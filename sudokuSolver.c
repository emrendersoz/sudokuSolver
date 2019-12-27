//9x9 Sudoku Solver
#include <stdio.h>
#define SIZE 9

void printSudoku();
//is it safe to fill in:
int columnCheck(int row, int number);
int rowCheck(int col, int number);
int squareCheck(int row, int col, int number);

int sudokuSolver(int x, int y);
void gridSaver(int row, int col);

int grid[SIZE][SIZE] = { 0 };
int main() {

	int row = 0, col = 0;
	gridSaver(row, col);
	printSudoku(); //For 1st form
	sudokuSolver(row, col);
	printSudoku(); //For solved form

	system("pause");
	return 0;
}

int sudokuSolver(int row, int col) {
	int row2 = 0, col2 = 0;
	if (grid[row][col] == 0) {
		for (int number = 1; number < 10; number++) {
			if (!rowCheck(col, number) && !columnCheck(row, number) && !squareCheck(row, col, number)) {
				grid[row][col] = number;
				if (row == 8 && col == 8) { //is it end of the table
					return 1;
				}
				if (row < 8) {
					row2 = row + 1;
				}
				else {
					if (col < 8) {
						row2 = 0;
						col2 = col + 1;
					}
				}
				if (sudokuSolver(row2, col2)) {
					return 1;
				}
			}
		}
		grid[row][col] = 0;
		return 0;
	}
	if (grid[row][col] != 0) {
		if (row == 8 && col == 8) { //is it end of the table
			return 1;
		}
		if (row < 8) {
			row++;
		}
		else {
			if (col < 8) {
				row = 0;
				col++;
			}
		}
		if (sudokuSolver(row, col)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int rowCheck(int col, int number) {
	for (int i = 0; i < 9; i++) {
		if (grid[i][col] == number)
			return 1;
	}
	return 0;
}

int columnCheck(int row, int number) {
	for (int i = 0; i < 9; i++) {
		if (grid[row][i] == number)
			return 1;
	}
	return 0;
}

int squareCheck(int row, int col, int number) { //for 3x3
	if (row < 3) {
		row = 0;
	}
	else if (row < 6) {
		row = 3;
	}
	else {
		row = 6;
	}

	if (col < 3) {
		col = 0;
	}
	else if (col < 6) {
		col = 3;
	}
	else {
		col = 6;
	}

	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (grid[i][j] == number)
				return 1;
		}
	}
	return 0;
}

void printSudoku() {
	printf("-------------------------\n");
	for (int col = 0; col < 9; col++) {
		for (int row = 0; row < 9; row++) {
			if (row == 0) {
				printf("|");
			}
			printf(grid[col][row] == 0 ? " *" : "%2d", grid[col][row]);
			if (row % 3 == 2) {
				printf("%2s", "|");
			}
			if (row == 8) {
				puts("");
			}
		}
		if (col % 3 == 2) {
			printf("-------------------------\n");
		}
	}
	printf("\n");
}

void gridSaver(int row, int col) {
	printf("\t* 9x9 Sudoku Solver *\n\n");
	printf("Complete the line first then press enter. Don't forget to use 'space' between two numbers!\n");
	printf("If there is an unassigned cell, then enter 0(zero) instead.\n");
	printf("Here is the example for 3x3 grid:\n\n");
	printf("4 9 0 (Line break)\n0 6 0\n0 0 1\n\n");
	printf("Now enter the numbers for 9x9 sudoku table:\n");
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			scanf("%d", &grid[row][col]);
		}
	}
	puts("");
}
