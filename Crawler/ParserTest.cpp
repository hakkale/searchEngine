#include <iostream>
#include "PageLoader/PageLoader.hpp"
#include "PageLoader/LoadResult.hpp"
#include "Parser/Parser.hpp"

int main(){
    std::string url ="https://rau.am";
    PageLoader page;
    LoadResult result = page.load(url);

    Parser parser(url,result.getBody());
    parser.parse();
    for (const auto& u : parser.getUrls()){
        std::cout<< u <<std::endl;
    }

}