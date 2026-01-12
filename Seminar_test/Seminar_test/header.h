#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TILE 10
#define SUDOKU_SIZE 4
#include "structure.h"

tilePosition newTile();
Position mazeDepth(int);
sPosition newStog(int);
mgtPosition newMGT();

int makingMiniGameTiles(sPosition, int);

int settingValue(Position, sPosition, sPosition);
int settingMGTValue(sPosition);
int resettingValue(sPosition);
int randomNumberGenerator(int);

int printing(Position, sPosition, sPosition);

int printingMaze(Position);
int printingMazeUsingMask(Position);
int printingMazeRowsAndColumns(Position);

int printingTicTacToe(sPosition);
int printingTicTacToeRowsAndColumns(sPosition);

int printingSudoku(sPosition);
int printingSudokuUsingMask(sPosition);
int printingSudokuRowsAndColumns(sPosition);

int ticTacToe(sPosition);
int applyingChoice(sPosition, int, int);
int computerMovesTTT(sPosition, int);
int calculatingScoreTTT(sPosition, int);
int scoreCalculation(sPosition, int);

int sudoku(sPosition);
int applyingSudokuChoice(sPosition, int, int);
int revealedNumbers(sPosition);
int sudokuOne(sPosition);
int sudokuTwo(sPosition);
int sudokuThree(sPosition);
int sudokuFour(sPosition);
int sudokuFive(sPosition);
int sudokuSix(sPosition);
int sudokuSeven(sPosition);
int sudokuEight(sPosition);

int movement(Position, sPosition, sPosition);
int makingPath(Position);
tilePosition up(Position, tilePosition);
tilePosition down(Position, tilePosition);
tilePosition left(Position, tilePosition);
tilePosition right(Position, tilePosition);
tilePosition tileMover(tilePosition, tilePosition, sPosition, sPosition);
int callingGame(sPosition, sPosition);