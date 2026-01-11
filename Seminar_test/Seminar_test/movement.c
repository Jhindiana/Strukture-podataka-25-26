#include "header.h"
int movement(Position maze) {
	tilePosition currentTile = maze->next->firstTile;
	int choice = 1;
	while (choice) {
		printf("Choose direction\n");
		printf("1 - moving up\n");
		printf("2 - moving down\n");
		printf("3 - moving left\n");
		printf("4 - moving right\n");
		printf("0 - stop\n");
		printf("Your choice: ");
		if (!scanf("%d", &choice)) {
			printf("Choice not registered\n");
		}
		if (choice > 4 || 0 > choice) {
			printf("Invalid choice\n");
			continue;
		}
		switch (choice) {
		case 1:
			currentTile = up(maze->next, currentTile);
			printingMaze(maze->next);
			break;
		case 2:
			currentTile = down(maze->next, currentTile);
			printingMaze(maze->next);
			break;
		case 3:
			currentTile = left(maze->next, currentTile);
			printingMaze(maze->next);
			break;
		case 4:
			currentTile = right(maze->next, currentTile);
			printingMaze(maze->next);
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
		currentTile->test += 1;
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
		newPosition->test += 1;
		return newPosition;
	}
}

tilePosition down(Position mazeHead, tilePosition currentTile) {
	if (currentTile->row == TILE - 1) {
		printf("Cant go down anymore\n");
		currentTile->test += 1;
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
		if (newPosition == NULL) {
			printf("Cant go down anymore\n");
			return currentTile;
		}
		newPosition->test += 1;
		return newPosition;
	}
}

tilePosition left(Position mazeHead, tilePosition currentTile) {
	if (currentTile->column == 0) {
		printf("Cant go left anymore\n");
		currentTile->test += 1;
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
		newPosition->test += 1;
		if (newPosition == NULL) {
			printf("Cant go left anymore\n");
			return currentTile;
		}
		return newPosition;
	}
}

tilePosition right(Position mazeHead, tilePosition currentTile) {
	if (currentTile->column == TILE - 1) {
		printf("Cant go right anymore\n");
		currentTile->test += 1;
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
		newPosition->test += 1;
		if (newPosition == NULL) {
			printf("Cant go right anymore\n");
			return currentTile;
		}
		return newPosition;
	}
}