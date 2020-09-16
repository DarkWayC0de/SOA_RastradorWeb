//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_CRAWSERVER_H
#define INDEXING_SERVICE_CRAWSERVER_H

#include <actor.h>


class CrawServer : public Actor {
public:
    explicit CrawServer(Actor *parent);

private:
    void crawlRequest(const std::string url, int depth);
    void result(const std::string& url, std::list<std::string>& listaUrl);

};


#endif //INDEXING_SERVICE_CRAWSERVER_H
