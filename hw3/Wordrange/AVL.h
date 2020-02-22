#ifndef AVL_H
#define AVL_H

#include <string>

using namespace std;

// node struct to hold data
class Node
{
public:
    string key;
    Node *left, *right;
    int height;
    int ldesc, rdesc;

    Node() // default constructor
    {
        left = right = NULL;
        height = 1;
        ldesc = rdesc = 0;
    }

    Node(string val)
    {
        key = val;
        left = right = NULL;
        height = 1;
        ldesc = rdesc = 0;
    }
};

class AVL
{
private:
    Node *root; // Stores root of tree
public:
    AVL();               // Default constructor sets root to null
    void insert(string); // insert string into list
    int range(string, string);
    void printTree();
};

#endif
