/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: Header for Board class
***************************************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include "Ant.h"
#include "inputValidation.h"
#include "langtonsMenu.h"

class Board
{
private:
	char** board,			// 2D array of pointers to pointers
		   nextSpace = ' ';	// Holds the character value of the next space the ant will occupy
	int	   numRows = 0,		// Holds the number of rows in the board
		   numCols = 0,		// Holds the number of columns in the board
		   numOfTurns = 0,	// Holds the number of turns requested by the user
		   turnNumber = 0;	// Holds the turn number to display to the user
	Ant	   ant1;		// Object for the ant class
	InputValid inputValid1;		// Object for input validation class
	Menu menu1;			// Object for menu class

public:
	Board();
	void setBoard();
	void printBoard();
	void makeMove();
	void placeAnt(int);
	bool outOfBoundary();
	void antFacingEast();
	void antFacingWest();
	void antFacingSouth();
	void antFacingNorth();
	void deallocateMem();
};

#endif
