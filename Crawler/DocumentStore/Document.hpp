#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

class Document {
private:
    std::string url;
    std::string title;
    std::string description;
    std::string allText;
    
public:
    Document(){};
    Document(const std::string& url, const std::string& title, const std::string& description, const std::string& allText);
    Document(const Document&) = default;
    Document(Document&&) = default;
    const std::string& getUrl() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getAllText() const;
    Document& operator== (const Document&);
    Document& operator=(const Document&)= default;
};
#endif