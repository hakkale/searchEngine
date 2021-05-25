#include <iostream>
#include "WebsiteRepository/WebsiteRepository.hpp"
#include "LinkStore/LinkStore.hpp"
#include "LinkStore/Link.hpp"
#include "PageLoader/PageLoader.hpp"
#include "PageLoader/LoadResult.hpp"
#include "Parser/Parser.hpp"
#include "DocumentStore/DocumentStore.hpp"

//1.algoritmy sksvum e nranic vor sksum enq vazel websiteRepositroy-i
//website-neri vrayov
//2.ays websiteric yuraqanchyury petq e mshakenq
//3.amen website-in petq pahenq herti mej
int main()
{

    WebsiteRepository websiteRepository;
    websiteRepository.add(Website("rau.am", "http://rau.am", 0));

    //vercnum enq bolor websitery
    const auto& websites = websiteRepository.getAll();

    LinkStore linkStore;
    PageLoader pageLoader;
    DocumentStore documentStore;

    for (const auto &website : websites)
    {
        //aysinqn ayn website vory nor enq mshakel el chani ancni araj
        auto homepageLink = linkStore.getByUrl(website.getHomepage());
        if (homepageLink.has_value())
        {
            linkStore.update(Link(website.getHomepage(),website.getDomain(),LinkStatus::WAITING,homepageLink.value().getLastLoadTime()));
        }
        else
        {
            linkStore.add(Link(website.getHomepage(), website.getDomain(), LinkStatus::WAITING, 0));
        }
        //bun crawlingi algorithmy
        while (true)
        {
            const auto& links = linkStore.getBy(website.getDomain(), LinkStatus::WAITING, 10); // getby greluc maximum 10 hat e veradardznum
            if (links.empty())
            {
                break; //ete linker chkan mek el orinak mi shabatic het kganq
            }
            //ete linker kan petq e mshakenq(herti linkery)
            for (const auto& link : links)
            {
                //petq e load anenq pagey
                const auto& page = pageLoader.load(link.getUrl());
                //ete error e
                if (page.isError() || page.getStatus() < 200 || page.getStatus() >= 300)
                {
                    linkStore.update(Link(link.getUrl(), link.getDomain(), LinkStatus::ERROR, time(NULL)));
                    continue;
                }
                //ete error chka
                linkStore.update(Link(link.getUrl(), link.getDomain(), LinkStatus::LOADED, time(NULL)));

                //ete loady stacvel e uremn petq e parse anenq vor haskananq inch e petq mejic
                //parse aneluc stanum enq nor urlner ...
                Parser parser(page.getUrl(), page.getBody());
                parser.parse();
                //stexcum enq document
                for (const std::string &url : parser.getUrls())
                {
                    std::cout << url << "\n";
                }
                documentStore.save(Document(page.getUrl(), parser.getTitle(), parser.getDescription(), parser.getAllText()));

                //hertov ditarkum enq nor urlnery, vor ete ka voch mi ban chanenq, ete chka avelacnenq
                for (const auto &newUrl : parser.getUrls())
                {
                    //ete ka zut ancni araj
                    if (linkStore.getByUrl(newUrl).has_value())
                    {
                        continue;
                    }
                    //ete chka avelacni
                    linkStore.add(Link(link.getUrl(), link.getDomain(), LinkStatus:: WAITING, time(NULL)));
                }

                linkStore.update(Link(link.getUrl(), link.getDomain(), LinkStatus:: LOADED, time(NULL)));
            }
        }
        websiteRepository.update(Website(website.getDomain(), website.getHomepage(), time(NULL)));
    }
}

