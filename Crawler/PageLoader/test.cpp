#include "PageLoader.hpp"

#include <iostream>
#include <gumbo.h>
#include <string>

int main()
{
    PageLoader loader;
    LoadResult res = loader.load("http://rau.am");
    std::cout << res.getStatus() << std::endl << std::endl;
    std::cout << res.getBody();
}