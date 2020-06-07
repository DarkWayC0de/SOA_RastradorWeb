//
// Created by darkwayc0de on 28/5/20.
//

#ifndef SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
#define SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H

#include "actors_global.h"


class EXPORTED Actor {
private:
public:
    virtual ~Actor();
    Actor();
    void send();
    void sender();
    void getReply();
    void getUnknown();
};


#endif //SOA_1920_RASTREADOR_WEB_DIEGO_OSCAR_ACTOR_H
