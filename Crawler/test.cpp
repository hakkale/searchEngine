#include "Parser/Parser.hpp"
#include "PageLoader/PageLoader.hpp"

#include <stdlib.h>
#include <gumbo.h>
#include <iostream>
#include <string>

int main()
{
    std::string url ="https://www.seasidestartupsummit.com/";
    PageLoader loader;
    LoadResult result = loader.load(url);


    Parser parser(result.getUrl(), result.getBody());
    parser.parse();

    for (const std::string& url : parser.getUrls()){
        std::cout << url << std::endl;
    }
    std::cout << parser.getAllText() << std::endl<< std::endl<< std::endl<< std::endl;
    std::cout << parser.getTitle() << std::endl<< std::endl<< std::endl<< std::endl;
    std::cout << parser.getDescription() << std::endl;

        
    
}

/*
CURL_LINKER_FLAG				= -lcurl
GUMBO_COMPILER_FLAG 			=  -I /home/linuxbrew/.linuxbrew/Cellar/gumbo-parser/include
GUMBO_LINKER_FLAGS 				=  -L /home/linuxbrew/.linuxbrew/Cellar/gumbo-parser/0.10.1/lib -lgumbo
*/