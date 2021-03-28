#include "PageLoader/PageLoader.hpp"
#include "Parser/Parser.hpp"
#include "gumbo.h"

#include <iostream>
#include <string>

int main()
{
    std::string url="http://rau.am";
    PageLoader loader;
    LoadResult res = loader.load(url);

    Parser parser(url,res.getBody());
    parser.parse();

    for (const std::string& u : parser.getUrls()){
        std::cout<< u << std::endl;
    }
}