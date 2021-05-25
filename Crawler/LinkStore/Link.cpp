#include "Link.hpp"

Link::Link(const std::string &url, const std::string &domain, const LinkStatus status, time_t lastLoadTime)
{
    this->url = url;
    this->domain = domain;
    this->status = status;
    this->lastLoadTime = lastLoadTime;
}

const std::string &Link::getUrl() const
{
    return this->url;
}

const std::string &Link::getDomain() const
{
    return this->domain;
}

const LinkStatus &Link::getStatus() const
{
    return this->status;
}

time_t Link::getLastLoadTime() const
{
    return this->lastLoadTime ;
}