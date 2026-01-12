#pragma once
#include "header.h"

typedef struct tile* tilePosition;
typedef struct tile {
	int row;
	int column;
	int mask;
	int path;
	int placement;
	int isImportant;
	int end;
	tilePosition nextTile;
}tile;

typedef struct maze* Position;
typedef struct maze {
	int depth;
	Position next;
	tilePosition firstTile;
}maze;

typedef struct miniGameTile* mgtPosition;
typedef struct miniGameTile {
	int column;
	int row;
	int mask;
	int symbol;
	mgtPosition brother;
}miniGameTile;

typedef struct miniGameStog* sPosition;
typedef struct miniGameStog {
	int depth_mgs;
	sPosition nextStog;
	mgtPosition firstMGT;
}miniGameStog;