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
    Link(){};
    Link(const std::string &url, const std::string &domain, const LinkStatus status, time_t lastLoadTime); 
    Link(const Link&) = default;
    Link(Link&&) = default;
    const std::string &getUrl() const;
    const std::string &getDomain() const;
    const LinkStatus &getStatus() const;
    time_t getLastLoadTime() const;
    Link& operator== (const Link&);
    Link& operator=(const Link&);
};
#endif