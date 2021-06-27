#include "WebsiteRepository.hpp"
#include "Website.hpp"


/*WebsiteRepository::WebsiteRepository(std::shared_ptr<mysqlx::Client> client) {
    this->client = client;
}
*/
WebsiteRepository::WebsiteRepository(const std::vector<Website>& websites) {
    for(const auto& website : websites){
        this->add(website);
    }   
}


std::vector<Website> WebsiteRepository::getAll() const
{
    std::vector<Website> all;
        for(const auto& website : websites){
        all.push_back(website.second);
    }
   /* auto session = this->client->getSession();
    
    {
        auto sessionRes = session
        .getDefaultSchema()
        .getTable("websites")
        .select("id", "domain", "homepage", "unix_timestamp(lastCrawlingTime)")
        .execute();
        
        mysqlx::Row row;
        while ((row = sessionRes.fetchOne())) {
            all.push_back(Website((int)row[0], (std::string)row[1], (std::string)row[2], (long long)row[3]));
        }
    }
    
    session.close();
    */
    
    return all;
}

void WebsiteRepository::add(const Website &website)
{
    this->websites.insert({website.getDomain(), website });
   /* auto session = this->client->getSession();
    
    {
        auto res = session.getDefaultSchema()
        .getTable("websites")
        .insert("domain", "homepage")
        .values(website.getDomain(), website.getHomepage())
        .execute();
    }
    
    session.close();*/
}

void WebsiteRepository::update(const Website &website)
{
    this->websites[website.getDomain()] = website;
   /* auto session = this->client->getSession();
    
    {
        auto res = session.getDefaultSchema()
        .getTable("websites")
        .update()
        .set("domain", website.getDomain())
        .set("homepage", website.getHomepage())
        .set("lastCrawlingTime", getDateLocalTime(website.getLastCrawlingTime()))
        .where("id = :id")
        .bind("id", website.getId())
        .execute();
    }
    
    session.close();
    */
}