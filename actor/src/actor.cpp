//
// Created by darkwayc0de on 13/9/20.
//
#include "actor.h"
ActorManager::ActorManager(): root_actor_(new Actor(nullptr)){}

void ActorManager::kill(Actor* actor) {

}

ActorManager::~ActorManager() {
    root_actor_ -> deletelater();
}
Actor::~Actor() {
    deletelater();
}
void Actor::deletelater() {}

Actor::Actor(Actor* parent):
        thread_(&Actor::processMessage, this),
        parent_(parent){

}
void Actor::processMessage() {}

ActorManager* ActorManager::instance() {
    if(!instance_)
        instance_ = new ActorManager();

    return instance_;
}