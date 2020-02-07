#include "Queens.h"
#include <vector>
#include <fstream>

#ifndef BOARD
#define BOARD

using namespace std;

class Board
{

public:
    vector<Queens> board;
    int row;
    int numQueens;
    int size;
    Board(int);
    bool isValid();
    bool isValid(int, int);
    bool isComplete();
    bool hasQueen(int);
    void placeQueen(int, int);
    void placeQueen(int, int, bool);
    string print();
    string print_toFile();
};

#endif