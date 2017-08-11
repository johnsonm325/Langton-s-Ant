/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: Header for Ant class
***************************************************************************************************/

#ifndef ANT_H
#define ANT_H

#include "inputValidation.h"

class Ant
{

private:
	char ant,						// Variable for representation of the ant
		 antFacingDirection = 's';	// Variable for the starting direction of the ant
	int  xInput = 0,				// Variable to hold the row coordinate entered by user
		 yInput = 0,				// Variable to hold the column coordinate entered by user
		 xCoord = 0,				// Variable to hold the current row coordinate
		 yCoord = 0;				// Variable to hold the current column coordinate
	InputValid inputVal1;			// Input validation object

public:
	Ant();
	int getXCoord();
	int getYCoord();
	void setAnt(int, int);
	void setDefaultAnt(int, int);
	void setRandomAnt(int, int);
	char getAntFacingDirection();
	void moveAntWest();
	void moveAntSouth();
	void moveAntEast();
	void moveAntNorth();	
};


#endif