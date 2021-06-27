#ifndef Parser_hpp
#define Parser_hpp

#include <iostream>
#include <string>
#include <vector>
#include <gumbo.h>
#include <optional>
#include <boost/regex.hpp>
class Parser {
private:
    /**
     * The effective url.
     */
    std::string url; 
    /**
     * The html document
     */
    std::string html;
    /**
     * All parsed urls
     */
    std::vector<std::string> urls;
    std::string title;
    std::string description;
    std::string allText;
private:
    /**
     * Extracts urls.
     */
    void extractUrls(GumboNode* node);
    /**
     * Extracts clean text.
     */
    std::string extractCleanText(GumboNode* node) const;
    /**
     * Extracts title.
     */
    void extractTitle(GumboNode* node);
    /**
     * Extracts description from "meta" tag
     */
    void extractDescription(GumboNode* node);

public:

    Parser(const std::string& url,const std::string& html);
    std::vector<std::pair<std::string, std::string> > checkByDomain(std::vector<std::string>& links, const std::string& domain);
    /**
     * Parse the HTML document.
     */
    void parse();
    const std::vector<std::string>& getUrls() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getAllText() const; //gtnel glxavor texty

};



#endif
