#include "VocabList.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

VocabList::VocabList()
{
    list = new LinkedList[10];
    size = 10;
}

void VocabList::arrayDoubler()
{
    size_t newSize = (this->size) * 2;
    LinkedList *tempList = new LinkedList[newSize];
    memcpy(tempList, this->list, this->size * sizeof(LinkedList));
    this->size = newSize;
    delete[] this->list;
    this->list = tempList;
}

void VocabList::insert(string val)
{
    int len = val.length();
    if (this->size - 1 < len)
        this->arrayDoubler();

    this->list[len].insert(val);
}

void VocabList::sort()
{
    for (int i = 1; i <= this->size; i++)
    {
        if (this->list[i].length() > 1)
            this->list[i].sort();
    }
}

string VocabList::print()
{
    string temp = "";
    for (int i = 1; i <= this->size; i++)
    {
        if (this->list[i].length() >= 1)
            temp += this->list[i].print() + "|";
        else
            temp += "...|";
    }
    return temp;
}
string VocabList::print(int len) { return this->list[len].print(); }

string VocabList::getRank(int len, int rank)
{
    LinkedList currentList = this->list[len];
    Node *tgt = currentList.getRank(rank);

    return (tgt == NULL ? "-" : tgt->str);
}

void VocabList::deleteList()
{
    for (int i = 0; i < this->size; i++)
    {
        this->list[i].deleteList();
    }
}