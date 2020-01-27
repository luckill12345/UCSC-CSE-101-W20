// Filename: linkedlist.h
//
// Header file for the class LinkedList that represents a linked list
//
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

// node struct to hold data
struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head; // Stores head of linked list
public:
	LinkedList();		   // Default constructor sets head to null
	void insert(int);	   // insert int into list
	Node *find(int);	   // find int in list, and return pointer to node with that int. If there are multiple copies, this only finds one copy
	Node *deleteNode(int); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
	void deleteList();	   // deletes every node to prevent memory leaks, and frees memory
	string print();		   // Construct string with data of list in order
	int length();		   // Returns the length of the linked list
	void dedup();		   // This is a deduplication function, meaning that all duplicate values are deleted from the list. Specifically, for every value, you need to delete all subsequent occurrences from the list.
	bool palindrome();	   // The function returns true if the list is a palindrome, and returns false otherwise.
	Node *deletelast(int); // Given an int argument, this function deletes the last occurrence of the element, and returns a pointer to the deleted node.
	void rotate(int);	   // Given a non-negative int argument, this function “rotates” the list by this value
	void reverse(int);	   // Given a non-negative int argument (say, val), this function reverses the order of the first val elements of the list, and leaves the others unchanged.
};

#endif
