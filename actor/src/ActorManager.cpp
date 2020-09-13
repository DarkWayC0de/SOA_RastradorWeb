//
// Created by darkwayc0de on 28/5/20.
//

#include <ActorManager.h>
#include <actor.h>

ActorManager* ActorManager::instance_ = nullptr;

ActorManager::ActorManager(): root_actor_(new Actor(nullptr)){

}


void ActorManager::kill(Actor* actor) {

}

ActorManager::~ActorManager() {
    root_actor_ -> deletelater();
}


template<typename... Types>
bool ActorManager::send(Actor *receiver, const std::string &message, Types &&... args) {
    return receiver -> deliver_from(nullptr, message, std::forward<Types>(args)...);
}

ActorManager* ActorManager::instance() {
    if(!instance_)
        instance_ = new ActorManager();

    return instance_;
}
