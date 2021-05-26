#ifndef PageLoader_hpp
#define PageLoader_hpp

#include "LoadResult.hpp"

class PageLoader
{
private:
    /**
     * Function for writing received data.
     */
    static std::size_t getData(char *data, size_t size, size_t nmemb, void *userp);

public:
    /**
     * The body of HTML document.
     */
    LoadResult load(const std::string &url);
};

#endif