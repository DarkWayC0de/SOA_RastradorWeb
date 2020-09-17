//
// Created by darkwayc0de on 16/9/20.
//

#include <list>
#include <algorithm>
#include "CrawlServer.h"

CrawServer::CrawServer(Actor *parent) : Actor(parent) {
    std::function<void(const std::string&, int)> fn2 = [this](const std::string& url, int depth) {
        this->crawlRequest(url,depth);
    };
    this->Actor::create_handler("crawlRequest", fn2);
    std::function<void(const std::string& , std::vector<std::string>&)> fn1 = [this](const std::string& url, std::vector<std::string>& listaUrl) {
        this->result(url,listaUrl);
    };
    this->Actor::create_handler("result", fn1);
}

void CrawServer::crawlRequest(const std::string& url, int depth) {
    auto i = urlclient_.begin();
     for( ; i != urlclient_.end(); i++){
         if(i->first == url){
             break;
         }
     }
     if(i != urlclient_.end()){
         i ->second.push_back(getLastSender());
     }else{
         auto linch =  ActorManager::spawn<LinkChecker>(this);
         Linchekers_.push_back(linch);
         std::pair<std::string,std::vector<Actor*>> pair;
         pair.first = url;
         pair.second.push_back(getLastSender());
         urlclient_.push_back(pair);
         ActorManager::send(linch,"checkUrl",url,depth);
     }

    //TODO Comprobar si la url ya esta siendo atendida. Si es así, apuntar al cliente para la respuesta.
    // En caso contrario crear linkcheker  y pedirle que procese la url.
}

void CrawServer::result(const std::string& url, std::vector<std::string>& listaUrl) {
    auto i = urlclient_.begin();
    for( ; i != urlclient_.end(); i++){
        if(i->first == url){
            break;
        }
    }
    auto pair = i.base();
    auto elem = 0;
    for( ; elem < pair->second.size(); elem++){
        send(pair->second[elem],"result",url,listaUrl);
    }
    urlclient_.erase(i);
    //TODO Responder a cada cliente pendiente de peticion con la lista de enlaces
    //Message CrawlRespons(url,links)

}

void CrawServer::deletelater() {
    for (int i = 0; i <Linchekers_.size() ; ++i) {
        ActorManager::kill(Linchekers_[i]);
    }
}
