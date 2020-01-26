CXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = LinkedList.o VocabList.o Bard.o

Bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o bard LinkedList.o VocabList.o Bard.o

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) -g $(CXXFLAGS) -c LinkedList.cpp
	
VocabList.o: LinkedList.cpp LinkedList.h VocabList.cpp VocabList.h
	$(CXX) -g $(CXXFLAGS) -c VocabList.cpp

Bard.o: LinkedList.cpp LinkedList.h VocabList.cpp VocabList.h Bard.cpp
	$(CXX) -g $(CXXFLAGS) -c Bard.cpp

clean: 
	rm -f *.o
	rm bard
	
format:
	clang-format -i LinkedList.cpp VocabList.cpp Bard.cpp
