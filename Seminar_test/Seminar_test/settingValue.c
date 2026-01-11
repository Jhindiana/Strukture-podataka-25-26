#include "header.h"
int settingValue(Position q, sPosition ticTacToeStog, sPosition sudokuStog) {
	//setting random value to maze tiles and mask; setting columns and rows for maze
	Position help = q;
	sPosition sudokuHelp = sudokuStog;
	sPosition tttHelp = ticTacToeStog;
	int i = 0;
	while (help != NULL) {
		int j = 0;
		tilePosition tiles = help->firstTile;
		while (tiles != NULL) {
			tiles->test = 4;//randomNumberGenerator(3);
			tiles->mask = 0;
			tiles->row = i;
			tiles->column = j;
			tiles = tiles->nextTile;
			j++;
		}
		i++;
		help = help->next;
	}

	//making sure first tile is path
	q->firstTile->mask = 1;
	i = 0;

	//setting tic tac toe row and column
	while (tttHelp != NULL) {
		mgtPosition tttTiles = tttHelp->firstMGT;
		int j = 0;
		while (tttTiles != NULL) {
			tttTiles->row = i;
			tttTiles->column = j;
			tttTiles = tttTiles->brother;
			j++;
		}
		i++;
		tttHelp = tttHelp->nextStog;
	}
	i = 0;

	//setting sudoku rows and columns
	while (sudokuHelp != NULL) {
		mgtPosition sudokuTiles = sudokuHelp->firstMGT;
		int j = 0;
		while (sudokuTiles != NULL) {
			sudokuTiles->row = i;
			sudokuTiles->column = j;
			sudokuTiles = sudokuTiles->brother;
			j++;
		}
		i++;
		sudokuHelp = sudokuHelp->nextStog;
	}
	
	return 0;
}

int resettingValue(sPosition stog) {
	while (stog != NULL) {
		tilePosition tiles = stog->firstMGT;
		while (tiles != NULL) {
			tiles->test = 0;
			tiles->mask = 0;
			tiles = tiles->nextTile;
		}
		stog = stog->nextStog;
	}
	return 0;
}

int randomNumberGenerator(int x) {
	int r = rand();
	return r % x;
}