#include "VocabList.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    cout << "Starting..." << endl;
    VocabList *vlist = new VocabList();

    ifstream src("shakespeare-cleaned5.txt");
    string temp;

    auto start = high_resolution_clock::now();

    if (src.is_open())
    {
        while (!src.eof())
        {
            getline(src, temp);
            vlist->insert(temp);
        }
    }
    cout << "Words inserted..." << endl;

    cout << "Now sorting..." << endl;
    vlist->sort();
    cout << "Sorted" << endl;

    auto stop = high_resolution_clock::now();

    auto durations = duration_cast<seconds>(stop - start);
    auto durationms = duration_cast<milliseconds>(stop - start);

    cout << "Time to input and sort: " << durations.count() << " seconds or "
         << durationms.count() << " milliseconds" << endl;

    src.close();

    FILE *in, *out;
    if ((in = fopen(argv[1], "r+")) == NULL)
    {
        printf("Unable to read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((out = fopen(argv[2], "w+")) == NULL)
    {
        printf("Unable to write to file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    rewind(in);
    int len, rank;
    while (fscanf(in, "%d %d", &len, &rank) != EOF)
    {
        //cout << "length: " << len << " rank: " << rank << endl;
        fprintf(out, "%s\n", vlist->getRank(len, rank).c_str());
    }
    fclose(in);
    fclose(out);
    return 0;
}