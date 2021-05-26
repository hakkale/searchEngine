#ifndef LoadResult_hpp
#define LoadResult_hpp

#include <string>
#include <memory>
#include <curl/curl.h>
class LoadResult
{
private:
    /*
     * The entire html document
     */
    std::string body;
    /*
     * The effective url
     */
    std::string url;
    /*
     * The http response code
     */
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