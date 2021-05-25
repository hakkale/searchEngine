#include "WebsiteRepository.hpp"
#include "Website.hpp"

WebsiteRepository::WebsiteRepository() {

    this->add(Website("rau.am", "http://rau.am", 0));

}

std::vector<Website> WebsiteRepository::getAll() const
{
    std::vector<Website> all;
    for(const auto& website : websites){
        all.push_back(website.second);
    }
    return all;
}

void WebsiteRepository::add(const Website &website)
{
    this->websites.insert({website.getDomain(), website });
}

void WebsiteRepository::update(const Website &website)
{

    this->websites[website.getDomain()] = website;
}