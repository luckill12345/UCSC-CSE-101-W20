  ### HW3: Life is all about balancec

  wordrange.cpp
  Due Date: 26-02-19
  Author: Baladithya Balamurugan
  UCID: bbalamur
  Course: CSE 101

  [Assignment Document](../range_queries_avl.pdf)

  **Disclaimer:** This code solves the board in microseconds but if line 33 in **nqueens.cpp** is changed from "break;" to "continue;" the resulting boards are solved going from left to right instead of right to left if "break;" is left unchanged.

  ### Description

  In this assignment we were supposed to take a file input that contains two types of queries (inserting and ranging). Then using the queries execute them on a AVL Tree (Height Balancing Binary Search Tree). The assignment has 3 tiers of grading: 5 points if you make a binary search tree (BST) that inserts and ranges the entire tree, 7 points if the program can deal with 1 million operations a minute, and finally full credit if the program can handle 3 million operations in a minute.

  The Test folders have 3 input files that follow these tiers respectively: [simple-input.txt](Tests/simple-input.txt), [allwords-basic.txt](Tests/allwords-basic.txt), and [allwords-more-range.txt](Tests/allwords-more-range.txt)

  The resulting executable needs to take 2 arguments inf the form:
      **./wordrange [input.txt] [output.txt]**
      
  **input.txt** format:

    i <string input>
    .
    .
    .
    i <string input>
    i <string input>
    .
    .
    .
    r <string of left bound of range> <string of right bound of range>
    .
    .
    .
    r <string of left bound of range> <string of right bound of range>
    r <string of left bound of range> <string of right bound of range>

  Keep note that the AVL tree compares using strings not integers so by string logic the string 100 is less than string 50

  ### Relevant Files

  **wordrange.cpp**
  * The main file that compiles to executable and takes in 2 arguments and generates an extra file aside from the designated output file: **OutputLog.txt**
  * prints total, solve, sort, and stringify time in **OutputLog.txt**

  **AVL.cpp**
  * The **AVL** ADT/Class ==> used to hold a root **Node** with essential functions: insert, find, range, etc
  * Contains 1 attributes: a pointer of type **Node** named [root]

  **Node**
  * The **Node** ADT/Class ==> used to hold the string values inserted, height of node in tree, left and right descendent counts and left and right children

  **AVL.h**
  * The header file for **AVL.cpp**
  * A pipeline to connect **wordrange.cpp** to **AVL.cpp**

  **README.md**
  * The current file you are reading that describes the assignment and the relevant files in parent directory

  **Makefile1**
  * Makefile that compiles **wordrange.cpp**

  ### Other Files

  **AVLTester.cpp**
  * A file that compiles to executable and build a basic AVL Tree and inserts test values and prints relavent values to console
  * Used as a tester executable for the AVL ADT

  **Makefile1**
  * Makefile that compiles **AVLTester.cpp**

  ### Instructions

  **Basic**
    1. Run command 'make clean' in terminal
    2. Run command 'make' in termial ==> creates 'wordrange' executable
    3. Make sure that the input query text file is formatted correctly
    4. Run './wordrange [Name of Input file] [Name of Output file]' (there is no need to create the output file beforehand as the executable will do so if it doesn't exist)
    5. Output file should have the results of the query and **OutputLog.txt** should have an output
    6. Run command 'make clean' in terminal

  **Other**
    1. Run command 'make clean' in terminal
    2. Run command 'make -f Makefile1' in termial ==> creates 'AVLTester' executable
    3. Make sure that the input query text file is formatted correctly
    4. Run './AVLTester'
    5. Output file should have the results of the query and console should have an output
    6. Run command 'make clean -f Makefile1' in terminal