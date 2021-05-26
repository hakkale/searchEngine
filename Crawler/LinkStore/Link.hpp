#ifndef Link_hpp
#define Link_hpp

#include "LinkStatus.hpp"
#include <string>
#include <ctime>

class Link
{
private:
    /*
     * The effective url
     */
    std::string url;
    /*
     * The website domain
     */
    std::string domain;
    /*
     * Current status
     */
    LinkStatus status;
    /*
     * The last loaded time
     */
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