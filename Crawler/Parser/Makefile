CXX = g++ 
CXXFLAGS = -std=c++11 -Wall

LDLIBS = -I/usr/local/Cellar/gumbo-parser/0.10.1/include -L/usr/local/Cellar/gumbo-parser/0.10.1/lib -lgumbo

all: testLoader

testLoader: test.o PageLoader.o LoadResult.o Parser.o
	$(CXX) $(CXXFLAGS) $(LDLIBS) test.o PageLoader.o LoadResult.o Parser.o -lcurl -o testLoader

test.o: test.cpp 
	$(CXX) $(CXXFLAGS) test.cpp -o test.o

PageLoader.o: ./PageLoader/PageLoader.cpp ./PageLoader/LoadResult.hpp
	$(CXX) $(CXXFLAGS) ./PageLoader/PageLoader.cpp -o PageLoader.o

LoadResult.o: ./PageLoader/LoadResult.cpp
	$(CXX) $(CXXFLAGS) ./PageLoader/LoadResult.cpp -o LoadResult.o

Parser.o: ./Parser/Parser.cpp
	$(CXX) $(CXXFLAGS) ./Parser/Parser.cpp -o Parser.o

clean:
	rm *.o testLoader