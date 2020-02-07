#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <string.h>
#include <chrono>

#include "Board.h"
#include "Queens.h"

using namespace std;
using namespace std::chrono;

Board solve(Board init)
{
    Board final = init;
    stack<Board> BoardState;
    BoardState.push(init);

    while (!BoardState.empty())
    {
        Board stacktop = BoardState.top();
        BoardState.pop();

        if (stacktop.isComplete() && stacktop.isValid())
        {
            final = stacktop;
            continue;
        }
        int row = 0;
        while (stacktop.hasQueen(row + 1))
        {
            // cout << "Row: " << row + 1 << endl;
            row++;
        }
        for (int i = 0; i < stacktop.size; i++)
        {
            if (stacktop.isValid(row + 1, i + 1))
            {
                // cout << "pushRow: " << row + 1 << endl;
                // cout << "pushCol: " << i + 1 << endl;
                Board temp = stacktop;
                temp.placeQueen(row + 1, i + 1);
                BoardState.push(temp);
            }
        }
    }
    return final;
}

bool comparator(Queens &lhs, Queens &rhs) { return lhs.getRow() < rhs.getRow(); }

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        cout << "Usage: ./nqueens <INPUT FILE> <OUTPUTFILE>";
        exit(EXIT_FAILURE);
    }

    ifstream in;
    ofstream out;
    ofstream log;
    in.open(argv[1], ios::in);
    out.open(argv[2]);
    log.open("OutputLog.txt");

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
        log << "***********************************************************" << endl;
        log << "Board Size: " << nums[0] << endl;
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

        log << "Initial Board: ";
        init.print();
        auto start = high_resolution_clock::now();
        Board temp = solve(init);
        auto stop = high_resolution_clock::now();

        auto durations = duration_cast<seconds>(stop - start);
        auto durationms = duration_cast<milliseconds>(stop - start);
        auto durationus = duration_cast<microseconds>(stop - start);

        log << "Time to solve: " << durations.count() << " seconds or "
            << durationms.count() << " milliseconds or " << durationus.count() << " microseconds" << endl;

        if (temp.numQueens == init.numQueens)
        {
            log << "No solution" << endl;
            out << "No solution" << endl;
        }
        else
        {
            log << "Final Board: ";

            auto startsort = high_resolution_clock::now();
            sort(temp.board.begin(), temp.board.end(), &comparator);
            auto stopsort = high_resolution_clock::now();

            auto durationssort = duration_cast<seconds>(stopsort - startsort);
            auto durationmssort = duration_cast<milliseconds>(stopsort - startsort);
            auto durationussort = duration_cast<microseconds>(stopsort - startsort);

            log << "Time to sort: " << durationssort.count() << " seconds or "
                << durationmssort.count() << " milliseconds or " << durationussort.count() << " microseconds" << endl;

            log << temp.print();
            auto startstring = high_resolution_clock::now();
            out << temp.print_toFile();
            auto stopstring = high_resolution_clock::now();

            auto durationsstring = duration_cast<seconds>(stopstring - startstring);
            auto durationmsstring = duration_cast<milliseconds>(stopstring - startstring);
            auto durationusstring = duration_cast<microseconds>(stopstring - startstring);

            log << "Time to convert to string: " << durationsstring.count() << " seconds or "
                << durationmsstring.count() << " milliseconds or " << durationusstring.count() << " microseconds" << endl;
        }
        log << "***********************************************************" << endl;
    }
    in.close();
    out.close();
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