  ### HW4: Six Degrees of Searching

  Bard.cpp
  Due Date: 11-03-19
  Author: Baladithya Balamurugan
  UCID: bbalamur
  Course: CSE 101

  [Assignment Document](../bfs_six_degrees.pdf)

  ### Description

  In this assignment we were supposed to take the entirety of IMDB's movie-actor database and parse through taking every line and storing in a graph implementation of a data structure. Then using the created graph we were supposed to play an equivalent of "Six Degrees of Kevin Bacon" by taking a query of 2 possible actors and finding the shortest common path between them byt common movies and coactors.

  The resulting executable needs to take 2 arguments inf the form:
      **./sixdegrees [input.txt] [output.txt]**

  The Test folders have 3 input files with respective output files: [simple-input.txt](Tests/simple-input.txt), [more-input.txt](Tests/more-input.txt), and [evenmore-input.txt](Tests/evenmore-input.txt)

  This file will run succesfully if the **cleaned_movieslist.txt** file exists in the same directory and if the **input.txt** formatting is correct as specified below.

  **input.txt** format:

    <string movie> <string actor> <string actor> <string actor> ...
    <string movie> <string actor> <string actor> <string actor> ...
    .
    .
    .
    <string movie> <string actor> <string actor> <string actor> ...


  The first word in the line is the movie and the rest in said line are the actors in the movie

  ### Relevant Files

  **sixdegrees.cpp**
  * The main file that compiles to executable and takes in 2 arguments and parses **cleaned_movieslist.txt**
  * prints total parse and sort time in console

  **graph.cpp**
  * The Graph ADT/Class ==> implentation of a graph data structure using an **unordered_map** data structure
  * Contains 2 attributes: an **unordered_map** of type pair<string,list<Coactor>> and the size of aforementioned **unordered_map**

  **graph.h**
  * The header file for **graph.cpp**
  * A pipeline to connect **sixdegrees.cpp** to **graph.cpp**

  **Coactor**
  * The **Coactor** ADT/Class ==> used to hold the string values inserted namely the movie acted in and the name of the coactor

  **README.md**
  * The current file you are reading that describes the assignment and the relevant files in parent directory

  ### Other Files

 **cleaned_movieslist.txt**
  * IMDB movie-actor data

  ### Instructions

  **Basic**
    1. Run command 'make clean' in terminal
    2. Run command 'make' in termial ==> creates 'sixdegrees' executable
    3. Make sure that the input query text file is formatted correctly
    4. Run './sixdegrees [Name of Input file] [Name of Output file]' (there is no need to create the output file beforehand as the executable will do so if it doesn't exist)
    5. Output file should have the results of the query and **OutputLog.txt** should have an output of runtime
    6. Run command 'make clean' in terminal
