//
// Created by darkwayc0de on 16/9/20.
//

#include <list>
#include <algorithm>
#include "CrawlServer.h"

CrawServer::CrawServer(Actor *parent) : Actor(parent) {

}

void CrawServer::crawlRequest(const std::string url, int depth) {
    auto i = urlclient_.begin();
     for( ; i != urlclient_.end(); i++){
         if(i->first == url){
             break;
         }
     }
     if(i != urlclient_.end()){
         i ->second.push_back(getLastSender());
     }else{
         auto linch =  ActorManager::spawn<LinkChecker>(this);
         Linchekers_.push_back(linch);
         std::pair<std::string,std::vector<Actor*>> pair;
         pair.first = url;
         pair.second.push_back(getLastSender());
         urlclient_.push_back(pair);
         ActorManager::send(linch,"checkUrl",url,depth);
     }

    //TODO Comprobar si la url ya esta siendo atendida. Si es así, apuntar al cliente para la respuesta.
    // En caso contrario crear linkcheker  y pedirle que procese la url.
}

void CrawServer::result(const std::string& url, std::list<std::string>& listaUrl) {
    auto i = urlclient_.begin();
    for( ; i != urlclient_.end(); i++){
        if(i->first == url){
            break;
        }
    }
    auto pair = i.base();
    auto elem = pair->second.begin();
    for( ; elem != pair->second.end(); elem++){
       // send(elem.base(),"result",url,listaUrl);
    }
   // urlclient_.re
    //TODO Responder a cada cliente pendiente de peticion con la lista de enlaces
    //Message CrawlRespons(url,links)

}
