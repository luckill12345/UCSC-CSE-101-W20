  ### HW2: Place your queens with care

  nqueens.cpp
  Due Date: 206-02-19
  Author: Baladithya Balamurugan
  UCID: bbalamur
  Course: CSE 101

  [Assignment Document](../nqueens.pdf)
  [Easier to Follow Version](../NQueensV1/README.md)

  **Disclaimer:** This code solves the board in microseconds but if line 33 in **nqueens.cpp** is changed from "break;" to "continue;" the resulting boards are solved going from left to right instead of right to left if "break;" is left unchanged.

  ### Description

  In this assignment we were supposed to take a file input that contains data pertaining to the [NQueens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle). We are given the board size and a number of queens to be placed on the board initially. Then we solve. There is a caveat, like every programming problem. This caveat states that we cannot use recursion but instead a requirement is that we complete the problem by simulating recursion using stacks.

  **HINT:** Make a while loop that checks if the stack is empty and if not then pop off the top of the stack and complete the copmutational steps that may or may not result in another set of data being push onto the top of the stack. This is then repeated till a base case is reached. or no ideal solution is reached.

  The resulting executable needs to take 2 arguments inf the form:
      **./nqueens [input.txt] [output.txt]**
      
  **input.txt** format:

    <board size int> <row int of queen> <column int of queen> ... <row int of queen> <column int of queen>
    <board size int> <row int of queen> <column int of queen> ... <row int of queen> <column int of queen>
    .
    .
    .
    <board size int> <row int of queen> <column int of queen> ... <row int of queen> <column int of queen>

  The first number in the line is the length of word the second number is the rank of the word of said length

  ### Relevant Files

  **nqueens.cpp**
  * The main file that compiles to executable and takes in 2 arguments and generates an extra file aside from the designated output file: **OutputLog.txt**
  * prints total, solve, sort, and stringify time in **OutputLog.txt**

  **Board.cpp**
  * The **Board** ADT/Class ==> used to hold attributes of a Board State with essential functions: placeQueen, isValid, isComplete, etc
  * Contains 3 attributes: a vector of type **Queens** and the max size of board and the total number of queens on the board

  **Board.h**
  * The header file for **Board.cpp**
  * A pipeline to connect **nqueens.cpp** to **Board.cpp**

  **Queens.cpp**
  * The **Queens** ADT/Class ==> a **Queens** data type with supporting functions needed to run
  * Contains 3 attributes: an int row, an int column, and a boolean signifying if the queen is a non-movable queen

  **Queens.h**
  * The header file for **Queens.cpp**
  * A pipeline to connect **nqueens.cpp** and **Board.cpp** to **Queens.cpp**

  **README.md**
  * The current file you are reading that describes the assignment and the relevant files in parent directory

  ### Other Files

  N/A

  ### Instructions

  **Basic**
    1. Run command 'make clean' in terminal
    2. Run command 'make' in termial ==> creates 'nqueens' executable
    3. Make sure that the input query text file is formatted correctly
    4. Run './nqueens [Name of Input file] [Name of Output file]' (there is no need to create the output file beforehand as the executable will do so if it doesn't exist)
    5. Output file should have the results of the query and **OutputLog.txt** should have an output
    6. Run command 'make clean' in terminal