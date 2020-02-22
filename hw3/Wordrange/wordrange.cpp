#include <iostream>
#include "AVL.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(int argc, char const **argv)
{
    if (argc < 3)
    {
        cout << "Usage: ./bard <INPUT FILE> <OUTPUTFILE>";
        exit(EXIT_FAILURE);
    }

    ifstream in;
    ofstream out;
    ofstream log;

    in.open(argv[1]);
    out.open(argv[2]);
    log.open("OutputLog.txt");

    if (!in.is_open())
    {
        printf("Unable to read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    AVL myAVL;

    string temp;
    auto starttotal = high_resolution_clock::now();

    while (getline(in, temp))
    {
        if (temp.length() == 0)
            continue;

        stringstream iss(temp);
        string arg;
        vector<string> args;
        while (iss >> arg)
            args.push_back(arg);

        // cout << args[0] << " => ";
        switch (int(args[0].c_str()[0]))
        {
        case int('i'):
            // cout << "Inserting " << args[1] << endl;
            myAVL.insert(args[1]);
            break;

        case int('r'):
            //             cout << args[0] << " => ";
            //             cout << "Finding Range between " << args[1] << " and " << args[2] << endl;
            //             cout << "Range: " << myAVL.range(args[1], args[2]) << endl;
            out << myAVL.range(args[1], args[2]) << endl;
            break;

        default:
            break;
        }
    }

    auto stoptotal = high_resolution_clock::now();

    auto durationstotal = duration_cast<seconds>(stoptotal - starttotal);
    auto durationmstotal = duration_cast<milliseconds>(stoptotal - starttotal);
    auto durationustotal = duration_cast<microseconds>(stoptotal - starttotal);
    log << "Total Time to execute: " << durationstotal.count() << " seconds or "
        << durationmstotal.count() << " milliseconds or " << durationustotal.count() << " microseconds" << endl;
    log << "***********************************************************" << endl;
    in.close();
    out.close();
    log.close();
}
