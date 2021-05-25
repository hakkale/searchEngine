#ifndef Parser_hpp
#define Parser_hpp

#include <string>
#include <vector>
#include <gumbo.h>
#include <optional>

class Parser {
private:
    /**
     * The effective url.
     */
    std::string url; 
    std::string html;
    std::vector<std::string> urls;
    std::string title;
    std::string description;
    std::string allText;
private:

    void extractUrls(GumboNode* node);
       /**
     * Extracts clean text.
     */
    std::string getHomeUrl(const std::string& url);

    std::string extractCleanText(GumboNode* node) const;
    
    /**
     * Extracts title tag content of the head tag.
     */
    void extractTitle(GumboNode* node);
    
    /**
     * Extract content of the content attribute of <meta name="description" content="Some content">
     */
    void extractDescription(GumboNode* node);


public:
    
    Parser(const std::string& url,const std::string& html);
    void parse();
    const std::vector<std::string>& getUrls() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getAllText() const; //gtnel glxavor texty

};



#endif
