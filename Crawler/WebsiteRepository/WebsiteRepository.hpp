#ifndef WebsiteRepository_hpp
#define WebsiteRepository_hpp

#include "Website.hpp"
#include <vector>
#include <unordered_map>
#include <string>

class WebsiteRepository
{
private:

    std::unordered_map<std::string, Website> websites;

public:

    WebsiteRepository(){};
    WebsiteRepository(const std::vector<Website>& websites);
    /*
     * Return all websites
     */
    std::vector<Website> getAll() const; 
    /*
     * Add website to repository
     */
    void add(const Website &website);
    /*
     * Update info for website
     */
    void update(const Website &website); 

};

#endif