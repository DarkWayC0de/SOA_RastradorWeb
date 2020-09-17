//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_LINKCHECKER_H
#define INDEXING_SERVICE_LINKCHECKER_H
#include <actor.h>
#include "HttpGetter.h"

class LinkChecker : public Actor {
public:
    explicit  LinkChecker(Actor* actor);
private:
    void request(const std::string& url, int depth );
    void checkUrl(const std::string& url, int depth);
    void done();
    std::vector<HttpGetter*> httpgeters_;
    unsigned long dones_;
    std::vector<std::string> urls_;
    void deletelater();
};


#endif //INDEXING_SERVICE_LINKCHECKER_H
