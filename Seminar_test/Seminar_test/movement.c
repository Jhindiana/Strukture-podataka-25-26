#include "header.h"
int movement(Position maze, sPosition ticTacToeStog, sPosition sudokuStog) {
	makingPath(maze);
	tilePosition currentTile = maze->firstTile;
	tilePosition nextTile = currentTile;
	char choice = '1';
	int flag = 1;
	while ( flag ) {
		//check if player blocked path
		if (currentTile == NULL) {
			printingMazeUsingMask(maze);
			printf("Important tile blocked, you lost\n");
			break;
		}
		//checking if end is reached
		if (currentTile->end) {
			printf("You won!GG Lets fucking goooooooo\n");
			currentTile->path = 2;
			printingMazeUsingMask(maze);
			break;
		}
		//making it so that current position is better visible
		currentTile->path = 2;
		printingMazeUsingMask(maze);
		currentTile->path = 1;

		//player choice for movement
		printf("Choose direction\n");
		printf("1 - moving up\n");
		printf("2 - moving down\n");
		printf("3 - moving left\n");
		printf("4 - moving right\n");
		printf("0 - stop\n");
		printf("Your choice: ");
		if (!scanf(" %c", &choice)) {
			printf("Choice not registered\n");
			continue;
		}
		if (choice < '0' ||choice > '4') {
			printf("Invalid choice\n");
			continue;
		}
		printf("\n");
		switch (choice) {
		case '1':
			nextTile = up(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		case '2':
			nextTile = down(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		case '3':
			nextTile = left(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		case '4':
			nextTile = right(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		default:
			printf("Forced stop\n");
			flag = 0;
			break;
		}
		
	}
	return 0;
}

int makingPath(Position maze) {
	Position first = maze;
	int isPath[54] = { 0, 5, 10, 11, 12, 13,
					14, 15, 19, 20, 23, 25,
					26, 27, 28, 29, 30, 31,
					34, 35, 36, 39, 40, 43,
					45, 47, 48, 49, 53, 54,
					55, 59, 63, 65, 67, 68,
					70, 71, 72, 73, 74, 75,
					77, 80, 85, 86, 87, 88,
					89, 90, 91, 92, 96, 99 };
	int crucialPath[18] = { 10, 11, 12, 13,	14, 15,	
							25, 35, 45, 55, 65, 75,
							85, 86, 87, 88, 89, 99 };
	int i = 0, j = 0;
	while (maze != NULL) {
		tilePosition tiles = maze->firstTile;
		while (tiles != NULL) {
			if (tiles->placement == isPath[i]) {
				tiles->path = 1;
				if (isPath[i] == crucialPath[j]) {
					tiles->isImportant = 1;
					j++;
				}
				i++;
			}
			tiles = tiles->nextTile;
		}
		maze = maze->next;
	}
	return 0;
}

tilePosition up(Position mazeHead, tilePosition currentTile) {
	if (currentTile->row == 0) {
		printf("Cant go up anymore\n");
		return currentTile;
	}
	else {
		tilePosition newPosition;
		Position maze = mazeHead;
		while (maze->next->depth != currentTile->row) {
			maze = maze->next;
		}
		newPosition = maze->firstTile;
		while (newPosition->column != currentTile->column) {
			newPosition = newPosition->nextTile;
		}
		return newPosition;
	}
}

tilePosition down(Position mazeHead, tilePosition currentTile) {
	if (currentTile->row == TILE - 1) {
		printf("Cant go down anymore\n");
		return currentTile;
	}
	else {
		tilePosition newPosition;
		Position maze = mazeHead;
		while (maze->depth != currentTile->row) {
			maze = maze->next;
		}
		maze = maze->next;
		newPosition = maze->firstTile;
		while (newPosition->column != currentTile->column) {
			newPosition = newPosition->nextTile;
		}
		return newPosition;
	}
}

tilePosition left(Position mazeHead, tilePosition currentTile) {
	if (currentTile->column == 0) {
		printf("Cant go left anymore\n");
		return currentTile;
	}
	else {
		tilePosition newPosition;
		Position maze = mazeHead;
		while (maze->depth != currentTile->row) {
			maze = maze->next;
		}
		newPosition = maze->firstTile;
		while (newPosition->nextTile->column != currentTile->column) {
			newPosition = newPosition->nextTile;
		}
		return newPosition;
	}
}

tilePosition right(Position mazeHead, tilePosition currentTile) {
	if (currentTile->column == TILE - 1) {
		printf("Cant go right anymore\n");
		return currentTile;
	}
	else {
		tilePosition newPosition;
		Position maze = mazeHead;
		while (maze->depth != currentTile->row) {
			maze = maze->next;
		}
		newPosition = maze->firstTile;
		while (newPosition->column != currentTile->nextTile->column) {
			newPosition = newPosition->nextTile;
		}
		return newPosition;
	}
}

tilePosition tileMover(tilePosition nextTile, tilePosition currentTile, sPosition ticTacToeStog, sPosition sudokuStog) {
	if (nextTile == NULL) {
		return currentTile;
	}
	else {
		int result;
		if (nextTile->mask == 0) {
			printf("First unlock that tile\n");
			result = callingGame(ticTacToeStog, sudokuStog);
			if (result == 1 || result == -1) {
				printf("Tile unlocked\n");
				nextTile->mask = 1;
				return currentTile;
			}
			else {
				printf("Mini game not solved: cant unlock this tile anymore\n");
				nextTile->mask = 2;
				if (nextTile->isImportant) {
					return NULL;
				}
				else {
					return currentTile;
				}
			}
		}
		else if (nextTile->mask == 2) {
			printf("Cant unlock this tile\n");
			return currentTile;
		}
		else {
			if (nextTile->path == 1) {
				return nextTile;
			}
			else {
				printf("That is a wall\n");
				return currentTile;
			}
		}
	}
}

int callingGame(sPosition tictactoeStog, sPosition sudokuStog) {
	int random = randomNumberGenerator(2), result, sudokuRandom = randomNumberGenerator(8) + 1;
	if (random) {
		result = ticTacToe(tictactoeStog);
		resettingValue(tictactoeStog);
	}
	else {
		switch (sudokuRandom) {
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
		result = sudoku(sudokuStog);
	}
	return result;
}