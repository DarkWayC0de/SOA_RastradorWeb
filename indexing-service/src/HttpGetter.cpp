//
// Created by darkwayc0de on 16/9/20.
//

#include "HttpGetter.h"

#include "CurlFetcher.h"

HttpGetter::HttpGetter(Actor *parent) : Actor(parent) {
    std::function<void(std::string,int)> fn = [this](std::string url, int depth) {
        this->request(url,depth);
    };
    this->Actor::create_handler("request", fn);
}

void HttpGetter::request(const std::string &url, int depth){
    //TODO: Descargar la URL y buscar URLs.
    CurlFetcher fetcher;
    auto info = fetcher.fetchURL(url,10240L);
    if(info || info.value().contentType.find("text/html",0) == std::string::npos){
        reply("done");
        kill();
        return;
    }
    auto content = std::string(reinterpret_cast<char*>(info.value().content.data()),info.value().content.size());
    /*CDocument doc;
    doc.parse(content);
    CSelector elements = doc.find("[href],[src]");
    for (int i = 0; i = elements.nodeNum(); ++i) {
      auto node =  elements.nodeAt(i);
      std::string hrefAttribute = node.attribute("href").empty();
      auto srcAttribute = node.attribute("src");
      if(! hrefAttribute.empty()){
          if (hrefAttribute.starts_with("http")) {
              reply("checkUrl", hrefAttribute, depth);
          }else{
              reply("checkUrl", url + hrefAttribute, depth);
          }
      }
      if(! srcAttribute.empty){
          if (hrefAttribute.starts_with("http")) {
              reply("checkUrl", srcAttribute, depth);
          }else{
              reply("checkUrl", url + srcAttribute, depth);
          }
      }
    } */
    reply("done");
    kill();
    return;
}

