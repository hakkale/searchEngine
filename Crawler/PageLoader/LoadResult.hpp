#ifndef LoadResult_hpp
#define LoadResult_hpp

#include <string>
#include <memory>
#include <curl/curl.h>
class LoadResult
{
private:
    //the entire html document
    std::string body;
    //the effective url
    std::string url;
    //the http response code
    long status;
    CURLcode error;

public:
    LoadResult(const std::string& body, const std::string& url, long status, CURLcode error);

    const std::string &getBody() const;

    const std::string &getUrl() const;

    long getStatus() const;

    CURLcode isError() const;
};

#endif