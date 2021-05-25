#ifndef PageLoader_hpp
#define PageLoader_hpp

#include "LoadResult.hpp"

class PageLoader
{
private:
    /**
     * Callback function for writing received data.
     */
    //static e qani vor ete chliner skzbum kavelacner evs mek argument this-y,isk da kxarner stacky
    static std::size_t getData(char *data, size_t size, size_t nmemb, void *userp);

public:
    /**
     * The content of HTML document.
     */
    LoadResult load(const std::string &url);
};

#endif