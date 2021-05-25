#ifndef WebsiteRepository_hpp
#define WebsiteRepository_hpp
//websitery tnorinelu hamar
#include "Website.hpp"
#include <vector>
#include <unordered_map>
#include <string>

class WebsiteRepository
{
private:

    std::unordered_map<std::string, Website> websites;

public:

    WebsiteRepository();

    std::vector<Website> getAll() const; // return websites

    void add(const Website &website);

    void update(const Website &website); //update website[id] to website
};

#endif