//
// Created by darkwayc0de on 16/9/20.
//

#include "HttpGetter.h"

#include "CurlFetcher.h"

HttpGetter::HttpGetter(Actor *parent) : Actor(parent) {

}

void HttpGetter::request(const std::string &url, int depth){
    //TODO: Descargar la URL y buscar URLs.
  //  CurlFetcher fetcher;
//    fetcher.fetchURL(url);
}

