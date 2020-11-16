# SudokuSolver

Simple Sudoku Solver

The idea is the have a function(isSolvable()) which checks all possible VALID numbers from 1 to 9 on empty place and recursively call the same function with updated number to check the next empty position. There are some helper functions such as isValidPosition(), printBoard(), hasEmpty() and some others.

For example given the Sudoku problem as such:

<img src="https://github.com/zbakin/SudokuSolver/blob/main/Original.png" width="330" height="300">
 
 where '0's represent empty squares, the result would be:
 
<img src="https://github.com/zbakin/SudokuSolver/blob/main/Solved.png" width="330" height="300">
  
  
  Inside isSolvable() function, first hasEmpty() function is called, which checks if an empty space exists. If no, it returns true, which means there is a solution found. Otherwise, we continue. When returning from hasEmpty(), 2 parameters are returned by reference - row, col. They represent the position of first empty space(or 0). Next, the numbers from 1 to 9 are passed to isValidPosition() function to check if the number is valid in that position based on rules of Sudoku. 
 Once the valid number is found, isSolvable() function is called(recursive call). This will check the next empty square. If there is no solution exists for the currect value(num), it will be reset back to 0, and the program will try the next value for num.
 
