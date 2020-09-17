#include "actor.h"

ActorManager* ActorManager::instance_ = nullptr;

ActorManager::ActorManager(): root_actor_(new Actor(nullptr)){}

void ActorManager::kill(Actor* actor) {
    actor->kill();
    actor->thread_.join();
}

bool ActorManager::threadlive(Actor* actor){
    return actor->thread_.joinable();
}

