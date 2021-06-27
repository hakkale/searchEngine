#ifndef DOCUMENTSTORE_HPP
#define DOCUMENTSTORE_HPP

#include "Document.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class DocumentStore {
private:

    std::unordered_map<std::string, Document> all;

public:

    std::vector<Document> getAll() const;
    void save(const Document& document);
    std::size_t count() const;
    
};

#endif