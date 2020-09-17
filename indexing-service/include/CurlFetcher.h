//
// Created by darkwayc0de on 16/9/20.
//

#ifndef INDEXING_SERVICE_CURLFETCHER_H
#define INDEXING_SERVICE_CURLFETCHER_H
#include <string>

#include <curl/curl.h>
#include <atomic>
#include <vector>
#include <optional>

class CurlFetcher {
public:
    struct FetchInfo{
        std::vector<uint8_t> content;
        std::string contentType;
    };
    CurlFetcher();

    ~CurlFetcher();

     std::optional<FetchInfo> fetchURL(const std::string& url,long);

private:
    static std::atomic_int instanceCounter_;

    static size_t  curlWriteCallback(char *ptr, size_t size, size_t nmemb, void *userdata);

};


#endif //INDEXING_SERVICE_CURLFETCHER_H
