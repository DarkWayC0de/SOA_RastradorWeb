//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_HTTPGETTER_H
#define INDEXING_SERVICE_HTTPGETTER_H

#include <actor.h>

class HttpGetter : public Actor {
    explicit HttpGetter(Actor* parent);
};


#endif //INDEXING_SERVICE_HTTPGETTER_H
