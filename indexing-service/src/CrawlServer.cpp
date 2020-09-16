//
// Created by darkwayc0de on 16/9/20.
//

#include <list>
#include "CrawlServer.h"

CrawServer::CrawServer(Actor *parent) : Actor(parent) {

}

void CrawServer::crawlRequest(const std::string url, int depth) {

    //TODO Comprobar si la url ya esta siendo atendida. Si es así, apuntar al cliente para la respuesta.
    // En caso contrario crear linkcheker  y pedirle que procese la url.
}

void CrawServer::result(const std::string& url, std::list<std::string>& listaUrl) {
    //TODO Responder a cada cliente pendiente de peticion con la lista de enlaces
    //Message CrawlRespons(url,links)

}
