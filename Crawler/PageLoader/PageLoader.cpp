#include "PageLoader.hpp"

#include <curl/curl.h>
#include <iostream>
#include <string>
#include <sstream>

size_t PageLoader::getData(char* data, size_t size, size_t nmemb, void* userp){ //setting callback

		//data contains data from url. size is always 1 (?)
		//nmemb is size of data. userp is for WRITEDATA(to write data in FILE??)
		size_t realsize = size * nmemb;
        std::string* str = (std::string*)userp;
        str->append(data, realsize);
		return realsize; //callback must return size*nmemb(?)

}

LoadResult PageLoader::load(const std::string& url)
{
    // initialize CURL
    CURL* curl = curl_easy_init();
    std::string content;

	curl_easy_setopt(curl,CURLOPT_URL,url.c_str()); //for getting "html code" (ssilka na document otkuda nujno skachat dannie)
    //curl_easy_setopt(curl, CURLOPT_HEADER, 1L); //for getting metadata
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,getData); //for callback (biblioteka curl doljna peredat te dannie kotorie skachaet)
    //dayot getData v kachestve argumenta to chto prochital 
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);// nam nado kuda-to zapisat, a ne tolko poluchit, chtobi v konce vernut 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); 

	CURLcode result = curl_easy_perform(curl);// performing transfer as described in options

    long status;
    //requesting information from session
	curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status);// same as CURLINFO_HTTP_CODE 



    curl_easy_cleanup(curl);
    return LoadResult(content, status);
}
