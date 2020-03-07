#include "graph.h"
#include <iostream>
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
    ifstream movieList;
    movieList.open("cleaned_movielist.txt");
    in.open(argv[1]);
    out.open(argv[2]);
    log.open("OutputLog.txt");

    if (!in.is_open())
    {
        printf("Unable to read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (!movieList.is_open())
    {
        printf("Unable to read file cleaned_movielist.txt");
        exit(EXIT_FAILURE);
    }

    Graph mygraph;
    string MLBuffer;
    auto starttotal = high_resolution_clock::now();
    while (getline(movieList, MLBuffer))
    {
        if (MLBuffer.length() == 0)
            continue;

        stringstream inputstream(MLBuffer);
        string val;
        vector<string> vals;
        while (inputstream >> val)
            vals.push_back(val);

        mygraph.insert(vals);
    }
    auto stoptotal = high_resolution_clock::now();
    auto durationstotal = duration_cast<seconds>(stoptotal - starttotal);
    auto durationmstotal = duration_cast<milliseconds>(stoptotal - starttotal);
    auto durationustotal = duration_cast<microseconds>(stoptotal - starttotal);
    log << "Total Time to Insert Data: " << durationstotal.count() << " seconds or "
        << durationmstotal.count() << " milliseconds or " << durationustotal.count() << " microseconds" << endl;
    log << "***********************************************************" << endl;

    string temp;
    starttotal = high_resolution_clock::now();

    while (getline(in, temp))
    {
        if (temp.length() == 0)
            continue;

        stringstream iss(temp);
        string arg;
        vector<string> args;
        while (iss >> arg)
            args.push_back(arg);
        if (args[0] == args[1])
            out << args[0];
        else if (!mygraph.exists(args[0], args[1]))
            out << "Not Present";
        else
        {
            list<string> path = mygraph.shortestPath(args[0], args[1]);
            int count = 0;
            if (path.size() != 1)
                for (string pathElem : path)
                {
                    if (count % 2)
                        out << " -(" << pathElem << ")- ";
                    else
                        out << pathElem;
                    count++;
                }
            else
                out << "Not Present";
        }
        out << endl;
    }

    stoptotal = high_resolution_clock::now();

    durationstotal = duration_cast<seconds>(stoptotal - starttotal);
    durationmstotal = duration_cast<milliseconds>(stoptotal - starttotal);
    durationustotal = duration_cast<microseconds>(stoptotal - starttotal);
    log << "Total Time to Finish Queries: " << durationstotal.count() << " seconds or "
        << durationmstotal.count() << " milliseconds or " << durationustotal.count() << " microseconds" << endl;
    log << "***********************************************************" << endl;
    in.close();
    out.close();
    log.close();
}

// mygraph.printMap();

// list<string> path = mygraph.shortestPath("Brad_Pitt", "Tom_Cruise");

// if (path.size() != 1)
//     for (string pathElem : path)
//         cout << pathElem << "||";
// else
//     cout << "Not Present";
// cout << endl;

// list<string> path2 = mygraph.shortestPath("Marilyn_Monroe", "Quentin_Tarantino");

// if (path2.size() != 1)
//     for (string pathElem : path2)
//         cout << pathElem << "||";
// else
//     cout << "Not Present";
// cout << endl;