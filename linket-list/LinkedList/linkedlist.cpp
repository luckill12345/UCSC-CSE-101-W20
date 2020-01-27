// Filename: linkedlist.cpp
//
// Contains the class LinkedList that represents a linked list. This contains some basic operations, such as insert, delete, find, length
//
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

Node *head;

// Default constructor sets head and tail to null
LinkedList ::LinkedList()
{
    head = NULL;
}

// Insert(int val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
void LinkedList ::insert(int val)
{
    Node *to_add = new Node; // creates new Node
    to_add->data = val;      // sets the data to hold input val

    to_add->next = head; // make to_add point to existing head
    head = to_add;       // set head to to_add
}

// find(int val): Finds a Node with data "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node *LinkedList ::find(int val)
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    while (curr != NULL) //looping over list
    {
        if (curr->data == val) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node *LinkedList ::deleteNode(int val)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) // loop over list, starting from head
    {
        if (curr->data == val) // we found Node with val, so break
            break;
        //otherwise, proceed list
        prev = curr;       // move prev by one Node
        curr = curr->next; // move curr by one Node
    }
    // at this point, curr points to Node with val. If curr is null, then val is not in the list.
    if (curr == NULL) // val not found
        return NULL;
    // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
    // Otherwise, we delete the Node after prev.
    if (prev == NULL)            // we need to delete head
        head = head->next;       // delete head
    else                         // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    return curr;
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void LinkedList ::deleteList()
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    Node *temp = NULL;

    // curr will loop over list. At every iteration, we first store a pointer to the next Node, and then delete the current Node.
    while (curr != NULL)
    {                      // Looping over list
        temp = curr->next; // store pointer to next Node in the list
        delete (curr);     // delete the current Node
        curr = temp;       // update curr to proceed through list
    }
    head = NULL;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string LinkedList ::print()
{
    string list_str = ""; // string that has list
    Node *curr = head;    // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will loop over list. It prints the content of curr, and then moves curr to next Node.
    while (curr != NULL)
    {                                                      // looping over list
        list_str = list_str + to_string(curr->data) + " "; //append string with current Node's data
        curr = curr->next;                                 // proceed through list
    }
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back();   // remove the last (extra) space from string
    return list_str;
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LinkedList ::length()
{
    int length = 0;    // initialize length to zero
    Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list

    while (curr != NULL)
    {                      // looping over list
        length++;          // increment length
        curr = curr->next; // proceed to next Node
    }
    return length;
}

void LinkedList::dedup()
{
    Node *init, *temp, *duplicate;
    init = this->head;

    while (init != NULL && init->next != NULL)
    {
        temp = init;
        while (temp->next != NULL)
        {
            if (init->data == temp->next->data)
            {
                duplicate = temp->next;
                temp->next = temp->next->next;
                delete (duplicate);
            }
            else
            {
                temp = temp->next;
            }
        }
        init = init->next;
    }
}

bool palindrome(Node *current, Node *&init)
{
    if (current == NULL)
        return true;
    if (!::palindrome(current->next, init))
        return false;
    Node *prev = init;
    init = init->next;
    return (prev->data == current->data);
}

bool LinkedList::palindrome()
{
    return ::palindrome(this->head, this->head);
}

Node *deletelast(int val, Node *current, Node *last)
{
    if (current->next == NULL)
    {
        Node *temp = last->next;
        last->next = last->next->next;
        delete (last->next);
        return temp;
    }
    if (current->next->data == val)
    {
        last = current;
    }
    return ::deletelast(val, current->next, last);
}

// Given an int argument, this function deletes the last occurrence
// of the element, and returns a pointer to the deleted node.
Node *LinkedList::deletelast(int val)
{
    return ::deletelast(val, this->head, NULL);
}

Node *getTail(Node *current)
{
    if (current->next->next == NULL)
    {
        return current;
    }
    return ::getTail(current->next);
}

// Given a non-negative int argument, this function “rotates” the list by this value
void LinkedList::rotate(int factor)
{

    for (int i = factor; i > 0; i--)
    {
        Node *tail = ::getTail(this->head);
        tail->next->next = this->head;
        this->head = tail->next;
        tail->next = NULL;
    }
}

Node *getTail1(Node *current)
{
    if (current == NULL)
    {
        return current;
    }
    return ::getTail1(current->next);
}

// Given a non-negative int argument (say, val), this function reverses the
// order of the first val elements of the list, and leaves the others unchanged.
void LinkedList::reverse(int factor)
{
    Node *temp, *current = this->head, *prev = NULL, *next = NULL;
    int count = 1;

    if (factor == 1)
        return;
    while (current != NULL && factor > 1)
    {

        current = current->next;
        factor--;
    }
    temp = current->next;
    current->next = NULL;

    current = this->head;
    while (current != NULL)
    {

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    this->head = prev;

    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = temp;
}