#include "PageLoader.hpp"

#include <curl/curl.h>
#include <iostream>
#include <string>

//This getData function gets called by libcurl as soon as there is data received that needs to be saved.
size_t PageLoader::getData(char *data, size_t size, size_t nmemb, void *userp)
{ 
    size_t realsize = size * nmemb;
    std::string* str = (std::string*)userp;
    str->append(data, realsize);
    return realsize; 
}

LoadResult PageLoader::load(const std::string &url)
{
    // Initialize CURL
    CURL *curl = curl_easy_init();

    CURLcode result = CURLE_NO_CONNECTION_AVAILABLE;

    std::string content;
    long responseCode = 0;
    std::string effectiveUrl;

    if (curl)
    {
        //For getting "html code"
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        //Send all data to this function 
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getData); 
        //We pass our 'content' to the getData function 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
        //Libcurl will issue another request for the new URL and follow new Location: 
        //headers all the way until no more such headers are returned.
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

        //Connect to the url and download it's contents 
        result = curl_easy_perform(curl); 
        // Check for errors.
        if (result != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
        }
        else
        {
            //Pass a pointer to a long to receive the last received HTTP, FTP or SMTP response code.
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
            char *url = nullptr;
            //Pass in a pointer to a char pointer(&url) and get the last used effective URL. 
            curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

            if (url != nullptr)
            {
                effectiveUrl.append(url);
            }
        }
        curl_easy_cleanup(curl);
    }
    
    return LoadResult(content, effectiveUrl, responseCode, result);
}