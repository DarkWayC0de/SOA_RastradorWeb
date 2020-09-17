//
// Created by darkwayc0de on 29/5/20.
//
#include <iostream>
#include <actor.h>
#include <LinkChecker.h>
#include "CurlFetcher.h"
#include "Document.h"
#include "Node.h"
#include "HttpGetter.h"
#include "CrawlServer.h"

int main(int argc, char* argv[]){
   // auto Crawserve = ActorManager::instance()->spawn<CrawServer>();
   // std::vector<std::string> l1;
   // ActorManager::send(Crawserve,"result", "http://www.ull.es/",l1); FALLA
   //ActorManager::send(Crawserve,"crawlRequest", "http://www.ull.es/",2); //FALA
   // auto linkchec = ActorManager::instance()->spawn<LinkChecker>();
   // ActorManager::send(linkchec,"done"); //PARECE Q SI VA
   // ActorManager::send(linkchec,"checkUrl", "http://www.ull.es/",2); //FALA
   // ActorManager::send(linkchec,"request","http://www.ull.es/",2); //FALLA

    auto getter = ActorManager::instance()->spawn<HttpGetter>();
   // ActorManager::send(getter,"request","http://www.ull.es/",2); //FALLA
    //getter->request("http://www.ull.es/",2);
    while(true){

    }
    return 0;
}
