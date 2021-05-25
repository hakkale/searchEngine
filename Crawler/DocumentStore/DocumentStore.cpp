#include "DocumentStore.hpp"

std::vector<Document> DocumentStore::getAll() const {
    std::vector<Document> result;

    for(const auto& elem : this->all) {
        result.push_back(elem.second);
    }
    return result;
}

void DocumentStore::save(const Document& document) {
    this->all[document.getUrl()] = document;
}

std::size_t DocumentStore::count() const {
    return this->all.size();
}