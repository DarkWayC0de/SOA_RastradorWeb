//
// Created by darkwayc0de on 29/5/20.
//
#include <iostream>
#include "CurlFetcher.h"

int main(int argc, char* argv[]){
    CurlFetcher fetcher;
    auto  info = fetcher.fetchURL("https://i.pinimg.com/originals/60/c2/17/60c2177448cbf90408ed1df7da78cf00.jpg",10240L);
    std::cout <<info->content.size()<<"\n";
    return 0;
}
