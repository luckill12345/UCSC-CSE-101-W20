#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    sorted = false;
    size = 0;
}

Node *LinkedList::getHead() { return this->head; }

Node *find(string val, Node *current)
{
    if (current == NULL || current->str == val)
    {
        return current;
    }
    else
        return ::find(val, current->nxt);
}

Node *LinkedList::find(string val) { return ::find(val, this->head); }

void insert(string val, Node *current)
{
    if (current->nxt == NULL)
    {
        Node *newNode = new Node;
        newNode->nxt = NULL;
        newNode->str = val;
        current->nxt = newNode;
        return;
    }
    else
        ::insert(val, current->nxt);
}

void LinkedList::insert(string val)
{
    if (::find(val, this->head) == NULL)
    {
        if (this->head == NULL)
        {
            Node *newNode = new Node;
            this->head = newNode;
            this->head->str = val;
            this->head->nxt = NULL;
        }
        else
            ::insert(val, this->head);
        this->size++;
        this->sorted = false;
    }
    else
    {
        ::find(val, this->head)->freq++;
        this->sorted = false;
    }
}

// Node *deleteNode(string val, Node *current)
// {
//     if (current == NULL)
//         return NULL;
//     else if (current->nxt->str == val)
//     {
//         Node *found = current->nxt;
//         current->nxt = current->nxt->nxt;
//         return found;
//     }
//     else if (current->str == val)
//     {
//         Node *found = current;
//         current = NULL;
//         return found;
//     }
//     else
//         return ::deleteNode(val, current->nxt);
// }

// Node *LinkedList::deleteNode(string val)
// {
//     return ::deleteNode(val, this->head);
// }

// void deleteList(Node *current)
// {
//     if (current == NULL)
//         return;
//     ::deleteList(current->nxt);
//     free(current);
// }

void LinkedList::deleteList()
{
    // ::deleteList(this->head);
    this->size = 0;
    Node *current = this->head;
    Node *temp = NULL;
    while (current != NULL)
    {
        temp = current->nxt;
        delete (current);
        current = temp;
    }
    this->head = NULL;
}

string print(string list, Node *current)
{
    if (current == NULL)
        return list;
    list += current->str + "|" + to_string(current->freq) + ",";
    return ::print(list, current->nxt);
}

string LinkedList::print() { return ::print("", this->head); }

int LinkedList::length() { return this->size; }

void sort(Node *current)
{
    while (current != NULL)
    {
        Node *max = current;
        Node *temp = current->nxt;

        while (temp != NULL)
        {
            if (max->freq < temp->freq)
                max = temp;
            else if (max->freq == temp->freq && max->str.compare(temp->str) > 0)
                max = temp;
            temp = temp->nxt;
        }
        string tempstr = current->str;
        int tempfreq = current->freq;
        current->str = max->str;
        current->freq = max->freq;
        max->str = tempstr;
        max->freq = tempfreq;
        current = current->nxt;
    }
}

void LinkedList::sort()
{
    ::sort(this->head);
    this->sorted = true;
}

Node *getRank(int rank, Node *current)
{
    if (rank == 0 || current == NULL)
        return current;
    else
        return ::getRank(rank - 1, current->nxt);
}

Node *LinkedList::getRank(int rank) { return ::getRank(rank, this->head); }