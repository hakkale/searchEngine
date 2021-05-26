#include <iostream>
#include "WebsiteRepository/WebsiteRepository.hpp"
#include "LinkStore/LinkStore.hpp"
#include "LinkStore/Link.hpp"
#include "PageLoader/PageLoader.hpp"
#include "PageLoader/LoadResult.hpp"
#include "Parser/Parser.hpp"
#include "DocumentStore/DocumentStore.hpp"

int main()
{

    WebsiteRepository websiteRepository;
    websiteRepository.add(Website("rau.am", "https://rau.am", 0));

    //Get all websites from repository
    const auto& websites = websiteRepository.getAll();

    LinkStore linkStore;
    PageLoader pageLoader;
    DocumentStore documentStore;

    for (const auto &website : websites)
    {
        //Get urls from link store
        auto homepageLink = linkStore.getByUrl(website.getHomepage());
        if (homepageLink.has_value())
        {
            //If url is already in link store, then update status
            linkStore.update(Link(website.getHomepage(),website.getDomain(),LinkStatus::WAITING,homepageLink.value().getLastLoadTime()));
        }
        else
        {
            //If url is not in link store, then add
            linkStore.add(Link(website.getHomepage(), website.getDomain(), LinkStatus::WAITING, 0));
        }
        //Start crawling algorithm
        while (true)
        {
            //Get 10 links from queue in status WAITING
            const auto& links = linkStore.getBy(website.getDomain(), LinkStatus::WAITING, 10); 
            if (links.empty())
            {
                break; 
            }
            //If there is links, which should be edited
            for (const auto& link : links)
            {
                // Load page 
                const auto& page = pageLoader.load(link.getUrl());
                // Error
                if (page.isError() || page.getStatus() < 200 || page.getStatus() >= 300)
                {
                    //Update status
                    linkStore.update(Link(link.getUrl(), link.getDomain(), LinkStatus::ERROR, time(NULL)));
                    continue;
                }
                //If there is no errors update link status 
                linkStore.update(Link(link.getUrl(), link.getDomain(), LinkStatus::LOADED, time(NULL)));

                //Parse page
                Parser parser(page.getUrl(), page.getBody());
                parser.parse();

                //Create document
                for (const std::string &url : parser.getUrls())
                {
                    std::cout << url << std::endl;
                }
                documentStore.save(Document(page.getUrl(), parser.getTitle(), parser.getDescription(), parser.getAllText()));

                //Check new links
                for (const auto &newUrl : parser.getUrls())
                {
                    if (linkStore.getByUrl(newUrl).has_value())
                    {
                        continue;
                    }
                    //Add new link to queue
                    linkStore.add(Link(link.getUrl(), link.getDomain(), LinkStatus:: WAITING, time(NULL)));
                }

                linkStore.update(Link(link.getUrl(), link.getDomain(), LinkStatus:: LOADED, time(NULL)));
            }
        }
        websiteRepository.update(Website(website.getDomain(), website.getHomepage(), time(NULL)));
    }
}

