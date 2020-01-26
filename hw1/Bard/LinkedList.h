#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct Node
{
    string str;
    int freq = 1;
    Node *nxt;
};

class LinkedList
{
private:
    Node *head;
    bool sorted;
    int size;

public:
    LinkedList();
    Node *getHead();
    void insert(string);
    Node *find(string);
    // Node *deleteNode(string); // not necessary
    void deleteList(); // maybe needed
    string print();    // eeehhhh...
    int length();
    void sort();
    Node *getRank(int);
};

#endif
