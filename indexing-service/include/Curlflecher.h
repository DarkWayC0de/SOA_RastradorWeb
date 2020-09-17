//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_CURLFLECHER_H
#define INDEXING_SERVICE_CURLFLECHER_H
#include <string>

#include <curl/curl.h>
#include <atomic>

class Curlflecher {
public:
    Curlflecher();

    ~Curlflecher();

    void fetchURL(const std::string& url );

private:
    static std::atomic_int instanceCounnter_;

    static size_t  curlWriteCallback(char *ptr, size_t size, size_t nmemb, void *userdata);

};


#endif //INDEXING_SERVICE_CURLFLECHER_H
