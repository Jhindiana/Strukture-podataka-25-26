#include "header.h"
int sudoku(sPosition sudokuStog) {
	char playerChoiceRow, playerChoiceColumn;
	int playerRow, playerColumn, flag = 1, n = SUDOKU_SIZE * SUDOKU_SIZE - revealedNumbers(sudokuStog), m;
	while (flag) {
		if (!n) {
			printf("Sudoku cleared\n");
			printingSudokuUsingMask(sudokuStog);
			return 1;
		}
		printf("\n");
		printingSudokuUsingMask(sudokuStog);
		printf("\n");
		printingSudokuRowsAndColumns(sudokuStog);
		printf("Choose row: ");
		scanf(" %c", &playerChoiceRow);
		if (playerChoiceRow < '0' || playerChoiceRow > '3') {
			printf("Invalid choice\n");
			continue;
		}
		playerRow = switchFunction(playerChoiceRow);
		printf("Choose column: ");
		scanf(" %c", &playerChoiceColumn);
		if (playerChoiceColumn < '0' || playerChoiceColumn > '3') {
			printf("Invalid choice\n");
			continue;
		}
		playerColumn = switchFunction(playerChoiceColumn);
		m = applyingSudokuChoice(sudokuStog, playerRow, playerColumn);
		if (m == 1) {
			printf("Wrong number placed\n");
			continue;
		}
		else if (m == 2) {
			printf("Wrong solution\n");
			return 0;
		}
		n--;
	}
	return 0;
}

int revealedNumbers(sPosition sudokuStog) {
	int n = 0;
	while (sudokuStog != NULL) {
		mgtPosition stile = sudokuStog->firstMGT;
		while (stile != NULL) {
			if (stile->mask) {
				n++;
			}
			stile = stile->brother;
		}
		sudokuStog = sudokuStog->nextStog;
	}
	return n;
}

int applyingSudokuChoice(sPosition sudokuStog, int pR, int pC) {
	int number;
	sPosition tempPrint = sudokuStog;
	while (sudokuStog->depth_mgs != pR) {
		sudokuStog = sudokuStog->nextStog;
	}
	mgtPosition selectedTile = sudokuStog->firstMGT;
	while (selectedTile->column != pC) {
		selectedTile = selectedTile->brother;
	}
	if (selectedTile->mask) {
		printf("Position already solved\n");
		return 0;
	}
	selectedTile->mask = 2;
	printingSudokuUsingMask(tempPrint);
	selectedTile->mask = 0;
	printf("Number: ");
	scanf("%d", &number);
	if (number < 1 || number>4) {
		return 1;
	}
	if (selectedTile->symbol != number) {
		return 2;
	}
	selectedTile->mask = 1;
	return 0;
}

int sudokuOne(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = {	{2, 1, 3, 4},
													{3, 4, 2, 1},
													{1, 3, 4, 2},
													{4, 2, 1, 3} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 4 || k == 5 || k == 12 || k == 13 || k == 15) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 5;
}

int sudokuTwo(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {4, 2, 3, 1},
												  {3, 1, 2, 4},
												  {1, 3, 4, 2},
												  {2, 4, 1, 3} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 3 || k == 6 || k == 7 || k == 9 || k == 12) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 5;
}

int sudokuThree(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {2, 4, 1, 3},
												  {1, 3, 2, 4},
												  {3, 1, 4, 2},
												  {4, 2, 3, 1} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 2 || k == 5 || k == 11 || k == 12) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 4;
}

int sudokuFour(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {2, 4, 3, 1},
												  {3, 1, 4, 2},
												  {1, 3, 2, 4},
												  {4, 2, 1, 3} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 6 || k == 9 || k == 12 || k == 14) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 4;
}

int sudokuFive(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {4, 2, 3, 1},
												  {1, 3, 2, 4},
												  {2, 1, 4, 3},
												  {3, 4, 1, 2} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 0 || k == 5 || k == 8 || k == 10) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 4;
}

int sudokuSix(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {4, 3, 1, 2},
												  {2, 1, 3, 4},
												  {3, 2, 4, 1},
												  {1, 4, 2, 3} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 3 || k == 6 || k == 9 || k == 11) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 4;
}

int sudokuSeven(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {4, 2, 1, 3},
												  {3, 1, 2, 4},
												  {1, 3, 4, 2},
												  {2, 4, 3, 1} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 1 || k == 4 || k == 6 || k == 8 || k == 14) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 5;
}

int sudokuEight(sPosition sudokuStog) {
	sPosition sudoku_stog = sudokuStog;
	int sudokuArray[SUDOKU_SIZE][SUDOKU_SIZE] = { {1, 3, 4, 2},
												  {2, 4, 3, 1},
												  {3, 1, 2, 4},
												  {4, 2, 1, 3} };
	int i = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		int j = 0;
		while (tileInSudoku != NULL) {
			tileInSudoku->symbol = sudokuArray[i][j];
			j++;
			tileInSudoku = tileInSudoku->brother;
		}
		i++;
		sudoku_stog = sudoku_stog->nextStog;
	}
	sudoku_stog = sudokuStog;
	int k = 0;
	while (sudoku_stog != NULL) {
		mgtPosition tileInSudoku = sudoku_stog->firstMGT;
		while (tileInSudoku != NULL) {
			if (k == 0 || k == 3 || k == 6 || k == 12 || k == 14) {
				tileInSudoku->mask = 1;
			}
			else {
				tileInSudoku->mask = 0;
			}
			k++;
			tileInSudoku = tileInSudoku->brother;
		}
		sudoku_stog = sudoku_stog->nextStog;
	}
	return 5;
}
