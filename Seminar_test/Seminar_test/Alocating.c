#include "header.h"
//makes rows for maze
Position mazeDepth(int i) {
	Position mD = (Position)malloc(sizeof(maze));
	if (!mD) {
		printf("Greska u alokaciji u mazeDepth\n");
		return NULL;
	}
	mD->firstTile = newTile();
	mD->depth = i;
	mD->next = NULL;
	return mD;
}

//makes new tile in maze
tilePosition newTile() {
	tilePosition nT = (tilePosition)malloc(sizeof(tile));
	if (!nT) {
		printf("Greska u alokaciji u newTile\n");
		return NULL;
	}
	nT->nextTile = NULL;
	return nT;
}

//makes rows for mini games
sPosition newStog(int x) {
	sPosition nS = (sPosition)malloc(sizeof(miniGameStog));
	if (!nS) {
		printf("Greska pri alokaciji u newStog\n");
		return NULL;
	}
	nS->depth_mgs = x;
	nS->firstMGT = newMGT();
	nS->nextStog = NULL;
	return nS;
}

//makes cells for mini games
mgtPosition newMGT() {
	mgtPosition nMGT = (mgtPosition)malloc(sizeof(miniGameTile));
	if (!nMGT) {
		printf("Greska pri akolaciji u newTTT\n");
		return NULL;
	}
	nMGT->brother = NULL;
	nMGT->symbol = 0;
	return nMGT;
}

//freeing maze memory
int freeingPositionMemory(Position maze) {
	while (maze->next != NULL) {
		Position del = maze->next;
		freeingTilePositionMemory(del->firstTile);
		maze->next = del->next;
		del->next = NULL;
		free(del);
	}
	return 0;
}

//freeing maze tile memory
int freeingTilePositionMemory(tilePosition mazeTile) {
	while (mazeTile != NULL) {
		tilePosition del = mazeTile;
		mazeTile = del->nextTile;
		free(del);
	}
	return 0;
}

//freeing tic tac toe and sudoku memory
int freeingSPositionMemory(sPosition miniGameStog) {
	while (miniGameStog->nextStog != NULL) {
		sPosition del = miniGameStog->nextStog;
		freeingMGTPositionMemory(del->firstMGT);
		miniGameStog->nextStog = del->nextStog;
		del->nextStog = NULL;
		free(del);
	}
	return 0;
}

//freeing tic tac toe and sudoku tiles memory
int freeingMGTPositionMemory(mgtPosition mgtTile) {
	while (mgtTile != NULL) {
		mgtPosition del = mgtTile;
		mgtTile = del->brother;
		free(del);
	}
	return 0;
}