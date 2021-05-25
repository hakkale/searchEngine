#ifndef DOCUMENTSTORE_HPP
#define DOCUMENTSTORE__HPP

#include "Document.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class DocumentStore {
private:

    std::unordered_map<std::string, Document> all;

public:

    const std::vector<Document>& getAll() const;
    void save(const Document& doc);
    std::size_t count() const;
    
};

#endif