//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_CRAWSERVER_H
#define INDEXING_SERVICE_CRAWSERVER_H

#include <actor.h>
#include <LinkChecker.h>


class CrawServer : public Actor {
public:
    explicit CrawServer(Actor *parent);

private:
    void crawlRequest(const std::string& url, int depth);
    void result(const std::string& url, std::vector<std::string>& listaUrl);
    std::vector<std::pair<std::string,std::vector<Actor*>>> urlclient_;
    std::vector<LinkChecker*> Linchekers_;
};


#endif //INDEXING_SERVICE_CRAWSERVER_H
