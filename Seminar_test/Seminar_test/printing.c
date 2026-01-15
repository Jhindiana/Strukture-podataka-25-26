#include "header.h"
int printing(Position test, sPosition ticTacToe_stogTest, sPosition sudoku_stogTest) {
	//printing maze
	printingMaze(test);
	
	//printing depending on mask
	printf("\n");
	printingMazeUsingMask(test);

	//printing maze rows and columns
	printf("\n");
	printingMazeRowsAndColumns(test);

	//printing tic tac toe
	printf("\n");
	printingTicTacToe(ticTacToe_stogTest);

	//printing tic tac toe rows and columns
	printf("\n");
	printingTicTacToeRowsAndColumns(ticTacToe_stogTest);

	//printing sudoku
	printf("\n");
	printingSudoku(sudoku_stogTest);

	//printing sudoku depending on mask
	printf("\n");
	printingSudokuUsingMask(sudoku_stogTest);
	
	//printing sudoku rows and columns
	printf("\n");
	printingSudokuRowsAndColumns(sudoku_stogTest);

	return 0;
}

int printingMaze(Position firstTest) {
	printf("X \t");
	for (int i = 0; i < TILE; i++) {
		printf("%d ", i);
	}
	printf("\n\n\n");
	while (firstTest != NULL) {
		printf("%d\t", firstTest->depth);
		tilePosition help = firstTest->firstTile;
		while (help != NULL) {
			printf("%d ", help->path);
			help = help->nextTile;
		}
		printf("\n");
		firstTest = firstTest->next;
	}
	return 0;
}

int printingMazeUsingMask(Position firstTest) {
	printf("X \t");
	for (int i = 0; i < TILE; i++) {
		printf("%d ", i);
	}
	printf("\n\n\n");
	while (firstTest != NULL) {
		printf("%d\t", firstTest->depth);
		tilePosition help = firstTest->firstTile;
		while (help != NULL) {
			if (help->mask == 1) {
				printf("%d ", help->path);
			}
			else if (help->mask == 2) {
				printf("X ");
			}
			else {
				printf("_ ");
			}
			help = help->nextTile;
		}
		printf("\n");
		firstTest = firstTest->next;
	}
	return 0;
}

int printingMazeRowsAndColumns(Position firstTest) {
	printf("X \t");
	for (int i = 0; i < TILE; i++) {
		printf("%d ", i);
	}
	printf("\n\n\n");
	while (firstTest != NULL) {
		printf("%d\t", firstTest->depth);
		tilePosition help = firstTest->firstTile;
		while (help != NULL) {
			printf("%d,%d ", help->row, help->column);
			help = help->nextTile;
		}
		printf("\n");
		firstTest = firstTest->next;
	}
	return 0;
}

int printingTicTacToe(sPosition firstTicTacToeTest) {
	printf("X \t");
	for (int i = 0; i < 3; i++) {
		printf("%d ", i);
	}
	printf("\n\n\n");
	while (firstTicTacToeTest != NULL) {
		printf("%d\t", firstTicTacToeTest->depth_mgs);
		mgtPosition mgthelp = firstTicTacToeTest->firstMGT;
		while (mgthelp != NULL) {
			if (mgthelp->symbol == 1) {
				printf("X ");
			}
			else if (mgthelp->symbol == 2) {
				printf("O ");
			}
			else {
				printf("? ");
			}
			mgthelp = mgthelp->brother;
		}
		printf("\n");
		firstTicTacToeTest = firstTicTacToeTest->nextStog;
	}
	return 0;
}

int printingTicTacToeRowsAndColumns(sPosition firstTicTacToeTest) {
	while (firstTicTacToeTest != NULL) {
		mgtPosition mgthelp = firstTicTacToeTest->firstMGT;
		while (mgthelp != NULL) {
			if (!mgthelp->symbol) {
				printf("%d, %d\t", mgthelp->row, mgthelp->column);
			}
			else {
				printf("    \t");
			}
			mgthelp = mgthelp->brother;
		}
		printf("\n");
		firstTicTacToeTest = firstTicTacToeTest->nextStog;
	}
	return 0;
}

int printingSudoku(sPosition firstSudokuTest) {
	printf("X \t");
	for (int i = 0; i < SUDOKU_SIZE; i++) {
		printf("%d ", i);
	}
	printf("\n\n\n");
	while (firstSudokuTest != NULL) {
		printf("%d\t", firstSudokuTest->depth_mgs);
		mgtPosition mgthelp = firstSudokuTest->firstMGT;
		while (mgthelp != NULL) {
			printf("%d ", mgthelp->symbol);
			mgthelp = mgthelp->brother;
		}
		printf("\n");
		firstSudokuTest = firstSudokuTest->nextStog;
	}
	return 0;
}

int printingSudokuUsingMask(sPosition firstSudokuTest) {
	printf("X \t");
	for (int i = 0; i < SUDOKU_SIZE; i++) {
		printf("%d ", i);
	}
	printf("\n\n\n");
	while (firstSudokuTest != NULL) {
		printf("%d\t", firstSudokuTest->depth_mgs);
		mgtPosition mgthelp = firstSudokuTest->firstMGT;
		while (mgthelp != NULL) {
			if (mgthelp->mask) {
				printf("%d ", mgthelp->symbol);
			}
			else {
				printf("_ ");
			}
			mgthelp = mgthelp->brother;
		}
		printf("\n");
		firstSudokuTest = firstSudokuTest->nextStog;
	}
	return 0;
}

int printingSudokuRowsAndColumns(sPosition firstSudokuTest) {
	while (firstSudokuTest != NULL) {
		printf("%d\t", firstSudokuTest->depth_mgs);
		mgtPosition mgthelp = firstSudokuTest->firstMGT;
		while (mgthelp != NULL) {
			if (!mgthelp->mask) {
				printf("%d, %d \t", mgthelp->row, mgthelp->column);
			}
			else {
				printf("   \t");
			}
			mgthelp = mgthelp->brother;
		}
		printf("\n");
		firstSudokuTest = firstSudokuTest->nextStog;
	}
	return 0;
}