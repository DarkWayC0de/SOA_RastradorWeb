//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_LINKCHECKER_H
#define INDEXING_SERVICE_LINKCHECKER_H
#include <actor.h>

class LinkChecker : public Actor {
    explicit  LinkChecker(Actor* actor);
private:
    void request(const std::string& url, int depth );
    void checkUrl(const std::string& url, int depth);
    void done();
};


#endif //INDEXING_SERVICE_LINKCHECKER_H
