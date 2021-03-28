#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <gumbo.h>

class Parser {
private:

    std::string url;
    std::string html;
    std::vector<std::string> urls;
    std::string title;
    std::string description;
    std::string text;
private:

    void extractUrls(GumboNode* node);

public:

    Parser(const std::string& url,const std::string& html);
    void parse();
    const std::vector<std::string>& getUrls() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getText() const;

};



#endif