#ifndef WebsiteRepository_hpp
#define WebsiteRepository_hpp

#include "Website.hpp"
#include <vector>
#include <unordered_map>
#include <string>
//#include <mysql-cppconn-8/mysqlx/xdevapi.h>
class WebsiteRepository
{
private:

    std::unordered_map<std::string, Website> websites;
    //mysqlx::Client client;    

public:
    WebsiteRepository(){};
    WebsiteRepository(const std::vector<Website>& websites);
    //WebsiteRepository(std::shared_ptr<mysqlx::Client> client);
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