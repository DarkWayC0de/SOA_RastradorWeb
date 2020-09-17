//
// Created by darkwayc0de on 29/5/20.
//
#include <iostream>
#include "CurlFetcher.h"
#include "Document.h"
#include "Node.h"

int main(int argc, char* argv[]){
    std::string page("<h1><a>some link</a></h1>");
    CDocument doc;
    doc.parse(page.c_str());

    CSelection c = doc.find("h1 a");
    std::cout << c.nodeAt(0).text() << std::endl; // some link
    return 0;
}
