#ifndef Link_hpp
#define Link_hpp

#include "LinkStatus.hpp"
#include <string>
#include <ctime>

class Link
{
private:
    std::string url;
    std::string domain;
    LinkStatus status;
    time_t lastLoadTime;

public:
    Link(const std::string &url, const std::string &domain, const LinkStatus &status, time_t time); 
    const std::string &getUrl() const;
    const std::string &getDomain() const;
    const LinkStatus &getStatus() const;
    time_t getLastLoadTime();
};
#endif