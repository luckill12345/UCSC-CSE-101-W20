#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Board.h"
#include "Queens.h"

using namespace std;

Board::Board()
{
    board = NULL;
    size = 0;
    numQueens = 0;
}

Board::Board(int newsize)
{
    board = new Queens[newsize];
    size = newsize;
    numQueens = 0;
}

bool Board::isValid()
{
    for (int i = 0; i < size - 1; i++)
    {
        // cout << "init " << i << " :" << board[i].getRow() << " " << board[i].getCol() << endl;
        for (int j = i + 1; j < size; j++)
        {
            if (hasQueen(j) && hasQueen(i))
                // cout << "compared to " << j << " :" << board[j].getRow() << " " << board[j].getCol() << endl;
                if ((abs(board[i].getRow() - board[j].getRow()) == abs(board[i].getCol() - board[j].getCol()) || board[i].getCol() == board[j].getCol() || board[i].getRow() == board[j].getRow()))
                    // if (!hasQueen(i) || !hasQueen(j))
                    return false;
        }
    }
    return true;
}

bool Board::isValid(int row, int col)
{
    for (int i = 0; i < size; i++)
    {
        // cout << "init " << i << " :" << board[i].getRow() << " " << board[i].getCol() << endl;
        if (hasQueen(i))
            // cout << "compared to " << j << " :" << board[j].getRow() << " " << board[j].getCol() << endl;
            if ((abs(board[i].getRow() - row) == abs(board[i].getCol() - col) || board[i].getCol() == col || board[i].getRow() == row))
                // if (!hasQueen(i) || !hasQueen(j))
                return false;
    }
    return true;
}

bool Board::isComplete()
{
    for (int i = 0; i < size; i++)
    {
        // cout << "hasQueen: row " << board[i].getRow() << " col " << board[i].getCol() << endl;

        if (!hasQueen(i))
            return false;
    }
    return true;
}

bool Board::hasQueen(int row)
{
    // cout << "hasQueen: row " << board[row].getRow() << " col " << board[row].getCol() << endl;
    if (board[row].getRow() == -1 || board[row].getCol() == -1)
        return false;
    else
        return true;
}

void Board::placeQueen(int row, int col)
{
    // cout << "placeQueen: row " << board[row - 1].getRow() << " col " << board[row - 1].getCol() << endl;

    if (!hasQueen(row - 1))
    {
        board[row - 1] = Queens(row, col);
        numQueens++;
        // cout << "Queen Placed: row " << board[row - 1].getRow() << " col " << board[row - 1].getCol() << endl;
    }
    // else
    //     cout << "Cannot place queen at " << row << ", " << col << endl;
}

void Board::placeQueen(int row, int col, bool given)
{
    if (!hasQueen(row - 1))
    {
        board[row - 1] = Queens(row, col, given);
        numQueens++;
    }
    else
        cout << "Cannot place queen at " << row << ", " << col << endl;
}

void Board::removeQueen(int row)
{
    if (board[row - 1].editable())
    {
        board[row - 1] = Queens();
        numQueens--;
    }
}

void Board::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << "(" << board[i].getRow() << "," << board[i].getCol() << ") ";
    }
    cout << endl;
}

bool Board::compare(Board compareto)
{
    bool same = false;
    for (int i = 0; i < size; i++)
    {
        if (board[i].getRow() == compareto.board[i].getRow() && board[i].getCol() == compareto.board[i].getCol())
            same = true;
        else
            same = false;
    }
    return same;
}