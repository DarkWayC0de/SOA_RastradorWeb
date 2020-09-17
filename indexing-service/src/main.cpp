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

int main(int argc, char* argv[]){

  //  auto linkchec = ActorManager::instance()->spawn<LinkChecker>();
    //ActorManager::send(linkchec,"request","http://www.ull.es/",2);

    auto getter = ActorManager::instance()->spawn<HttpGetter>();
    ActorManager::send(getter,"request","http://www.ull.es/",2);
    while(true){

    }
    return 0;
}
