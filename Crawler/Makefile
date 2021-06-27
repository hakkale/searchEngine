CXX = g++
CXXFLAGS = -std=c++17 

CURL_LINKER_FLAG				= -lcurl

GUMBO_COMPILER_FLAG 			= -I /home/linuxbrew/.linuxbrew/Cellar/gumbo-parser/include 
GUMBO_LINKER_FLAGS 				= -L /home/linuxbrew/.linuxbrew/Cellar/gumbo-parser/0.10.1/lib -lgumbo

ALL_LINKER_FLAGS = ${CURL_LINKER_FLAG} ${GUMBO_LINKER_FLAGS} 

all: CrawlerTest

CrawlerTest: main.o PageLoader.o LoadResult.o Parser.o Website.o WebsiteRepository.o Link.o LinkStore.o Document.o DocumentStore.o
	$(CXX) $(CXXFLAGS)   main.o PageLoader.o LoadResult.o Parser.o Website.o WebsiteRepository.o Link.o LinkStore.o Document.o DocumentStore.o ${ALL_LINKER_FLAGS} -o CrawlerTest 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

PageLoader.o: ./PageLoader/PageLoader.cpp 
	$(CXX) $(CXXFLAGS) -c ./PageLoader/PageLoader.cpp -o PageLoader.o

LoadResult.o: ./PageLoader/LoadResult.cpp
	$(CXX) $(CXXFLAGS) -c ./PageLoader/LoadResult.cpp -o LoadResult.o

Parser.o: ./Parser/Parser.cpp
	$(CXX) $(CXXFLAGS) ${GUMBO_COMPILER_FLAG} -c ./Parser/Parser.cpp -o Parser.o

Website.o: ./WebsiteRepository/Website.cpp
	$(CXX) $(CXXFLAGS) -c ./WebsiteRepository/Website.cpp -o Website.o

WebsiteRepository.o: ./WebsiteRepository/WebsiteRepository.cpp
	$(CXX) $(CXXFLAGS) -c ./WebsiteRepository/WebsiteRepository.cpp -o WebsiteRepository.o

Link.o: ./LinkStore/Link.cpp ./LinkStore/LinkStatus.hpp 
	$(CXX) $(CXXFLAGS) -c ./LinkStore/Link.cpp -o Link.o

LinkStore.o: ./LinkStore/LinkStore.cpp
	$(CXX) $(CXXFLAGS) -c ./LinkStore/LinkStore.cpp -o LinkStore.o

Document.o: ./DocumentStore/Document.cpp
	$(CXX) $(CXXFLAGS) -c ./DocumentStore/Document.cpp -o Document.o

DocumentStore.o: ./DocumentStore/DocumentStore.cpp
	$(CXX) $(CXXFLAGS) -c ./DocumentStore/DocumentStore.cpp -o DocumentStore.o

clean:
	rm *.o CrawlerTest
