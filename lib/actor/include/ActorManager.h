//
// Created by darkwayc0de on 28/5/20.
//
#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H

#include "actor.h"


class ActorManager: public Actor {
public:
    ActorManager() = default;

    void spawn();
    void kill();

    ~ActorManager() = default;

};

#endif // ACTORMANAGER_H
