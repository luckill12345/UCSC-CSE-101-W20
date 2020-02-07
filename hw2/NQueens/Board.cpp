#include <iostream>
#include <vector>
#include <sstream>
#include "Board.h"
#include "Queens.h"
using namespace std;

Board::Board(int newsize)
{
    row = 0;
    size = newsize;
    numQueens = 0;
}

bool Board::isValid(int row, int col)
{
    for (int i = 0; i < (int)board.size(); i++)
    {
        if ((abs(board[i].getRow() - row) == abs(board[i].getCol() - col) || board[i].getCol() == col || board[i].getRow() == row))
            return false;
    }
    return true;
}

bool Board::isValid()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((abs(board[i].getRow() - board[j].getRow()) == abs(board[i].getCol() - board[j].getCol()) || board[i].getCol() == board[j].getCol() || board[i].getRow() == board[j].getRow()))
                return false;
        }
    }
    return true;
}

bool Board::hasQueen(int row)
{
    for (int i = 0; i < (int)board.size(); i++)
    {
        if (board[i].getRow() == row)
        {
            return true;
        }
    }
    return false;
}

bool Board::isComplete()
{
    return numQueens == size;
}

void Board::placeQueen(int row, int col)
{
    board.push_back(Queens(row, col));
    numQueens++;
}

void Board::placeQueen(int row, int col, bool given)
{
    board.push_back(Queens(row, col, given));
    numQueens++;
}

string Board::print()
{
    stringstream temp;
    for (int i = 0; i < (int)board.size(); i++)
        temp << "(" << board[i].getRow() << "," << board[i].getCol() << ") ";

    temp << endl;
    return temp.str();
}

string Board::print_toFile()
{
    stringstream temp;
    for (int i = 0; i < (int)board.size(); i++)
        temp << board[i].getRow() << " " << board[i].getCol() << ' ';

    temp << endl;
    return temp.str();
}