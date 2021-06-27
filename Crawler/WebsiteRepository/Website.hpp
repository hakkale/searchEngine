#ifndef Website_hpp
#define Website_hpp

#include <string>
#include <ctime>
class Website
{
private:
    int id;
    /*
     * The domain of the site
     */   
    std::string domain;  
    /*
     * The homepage url
     */
    std::string homepage;    
    /*
     * The last crawling time
     */
    time_t lastCrawlingTime; 
    
public:
    Website(){};
    Website(/*int id,*/const std::string &domain, const std::string &homepage, time_t lastCrawlingTime);
    Website(const Website&) = default;
    Website(Website&&) = default;
    Website& operator=(const Website&) = default;
    int getId() const;
    const std::string &getDomain() const;
    const std::string &getHomepage() const;
    time_t getLastCrawlingTime() const;

};

#endif