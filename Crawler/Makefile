CXX = g++
CXXFLAGS = -std=c++17 -Wall

LDLIBS = -lcurl -I /home/linuxbrew/.linuxbrew/Cellar/gumbo-parser/include -L /home/linuxbrew/.linuxbrew/Cellar/gumbo-parser/0.10.1/lib -lgumbo
all: CrawlerTest

CrawlerTest: test.o PageLoader.o LoadResult.o Parser.o Website.o WebsiteRepository.o Link.o LinkStore.o Document.o DocumentStore.o
	$(CXX) $(CXXFLAGS) test.o PageLoader.o LoadResult.o Parser.o Website.o WebsiteRepository.o Link.o LinkStore.o Document.o DocumentStore.o ${LDLIBS} -o CrawlerTest 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

PageLoader.o: ./PageLoader/PageLoader.cpp 
	$(CXX) $(CXXFLAGS) -c ./PageLoader/PageLoader.cpp -o PageLoader.o

LoadResult.o: ./PageLoader/LoadResult.cpp
	$(CXX) $(CXXFLAGS) -c ./PageLoader/LoadResult.cpp -o LoadResult.o

Parser.o: ./Parser/Parser.cpp
	$(CXX) $(CXXFLAGS) -c ./Parser/Parser.cpp -o Parser.o

Website.o: ./WebsiteRepository/Website.cpp
	$(CXX) $(CXXFLAGS) -c ./WebsiteRepository/Website.cpp -o Website.o

WebsiteRepository.o: ./WebsiteRepository/WebsiteRepository.cpp
	$(CXX) $(CXXFLAGS) -c ./WebsiteRepository/WebsiteRepository.cpp -o WebsiteRepository.o

Link.o: ./LinkStore/Link.cpp
	$(CXX) $(CXXFLAGS) -c ./LinkStore/Link.cpp -o Link.o

LinkStore.o: ./Link/LinkStore.cpp
	$(CXX) $(CXXFLAGS) -c ./Link/LinkStore.cpp -o LinkStore.o

Document.o: ./DocumentStore/Document.cpp
	$(CXX) $(CXXFLAGS) -c ./DocumentStore/Document.cpp -o Document.o

DocumentStore.o: ./DocumentStore/DocumentStore.cpp
	$(CXX) $(CXXFLAGS) -c ./DocumentStore/DocumentStore.cpp -o DocumentStore.o

clean:
	rm *.o CrawlerTest
