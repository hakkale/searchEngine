#ifndef PAGE_LOADER_HPP
#define PAGE_LOADER_HPP

#include "LoadResult.hpp"

class PageLoader
{
private:

    static std::size_t getData(char *data, size_t size, size_t nmemb, void *userp);

public:

    LoadResult load(const std::string& url);
    
};

#endif 