#include "header.h"
int settingValue(Position q, sPosition ticTacToeStog, sPosition sudokuStog) {
	//setting random value to maze tiles and mask; setting columns and rows for maze
	Position help = q;
	sPosition sudokuHelp = sudokuStog;
	sPosition tttHelp = ticTacToeStog;
	int i = 0;
	int random = randomNumberGenerator(8) + 1;
	while (help != NULL) {
		int j = 0;
		tilePosition tiles = help->firstTile;
		while (tiles != NULL) {
			tiles->test = 4;//randomNumberGenerator(3);
			tiles->mask = randomNumberGenerator(2);
			tiles->isSolved = 0;
			tiles->row = i;
			tiles->column = j;
			tiles = tiles->nextTile;
			j++;
		}
		i++;
		help = help->next;
	}
	//making sure first tile is path
	q->firstTile->isSolved = 1;
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
	//setting sudoku rows, columns, mask and picking random premade sudoku
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
	//choosing random pre-made sudoku
	switch (random) {
	case 1:
		sudokuOne(sudokuStog);
		break;
	case 2:
		sudokuTwo(sudokuStog);
		break;
	case 3:
		sudokuThree(sudokuStog);
		break;
	case 4:
		sudokuFour(sudokuStog);
		break;
	case 5:
		sudokuFive(sudokuStog);
		break;
	case 6:
		sudokuSix(sudokuStog);
		break;
	case 7:
		sudokuSeven(sudokuStog);
		break;
	case 8:
		sudokuEight(sudokuStog);
		break;
	default:
		printf("Greska u switch funkciji u settingValue\n");
		break;
	}
	return 0;
}

int randomNumberGenerator(int x) {
	int r = rand();
	return r % x;
}