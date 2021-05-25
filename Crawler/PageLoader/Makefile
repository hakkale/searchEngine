CXX = g++
CXXFLAGS = -c

all: testLoader

testLoader: test.o PageLoader.o LoadResult.o 
	$(CXX) test.o PageLoader.o LoadResult.o -lcurl -o testLoader

test.o: test.cpp PageLoader.hpp
	$(CXX) $(CXXFLAGS) test.cpp -o test.o

PageLoader.o: PageLoader.cpp LoadResult.hpp
	$(CXX) $(CXXFLAGS) PageLoader.cpp -o PageLoader.o

LoadResult.o: LoadResult.cpp
	$(CXX) $(CXXFLAGS) LoadResult.cpp -o LoadResult.o

clean:
	rm *.o testLoader