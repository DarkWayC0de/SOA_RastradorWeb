//
// Created by darkwayc0de on 16/9/20.
//

#include "LinkChecker.h"
#include <algorithm>

LinkChecker::LinkChecker(Actor *actor) : Actor(actor), dones_(0) {
    std::function<void(const std::string&,int)> fn = [this](const std::string &url, int depth) {
        this->request(url,depth);
    };
    this->Actor::create_handler("request", fn);
    std::function<void(const std::string&,int)> fn1 = [this](const std::string &url, int depth) {
        this->checkUrl(url,depth);
    };
    this->Actor::create_handler("checkUrl", fn1);
    std::function<void()> fn2 = [this]() {
        this->done();
    };
    this->Actor::create_handler("done", fn2);
}

void LinkChecker::request(const std::string &url, int depth) {
    // TODO: Crear un HttpGetter y pedirle que procesese la url
    auto getter = ActorManager::spawn<HttpGetter>();
    httpgeters_.push_back(getter);
    urls_.push_back(url);
    ActorManager::send(getter,"request",url,depth);
}

void LinkChecker::checkUrl(const std::string &url, int depth) {
    auto it = std::find(urls_.begin(),urls_.end(),url);
    if(it == urls_.end()){
            urls_.push_back(url);
            if(--depth != 0){
                auto getter = ActorManager::instance()->spawn<HttpGetter>();
                httpgeters_.push_back(getter);
                ActorManager::send(getter,"request",url,depth);
            }

    }
    //TODO: Comprobar si la url ha sido procesada, afirmativo ingnoramos,
    // neg crear httpgeter que procese la url con depth -1
    // si depth == 0 guardar url pero no procesar
}

void LinkChecker::done() {
    if(++dones_ == httpgeters_.size()){
        reply("result",urls_[0],urls_);
    }
    //TODO Comprobar si es el ultimo httpgeter. Si es asi devolver lista urls al crawlserver
    // respuesta a result

}

