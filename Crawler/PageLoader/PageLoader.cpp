#include "PageLoader.hpp"

#include <curl/curl.h>
#include <iostream>
#include <string>

//https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
//This callback function gets called by libcurl as soon as there is data received that needs to be saved.
//For most transfers, this callback gets called many times and each invoke delivers another chunk of data. 
//ptr points to the delivered data, and the size of that data is nmemb; size is always 1. 
size_t PageLoader::getData(char *data, size_t size, size_t nmemb, void *userp)//ays functionov stacel enq danninery internetic u vorpeszi karoxananq inch vor tex ayn grel poxancum enq 4rd argumenty
{ 
    size_t realsize = size * nmemb;
    std::string* str = (std::string*)userp;
    str->append(data, realsize);
    return realsize; 
}

LoadResult PageLoader::load(const std::string &url)
{
    // initialize CURL
    CURL *curl = curl_easy_init();
    // The initial value is for internal use only, will never be returned by libcurl.
    CURLcode result = CURLE_NO_CONNECTION_AVAILABLE;
    std::string content;
    long responseCode = 0;
    std::string effectiveUrl;
    if (curl)
    {
        //For getting "html code"
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());//ssilka na document otkuda nujno skachat dannie
        //Send all data to this function 
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getData); //henc qashum e inch vor data kanchum e getData func. u getDatayin vorpes argument tur en inchy grel enq 35 toxum,contentum skzbum ban chka bayc klini vorovhetev de inch vor tex petq e grel datan
        //We pass our 'content' to the getData function 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);    //nam nado kuda-to zapisat, a ne tolko poluchit, chtobi v konce vernut
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
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
            char *url = nullptr;
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