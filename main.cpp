#include <iostream>

#define		SIZE			9

class SudokuSolver
{
public:

	SudokuSolver(int numbers[SIZE][SIZE])
	{
		for (int row = 0; row < SIZE; row++)
		{
			for (int col = 0; col < SIZE; col++)
			{
				grid[row][col] = numbers[row][col];
			}
		}
	}

	bool isSolvable()
	{
		int row, col;
		if (!hasEmpty(row, col))
			return true;
		
		for (int num = 1; num <= SIZE; num++)
		{
			if (isValidPosition(num, col, row))
			{
				grid[row][col] = num;
				if (isSolvable())
					return true;

				grid[row][col] = 0;
			}
		}
		return false;
	}

	bool hasEmpty(int& row, int& col)
	{
		for (row = 0; row < SIZE; row++)
		{
			for (col = 0; col < SIZE; col++)
			{
				if (grid[row][col] == 0)
					return true;
			}
		}
		return false;
	}

	bool isValidPosition(int num, int col, int row)
	{
		if (isValidInRow(num, row) && isValidInColumn(num, col) && isValidInBox(num, col - col % 3, row - row % 3))
			return true;
		return false;
	}

	bool isValidInRow(int num, int row)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (num == grid[row][col])
				return false;
		}
		return true;
	}

	bool isValidInColumn(int num, int col)
	{
		for (int row = 0; row < SIZE; row++)
		{
			if (num == grid[row][col])
				return false;
		}
		return true;
	}

	bool isValidInBox(int num, int boxStartCol, int boxStartRow)
	{
		for (int row = boxStartRow; row < boxStartRow + 3; row++)
		{
			for (int col = boxStartCol; col < boxStartCol + 3; col++)
			{
				if (num == grid[row][col])
					return false;
			}
		}
		return true;
	}

	void printBoard()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				std::cout << grid[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
private:
	int grid[SIZE][SIZE];
};


int main()
{
	int grid[SIZE][SIZE] = { { 0, 0, 7, 0, 0, 3, 9, 0, 2 },
							{ 0, 0, 0, 8, 0, 0, 0, 0, 0 },
							{ 9, 4, 3, 0, 0, 0, 0, 0, 7 },
							{ 6, 9, 0, 0, 0, 0, 0, 0, 0 },
							{ 3, 0, 0, 5, 2, 7, 0, 0, 0 },
							{ 0, 0, 0, 0, 0, 0, 8, 4, 0 },
							{ 0, 0, 0, 0, 4, 8, 0, 0, 0 },
							{ 2, 6, 0, 0, 0, 0, 0, 0, 0 },
							{ 0, 0, 0, 0, 0, 0, 1, 2, 9 } };


	SudokuSolver sudoku(grid);
	std::cout << "*******Original*******" << std::endl;
	sudoku.printBoard();

	if (sudoku.isSolvable())
	{
		std::cout << "*******Solved*********" << std::endl;
		sudoku.printBoard();
	}
	else
		std::cout << "No solution exists" << std::endl;
}