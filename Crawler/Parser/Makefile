CXX = g++
CXXFLAGS = -Wall
LDLIBS = -I/usr/local/Cellar/gumbo-parser/0.10.1/include -L/usr/local/Cellar/gumbo-parser/0.10.1/lib -lgumbo

all: ParserTest

ParserTest: test.o ./PageLoader/PageLoader.o ./PageLoader/LoadResult.o ./Parser/Parser.o
	$(CXX) $(CXXFLAGS) $(LDLIBS) test.o PageLoader.o LoadResult.o Parser.o -lcurl -o ParserTest

test.o: test.cpp 
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

PageLoader.o: ./PageLoader/PageLoader.cpp 
	$(CXX) $(CXXFLAGS) -c ./PageLoader/PageLoader.cpp -o PageLoader.o

LoadResult.o: ./PageLoader/LoadResult.cpp
	$(CXX) $(CXXFLAGS) -c ./PageLoader/LoadResult.cpp -o LoadResult.o

Parser.o: ./Parser/Parser.cpp
	$(CXX) $(CXXFLAGS) -c ./Parser/Parser.cpp -o Parser.o
	
clean:
	rm *.o ParserTest