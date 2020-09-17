//
// Created by darkwayc0de on 16/9/20.
//

#include "Curlflecher.h"

std::atomic_int Curlflecher::instanceCounter_ = 0;

Curlflecher::Curlflecher(){
    if(instanceCounnter_.fetch_add(1,std::memory_order_acquire) == 0){
        curl_global_init(CURL_GLOBAL_ALL);
    }
}

Curlflecher::~Curlflecher() {
    if(instanceCounnter_.fetch_sub(1, std::memory_order_acquire) == 1){
        curl_global_cleanup();
    }

}

void Curlflecher::fetchURL(const std::string& url) {
    CURL* curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, curlWriteCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, this);

    if (curl_easy_perform(curl_handle) == CURLE_OK){
        char* contentType = nullptr;
        curl_easy_getinfo(curl_handle,CURLINFO_CONTENT_TYPE,&contentType);
        //TODO hacer algo con Contentipe
    }else{
        //TODO Manejar el error

    }


    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();

}

size_t Curlflecher::curlWriteCallback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    auto fetcher = reinterpret_cast<Curlflecher*>(userdata);
}
