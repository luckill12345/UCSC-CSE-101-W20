#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <array>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <string.h>
#include <chrono>

#include "Board.h"
#include "Queens.h"

using namespace std;
using namespace std::chrono;

bool exists(stack<Board> BoardState, Board curr)
{
    stack<Board> tempstack;
    bool exists = false;
    while (!BoardState.empty())
    {
        Board stacktop = BoardState.top();
        BoardState.pop();
        tempstack.push(stacktop);
        if (stacktop.compare(curr))
        {
            exists = true;
        }
    }
    while (!tempstack.empty())
    {
        Board stacktop = tempstack.top();
        tempstack.pop();
        BoardState.push(stacktop);
    }
    return exists;
}

Board solve(Board init)
{
    Board final = init;
    stack<Board> BoardState;
    BoardState.push(init);

    while (!BoardState.empty())
    {
        Board stacktop = BoardState.top();
        BoardState.pop();
        // cout << "popped" << endl;
        // stacktop.print();
        // cout << "----------------------------------" << endl;
        // cout << "stacksize popped " << BoardState.size() << endl;
        // if (BoardState.size() > 0)
        // {
        //     BoardState.top().print();
        //     cout << "----------------------------------" << endl;
        // }
        if (stacktop.isComplete())
        {
            // cout << "Complete? " << stacktop.isComplete() << endl;
            // cout << "stacksize" << BoardState.size() << endl;
            // stacktop.print();
            // cout << "----------------------------------" << endl;
            final = stacktop;
            continue;
        }
        for (int i = 0; i < stacktop.size; i++)
        {
            bool pushed = false, endrow = false;
            if (!stacktop.hasQueen(i))
            {
                for (int j = 0; j < stacktop.size; j++)
                {
                    // stacktop.placeQueen(i + 1, j + 1);
                    // // stacktop.print();
                    // // cout << "----------------------------------" << endl;
                    // Board temp = Board(stacktop.size);
                    // memcpy(temp.board, stacktop.board, sizeof(Queens) * stacktop.size);
                    // // cout << "----------------------------------" << endl;
                    // temp.size = stacktop.size;
                    // temp.numQueens = stacktop.numQueens;
                    // // cout << "----------------------------------" << endl;
                    // if (temp.isValid())
                    // {
                    //     BoardState.push(temp);
                    //     // BoardState.top().print();
                    //     // cout << "----------------------------------" << endl;
                    //     // cout << "stacksize" << BoardState.size() << endl;
                    //     pushed = true;
                    // }
                    // stacktop.removeQueen(i + 1);
                    // // cout << "removed" << endl;
                    // // stacktop.print();
                    // // cout << "----------------------------------" << endl;
                    // // cout << "temp" << endl;
                    // // temp.print();
                    // // cout << "----------------------------------" << endl;
                    // // cout << "column " << j << endl;

                    if (stacktop.isValid(i + 1, j + 1))
                    {
                        stacktop.placeQueen(i + 1, j + 1);
                        Board temp = Board(stacktop.size);
                        memcpy(temp.board, stacktop.board, sizeof(Queens) * stacktop.size);
                        temp.size = stacktop.size;
                        temp.numQueens = stacktop.numQueens;
                        BoardState.push(temp);
                        pushed = true;
                        stacktop.removeQueen(i + 1);
                    }
                    if (j == stacktop.size)
                    {
                        // cout << "yeet" << endl;
                        endrow = true;
                        continue;
                        cout << pushed << " " << endrow << endl;
                    }
                }
                // cout << "size " << stacktop.size << endl;
                cout << "row used " << i << endl;
            }
            if (pushed && endrow)
            {
                // cout << "yeetus" << endl;
                continue;
            }
            // cout << "row " << i << endl;
        }
    }
    return final;
}

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        cout << "Usage: ./nqueens <INPUT FILE> <OUTPUTFILE>";
        exit(EXIT_FAILURE);
    }

    ifstream in;
    in.open(argv[1], ios::in);

    if (!in.is_open())
    {
        printf("Unable to read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    string temp;
    while (!in.eof())
    {
        getline(in, temp);
        if (temp.length() == 0)
            continue;

        stringstream iss(temp);
        int num;
        vector<int> nums;
        while (iss >> num)
        {
            // cout << "|" << num << "|" << endl;
            nums.push_back(num);
        }
        cout << nums[0] << endl;
        int x, y;
        bool pair = false;

        Board init = Board(nums[0]);

        for (int i = 1; i < (int)nums.size(); i++)
        {
            if (!pair)
            {
                x = nums[i];
                pair = true;
            }
            else
            {
                y = nums[i];
                // cout << "|" << x << "," << y << "|" << endl;
                init.placeQueen(x, y, true);
                pair = false;
            }
        }
        cout << "***********************************************************" << endl;
        cout << "Initial Board: ";
        init.print();
        auto start = high_resolution_clock::now();
        Board temp = solve(init);
        auto stop = high_resolution_clock::now();

        auto durations = duration_cast<seconds>(stop - start);
        auto durationms = duration_cast<milliseconds>(stop - start);

        cout << "Time to input and sort: " << durations.count() << " seconds or "
             << durationms.count() << " milliseconds" << endl;

        if (temp.numQueens == init.numQueens)
            cout << "No Solution" << endl;
        else
        {
            cout << "Final Board: ";
            temp.print();
        }
        cout << "***********************************************************" << endl;
    }

    // Board init = Board(8);
    // init.placeQueen(1, 1, true);
    // init.placeQueen(2, 5, true);
    // init.placeQueen(3, 8);
    // init.placeQueen(4, 6, true);
    // init.placeQueen(5, 3);
    // init.placeQueen(6, 7);
    // init.placeQueen(7, 2, true);
    // init.placeQueen(8, 4);
    // init.print();
    // init.removeQueen(8);
    // init.removeQueen(3);
    // init.removeQueen(5);
    // init.removeQueen(6);
    // init.print();
    // cout << "Complete? " << init.isComplete() << endl;
    // cout << "Valid?:" << init.isValid() << endl;

    // Board temp = solve(init);
    // if (temp.numQueens == init.numQueens)
    //     cout << "No Solution" << endl;
    // else
    //     temp.print();
    // cout << "***********************************************************" << endl;

    // Board init2 = Board(3);
    // init2.placeQueen(1, 1, true);
    // Board temp2 = solve(init2);
    // if (temp2.numQueens == init2.numQueens)
    //     cout << "No Solution" << endl;
    // else
    //     temp2.print();
    // cout << "***********************************************************" << endl;

    // Board init3 = Board(5);
    // init3.placeQueen(1, 1, true);
    // init3.placeQueen(2, 3, true);
    // Board temp3 = solve(init3);
    // if (temp3.numQueens == init3.numQueens)
    //     cout << "No Solution" << endl;
    // else
    //     temp3.print();
    // cout << "***********************************************************" << endl;

    // Board init4 = Board(5);
    // init4.placeQueen(1, 1, true);
    // init4.placeQueen(2, 4, true);
    // Board temp4 = solve(init4);
    // if (temp4.numQueens == init4.numQueens)
    //     cout << "No Solution" << endl;
    // else
    //     temp4.print();
    // cout << "***********************************************************" << endl;

    // Board init5 = Board(5);
    // init5.placeQueen(1, 1, true);
    // init5.placeQueen(2, 5, true);
    // Board temp5 = solve(init5);
    // if (temp5.numQueens == init5.numQueens)
    //     cout << "No Solution" << endl;
    // else
    //     temp5.print();
    // cout << "***********************************************************" << endl;

    // init2 = Board(5);
    // init2.placeQueen(1, 1, true);
    // temp2 = solve(init2);
    // if (temp2.numQueens == init2.numQueens)
    //     cout << "No Solution" << endl;
    // else
    //     temp2.print();
    // cout << "***********************************************************" << endl;
    return 0;
}

// Board solve(Board init)
// {
//     Board final = init;
//     stack<Board> BoardState;
//     BoardState.push(init);

//     while (!BoardState.empty())
//     {
//         Board stacktop = BoardState.top();
//         BoardState.pop();

//         if (stacktop.isComplete() && stacktop.isValid())
//         {
//             final = stacktop;
//             continue;
//         }
//         if (!stacktop.hasQueen(stacktop.row + 1))
//         {
//             for (int i = 0; i < stacktop.size; i++)
//             {
//                 if (stacktop.isValid(stacktop.row + 1, i + 1))
//                 {
//                     // cout << "pushRow: " << row + 1 << endl;
//                     // cout << "pushCol: " << i + 1 << endl;
//                     Board temp = stacktop;
//                     // cout << "stacktop init: ";
//                     // stacktop.print();
//                     // cout << "temp init: ";
//                     // temp.print();
//                     // cout << "------------------------------------------------------" << endl;
//                     temp.placeQueen(stacktop.row + 1, i + 1);

//                     // cout << "stacktop afterplace: ";
//                     // stacktop.print();
//                     // cout << "temp afterplace: ";
//                     // temp.print();
//                     // cout << "------------------------------------------------------" << endl;
//                     temp.row++;
//                     BoardState.push(temp);
//                 }
//             }
//         }
//         else
//         {
//             stacktop.row++;
//             BoardState.push(stacktop);
//         }
//     }

//     return final;
// }