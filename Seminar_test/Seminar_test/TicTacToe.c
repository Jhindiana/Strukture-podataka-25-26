#include "header.h"
int ticTacToe(sPosition ttt) {
	int availableSpots = 9;
	int playerChoice, playerRow, playerColumn;
	int haveAWinner = 0;
	while (availableSpots > 0) {
		//players plays
		printf("Broj mista %d\n", availableSpots);
		printingTicTacToe(ttt);
		printf("\n");
		printingTicTacToeRowsAndColumns(ttt);
		printf("Choose row: ");
		scanf("%d", &playerChoice);
		playerRow = playerChoice;
		if (playerRow < 0 || playerRow > 2) {
			printf("Wrong choice\n");
			continue;
		}
		printf("Choose column: ");
		scanf("%d", &playerChoice);
		playerColumn = playerChoice;
		if (playerColumn < 0 || playerColumn > 2) {
			printf("Wrong choice\n");
			continue;
		}
		if (applyingChoice(ttt, playerRow, playerColumn) == 0) {
			printf("Spot already taken\n");
			continue;
		}
		//checking if player won before letting computer play or if its tied
		if (scoreCalculation(ttt, availableSpots)) {
			break;
		}
		//computer playing
		availableSpots--;
		if (availableSpots > 1) {
			computerMovesTTT(ttt, haveAWinner);
		}
		//check if computer won after his move
		if (scoreCalculation(ttt, availableSpots)) {
			break;
		}
		availableSpots --;
	}
	return 0;
}

int applyingChoice(sPosition ttt, int pR, int pC) {
	while (ttt->depth_mgs != pR) {
		ttt = ttt->nextStog;
	}
	mgtPosition selectedRow = ttt->firstMGT;
	while (selectedRow->column != pC) {
		selectedRow = selectedRow->brother;
	}
	if (selectedRow->symbol == 0) {
		selectedRow->symbol = 1;
		return 1;
	}
	return 0;
}

int computerMovesTTT(sPosition ttt, int winner) {
	if (winner) {
		return 0;
	}
	sPosition startingPoint;
	mgtPosition computerSpot;
	int cR, cC, availableSpot = 0;
	while (!availableSpot) {
		startingPoint = ttt;
		cR = randomNumberGenerator(3);
		cC = randomNumberGenerator(3);
		while (startingPoint->depth_mgs != cR) {
			startingPoint = startingPoint->nextStog;
		}
		computerSpot = startingPoint->firstMGT;
		while (computerSpot->column != cC) {
			computerSpot = computerSpot->brother;
		}
		if (computerSpot->symbol == 0) {
			computerSpot->symbol = 2;
			availableSpot++;
		}
	}
	return 1;
}

int calculatingScoreTTT(sPosition ttt, int availableSpaces) {
	if (availableSpaces == 0) {
		//additional call to check when all spots are filled
		if (calculatingScoreTTT(ttt, 1)) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else {
		sPosition tttStart = ttt;
		mgtPosition rowCheck;
		mgtPosition columnCheckOne, columnCheckTwo, columnCheckThree;
		mgtPosition diagonalCheckOne, diagonalCheckTwo, diagonalCheckThree;
		int currentRowScore = 1;
		int currentColumnScore;
		int diagonalScore;
		int playerWin = 0, computerWin = 0;

		//checking rows
		while (tttStart != NULL) {
			rowCheck = tttStart->firstMGT;
			while (rowCheck != NULL) {
				currentRowScore *= rowCheck->symbol;
				rowCheck = rowCheck->brother;
			}
			if (currentRowScore == 1) {
				playerWin++;
				break;
			}
			else if (currentRowScore == 8) {
				computerWin++;
				break;
			}
			currentRowScore = 1;
			tttStart = tttStart->nextStog;
		}

		//checking columns
		columnCheckOne = ttt->firstMGT;
		columnCheckTwo = ttt->nextStog->firstMGT;
		columnCheckThree = ttt->nextStog->nextStog->firstMGT;
		while (columnCheckOne != NULL) {
			currentColumnScore = columnCheckOne->symbol * columnCheckTwo->symbol * columnCheckThree->symbol;
			if (currentColumnScore == 1) {
				playerWin++;
				break;
			}
			else if (currentColumnScore == 8) {
				computerWin++;
				break;
			}
			columnCheckOne = columnCheckOne->brother;
			columnCheckTwo = columnCheckTwo->brother;
			columnCheckThree = columnCheckThree->brother;
		}
		//checking diagonals
		diagonalCheckOne = ttt->firstMGT;
		diagonalCheckTwo = ttt->nextStog->firstMGT->brother;
		diagonalCheckThree = ttt->nextStog->nextStog->firstMGT->brother->brother;
		diagonalScore = diagonalCheckOne->symbol * diagonalCheckTwo->symbol * diagonalCheckThree->symbol;
		if (diagonalScore == 1) {
			playerWin++;
		}
		else if (diagonalScore == 8) {
			computerWin++;
		}
		diagonalCheckOne = ttt->firstMGT->brother->brother;
		diagonalCheckTwo = ttt->nextStog->firstMGT->brother;
		diagonalCheckThree = ttt->nextStog->nextStog->firstMGT;
		diagonalScore = diagonalCheckOne->symbol * diagonalCheckTwo->symbol * diagonalCheckThree->symbol;
		if (diagonalScore == 1) {
			playerWin++;
		}
		else if (diagonalScore == 8) {
			computerWin++;
		}
		if (playerWin) {
			return 1;
		}
		else if (computerWin) {
			return 3;
		}
		else {
			return 0;
		}
	}
}

int scoreCalculation(sPosition ttt, int availableSpots) {
	int score, haveAWinner = 0;
	score = calculatingScoreTTT(ttt, availableSpots);
	if (score == 1) {
		haveAWinner++;
		printingTicTacToe(ttt);
		printf("Player wins\n");
		return 1;
	}
	else if (score == 2) {
		printingTicTacToe(ttt);
		printf("Tie\n");
		return 1;
	}
	else if (score == 3) {
		printingTicTacToe(ttt);
		printf("Computer won\n");
		return 1;
	}
	else {
		return 0;
	}
}