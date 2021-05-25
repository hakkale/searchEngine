#ifndef Website_hpp
#define Website_hpp

#include <string>
#include <ctime>
//website linelu e mer inputy, u yndhanur ays moduly petq e websitery grel kardalu hamar,
// kardalu e ur? DB, DB-n karox e lini hasarak vector karox e lini henc DB disci vra, karch asac ays moduly tnorinum e bolor websitery
class Website
{
private:
    //The domain of the site   
    std::string domain;  
    //The homepage url
    std::string homepage;    
    //The last crawling time
    time_t lastCrawlingTime; 
    
public:
    Website(){};
    Website(const std::string &domain, const std::string &homepage, time_t lastCrawlingTime);
    Website(const Website&) = default;
    Website(Website&&) = default;
    Website& operator=(const Website&) = default;
    const std::string &getDomain() const;
    const std::string &getHomepage() const;
    time_t getLastCrawlingTime() const;

};

#endif