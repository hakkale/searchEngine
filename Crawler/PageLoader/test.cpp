#include "PageLoader.hpp"

#include <iostream>
#include <string>

int main()
{
    PageLoader loader;
    LoadResult result = loader.load("http://rau.am");
    std::cout << result.getStatus() << std::endl;
    std::cout << result.getBody() << std::endl;
    std::cout << result.getUrl() << std::endl;
    std::cout << result.isError()<< std::endl;
}