//
// Created by darkwayc0de on 28/5/20.
//
#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_MANAGER_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_MANAGER_H


#include "actor.h"
#include "actors_global.h"

class EXPORTED ActorManager :  public Actor  {
public:
    ActorManager();

    void spawn();
    void kill();

    virtual ~ActorManager();

};


#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_MANAGER_H
