  ### HW1: Much ado about linking

  Bard.cpp
  Due Date: 24-01-19
  Author: Baladithya Balamurugan
  UCID: bbalamur
  Course: CSE 101

  [Assignment Document](../hw_shakespeare.pdf)

  ### Description

  In this assignment we were supposed to take the entirety of Shakespear's Sonnets and parse through taking wvery word and storing ina sord of Vocab List.

  The resulting executable needs to take 2 arguments inf the form:
      **./bard [input.txt] [output.txt]**
      
  This file will run succesfully if the **shakespeare-cleaned5.txt** file exists in the same directory and if the **input.txt** formatting is correct as specified below.

  **input.txt** format:

    int int
    int int
    .
    .
    .
    int int

  The first number in the line is the length of word the second number is the rank of the word of said length

  ### Relevant Files

  **Bard.cpp**
  * The main file that compiles to executable and takes in 2 arguments and parses **shakespeare-cleaned5.txt**
  * prints total parse and sort time in console

  **VocabList.cpp**
  * The VocabList ADT/Class ==> essentially a Hashtable without the hashing component and additionally can extend the array size (contains essential functions)
  * Contains 2 attributes: an array of type **LinkedList** and the size of aforementioned array

  **VocabList.h**
  * The header file for **VocabList.cpp**
  * A pipeline to connect **Bard.cpp** to **VocabList.cpp**

  **LinkedList.cpp**
  * The **LinkedList** ADT/Class ==> a **LinkedList** data type with supporting functions needed to run
  * Contains 3 attributes: a **Node** pointer, a boolean signaling if list is sorted, and an int size of the **LinkedList**
  * **Node** data type ==> Contains 3 attributes: a string containind the word, the frequesncy of said word that has appeared, and a **Node** pointer (for obvious reasons)

  **LinkedList.h**
  * The header file for **LinkedList.cpp**
  * A pipeline to connect **VocabList.cpp** to **LinkedList.cpp**

  **README.md**
  * The current file you are reading that describes the assignment and the relevant files in parent directory

  ### Other Files

  **BardTester.cpp**
  * A file that compiles to executable and takes in 2 arguments and parses **shakespeare-cleaned5.txt**
  * Used as a tester executable for the LinkedList and VocabList ADTs

  ### Instructions

  **Basic**
    1. Run command 'make clean' in terminal
    2. Run command 'make' in termial ==> creates 'bard' executable
    3. Make sure that the input query text file is formatted correctly
    4. Run './bard [Name of Input file] [Name of Output file]' (there is no need to create the output file beforehand as the executable will do so if it doesn't exist)
    5. Output file should have the results of the query and console should have an output
    6. Run command 'make clean' in terminal

  **Other**
    1. Run command 'make clean' in terminal
    2. Run command 'make -f Makefile1' in termial ==> creates 'BardTester' executable
    3. Make sure that the input query text file is formatted correctly
    4. Run './BardTester [Name of Input file] [Name of Output file]' (there is no need to create the output file beforehand as the executable will do so if it doesn't exist)
    5. Output file should have the results of the query and console should have an output
    6. Run command 'make clean -f Makefile1' in terminal