#include "Queens.h"

#ifndef BOARD
#define BOARD

class Board
{

public:
    Queens *board;
    int numQueens;
    int size;
    Board();
    Board(int);
    bool isValid();
    bool isValid(int, int);
    bool isComplete();
    bool hasQueen(int);
    void placeQueen(int, int);
    void placeQueen(int, int, bool);
    void removeQueen(int);
    void print();
    bool compare(Board);
};

#endif