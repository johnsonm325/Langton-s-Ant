/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: Definitions for Ant class functions
***************************************************************************************************/

#include <iostream>
#include "Ant.h"

using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**										Ant class Constructor
**									  Sets the ant equal to '@'
****************************************************************************************************/
Ant::Ant()
{
	ant = '@';
}

/***************************************************************************************************
**										getXCoord function
**								Returns the current value of xCoord
***************************************************************************************************/
int Ant::getXCoord()
{
	return xCoord;
}

/***************************************************************************************************
**										getYCoord function
**								Returns the current value of yCoord
***************************************************************************************************/
int Ant::getYCoord()
{
	return yCoord;
}

/***************************************************************************************************
**										  setAnt function
**					User chooses starting point for the ant if they choose menu 2
***************************************************************************************************/
void Ant::setAnt(int rows, int cols)
{
	cout << "Enter a starting point for the ant:" << endl;
	
	do
	{
		cout << "Enter a row number:" << endl;
		xInput = inputVal1.isPosInteger();
	} while (xInput < 1 || xInput > rows);

	// Sets starting x coordinate of ant to user input -1
	xCoord = xInput - 1;

	cout << endl;
	
	do
	{
		cout << "Enter a column number:" << endl;
		yInput = inputVal1.isPosInteger();
	} while (yInput < 1 || yInput > cols);

	// Sets starting y coordinate of ant to user input -1
	yCoord = yInput - 1;

	cout << endl;
}


/***************************************************************************************************
**									  setDefaultAnt function
**			Sets a default starting point at the center for the ant if they choose menu 1
***************************************************************************************************/
void Ant::setDefaultAnt(int rows, int cols)
{
	xCoord = rows / 2;
	yCoord = cols / 2;

	cout << endl;
}


/***************************************************************************************************
**										  setRandomAnt function
**					Sets a random starting point for the ant if they choose menu 3
***************************************************************************************************/
void Ant::setRandomAnt(int rows, int cols)
{
	xInput = rand() % rows + 1;
	xCoord = xInput - 1;

	yInput = rand() % cols + 1;
	yCoord = yInput - 1;

	cout << endl;
}

/******************************************************************************************************
**									 getAntFacingDirection function
**							Returns the direction that the ant is facing
******************************************************************************************************/
char Ant::getAntFacingDirection()
{
	return antFacingDirection;
}

/******************************************************************************************************
**										 moveAntWest function
**						Moves the ant west and sets facing direction to west
******************************************************************************************************/
void Ant::moveAntWest()
{
	yCoord -= 1;
	antFacingDirection = 'w';
}

/******************************************************************************************************
**										 moveAntSouth function
**						Moves the ant south and sets facing direction to south
******************************************************************************************************/
void Ant::moveAntSouth()
{
	xCoord += 1;
	antFacingDirection = 's';
}

/******************************************************************************************************
**										 moveAntEast function
**						Moves the ant east and sets facing direction to east
******************************************************************************************************/
void Ant::moveAntEast()
{
	yCoord += 1;
	antFacingDirection = 'e';
}

/******************************************************************************************************
**										 moveAntNorth function
**						Moves the ant north and sets facing direction to north
******************************************************************************************************/
void Ant::moveAntNorth()
{
	xCoord -= 1;
	antFacingDirection = 'n';
}