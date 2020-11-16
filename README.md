# SudokuSolver

Simple Sudoku Solver

The idea is the have a function(isSolvable()) which checks all possible VALID numbers from 1 to 9 on empty place and recursively call the same function with updated number to check the next empty position. There are some helper functions such as isValidPosition(), printBoard(), hasEmpty() and some others.

For example given the Sudoku problem as such:

  0, 0, 7, 0, 0, 3, 9, 0, 2
  0, 0, 0, 8, 0, 0, 0, 0, 0
  9, 4, 3, 0, 0, 0, 0, 0, 7
  6, 9, 0, 0, 0, 0, 0, 0, 0
  3, 0, 0, 5, 2, 7, 0, 0, 0
  0, 0, 0, 0, 0, 0, 8, 4, 0
  0, 0, 0, 0, 4, 8, 0, 0, 0
  2, 6, 0, 0, 0, 0, 0, 0, 0
  0, 0, 0, 0, 0, 0, 1, 2, 9
 
 where '0's represent empty squares, the result would be:
 
  8, 1, 7, 4, 5, 3, 9, 6, 2 
  5, 2, 6, 8, 7, 9, 3, 1, 4 
  9, 4, 3, 1, 6, 2, 5, 8, 7 
  6, 9, 1, 3, 8, 4, 2, 7, 5 
  3, 8, 4, 5, 2, 7, 6, 9, 1 
  7, 5, 2, 9, 1, 6, 8, 4, 3 
  1, 3, 9, 2, 4, 8, 7, 5, 6 
  2, 6, 5, 7, 9, 1, 4, 3, 8 
  4, 7, 8, 6, 3, 5, 1, 2, 9 
  
  
  Inside isSolvable() function, first hasEmpty() function is called, which checks if an empty space exists. If no, it returns true, which means there is a solution found. Otherwise, we continue. When returning from hasEmpty(), 2 parameters are returned by reference - row, col. They represent the position of first empty space(or 0). Next, the numbers from 1 to 9 are passed to isValidPosition() function to check if the number is valid in that position based on rules of Sudoku. 
 Once the valid number is found, isSolvable() function is called(recursive call). This will check the next empty square. If there is no solution exists for the currect value(num), it will be reset back to 0, and the program will try the next value for num.
 
