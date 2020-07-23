//
// Created by darkwayc0de on 9/6/20.
//

#ifndef ACTOR_ACTORTHEAD_H
#define ACTOR_ACTORTHEAD_H

#include <actors_global.h>
#include <actor.h>


class NOT_EXPORTED ActorThead {
private:
    Actor *actor_;

public:
    explicit ActorThead(Actor* actor);

    void run();

};


#endif //ACTOR_ACTORTHEAD_H
