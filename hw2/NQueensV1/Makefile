CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = Queens.o Board.o nqueens.o

nqueens: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean: 
	rm -f *.o nqueens
$(OBJECTS): Queens.h Board.h
