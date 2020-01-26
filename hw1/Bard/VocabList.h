#ifndef VOCABLIST_H

#define VOCABLIST_H

#include "LinkedList.h"
#include <string>

using namespace std;

class VocabList
{
private:
    LinkedList *list;
    int size;

public:
    VocabList();
    void arrayDoubler();
    void insert(string);
    void sort();
    string getRank(int, int);
    string print();
    string print(int);
    void deleteList();
};

#endif