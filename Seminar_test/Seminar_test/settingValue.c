#include "header.h"
int settingValue(Position q, sPosition ticTacToeStog, sPosition sudokuStog) {
	//setting random value to maze tiles and mask; setting columns and rows for maze
	Position help = q;
	sPosition sudokuHelp = sudokuStog;
	sPosition tttHelp = ticTacToeStog;
	int i = 0, k = 0;
	while (help != NULL) {
		int j = 0;
		tilePosition tiles = help->firstTile;
		while (tiles != NULL) {
			tiles->path = 0;
			tiles->mask = 0;
			tiles->end = 0;
			tiles->placement = k;
			tiles->isImportant = 0;
			tiles->row = i;
			tiles->column = j;
			if (help->next == NULL) {
				if (tiles->nextTile == NULL) {
					tiles->end = 1;
				}
			}
			tiles = tiles->nextTile;
			j++;
			k++;
		}
		i++;
		help = help->next;
	}

	//making sure first tile is path
	q->firstTile->mask = 1;

	//setting tic tac toe rows and columns
	settingMGTValue(ticTacToeStog);

	//setting sudoku rows and columns
	settingMGTValue(sudokuStog);
	
	return 0;
}

int settingMGTValue(sPosition stog) {
	int i = 0, j = 0;
	while (stog != NULL) {
		mgtPosition tiles = stog->firstMGT;
		while (tiles != NULL) {
			tiles->row = i;
			tiles->column = j;
			tiles = tiles->brother;
			j++;
		}
		j = 0;
		i++;
		stog = stog->nextStog;
	}
	return 0;
}

int resettingValue(sPosition stog) {
	while (stog != NULL) {
		mgtPosition tiles = stog->firstMGT;
		while (tiles != NULL) {
			tiles->symbol = 0;
			tiles->mask = 0;
			tiles = tiles->brother;
		}
		stog = stog->nextStog;
	}
	return 0;
}

int randomNumberGenerator(int x) {
	int r = rand();
	return r % x;
}

int switchFunction(char choice) {
	switch (choice) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	}
}