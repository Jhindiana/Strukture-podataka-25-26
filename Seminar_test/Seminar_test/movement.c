#include "header.h"
int movement(Position maze, sPosition ticTacToeStog, sPosition sudokuStog) {
	tilePosition currentTile = maze->firstTile;
	tilePosition nextTile = currentTile;
	int choice = 1;
	while (choice) {
		currentTile->test = 5;
		printingMAzeUsingMask(maze);
		currentTile->test = 4;
		printf("Choose direction\n");
		printf("1 - moving up\n");
		printf("2 - moving down\n");
		printf("3 - moving left\n");
		printf("4 - moving right\n");
		printf("0 - stop\n");
		printf("Your choice: ");
		if (!scanf("%d", &choice)) {
			printf("Choice not registered\n");
			continue;
		}
		if (choice > 4 || 0 > choice) {
			printf("Invalid choice\n");
			continue;
		}
		switch (choice) {
		case 1:
			nextTile = up(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		case 2:
			nextTile = down(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		case 3:
			nextTile = left(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		case 4:
			nextTile = right(maze, currentTile);
			currentTile = tileMover(nextTile, currentTile, ticTacToeStog, sudokuStog);
			break;
		default:
			printf("Pozvan default u movement\n");
			break;
		}
		
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
			result = callingGame(ticTacToeStog, sudokuStog);
			if (result == 1 || result == -1) {
				printf("Tile unlocked\n");
				nextTile->mask = 1;
				return nextTile;
			}
			else {
				printf("Mini game not solved: cant unlock this tile anymore\n");
				nextTile->mask = 2;
				return currentTile;
			}
		}
		else if (nextTile->mask == 2) {
			printf("Cant unlock this tile\n");
			return currentTile;
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