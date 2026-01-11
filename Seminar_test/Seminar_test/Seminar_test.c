#include "header.h"

int main() {
	srand(time(NULL));
	maze headMaze = { .firstTile = NULL, .next = NULL };
	Position test = &headMaze;
	miniGameStog head_ticTacToeStog = { .firstMGT = NULL,.nextStog = NULL };
	sPosition ticTacToe_stogTest = &head_ticTacToeStog;
	miniGameStog head_sudokuStog = { .firstMGT = NULL,.nextStog = NULL };
	sPosition sudoku_stogTest = &head_sudokuStog;

	makingMiniGameTiles(ticTacToe_stogTest, 3);
	makingMiniGameTiles(sudoku_stogTest, SUDOKU_SIZE);

	int i, j;
	for (i = 0; i < TILE; i++) {
		test->next = mazeDepth(i);
		for (j = 0; j < TILE - 1; j++) {
			tilePosition temp = test->next->firstTile;
			while (temp->nextTile != NULL) {
				temp = temp->nextTile;
			}
			temp->nextTile = newTile();
		}
		test = test->next;
	}

	test = headMaze.next;
	ticTacToe_stogTest = head_ticTacToeStog.nextStog;
	sudoku_stogTest = head_sudokuStog.nextStog;
	settingValue(test, ticTacToe_stogTest, sudoku_stogTest);

	//printing
	printing(test, ticTacToe_stogTest, sudoku_stogTest);
	movement(&headMaze);

	ticTacToe(ticTacToe_stogTest);

	sudoku(sudoku_stogTest);

	return 0;
}