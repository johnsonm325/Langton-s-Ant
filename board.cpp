/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: This file holds the definitions for the board class functions. In this program
**				when an ant hits a wall, the ant does an about face and reacts to the space based on
**				the new direction it's facing.
***************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Board.h"

using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**										Board Constructor
**		Sets up the number of rows, columns and turns for the game and dynamically allocates
**							         memory for the 2D array
****************************************************************************************************/
Board::Board()
{
		cout << "Enter the number of rows and columns for the board." << endl;
		cout << endl;
		cout << "Enter numbers between 3 and 80." << endl;
		
		do
		{
			cout << "How many rows would you like?" << endl;
			// Sets numRows variable equal to the integer passed from input validation class
			numRows = inputValid1.isPosInteger();
		} while (numRows < 3 || numRows > 80);

		cout << endl;

		do
		{
			cout << "How many columns would you like?" << endl;
			numCols = inputValid1.isPosInteger();
		} while (numCols < 3 || numCols > 80);

		cout << endl;

		//Dynamically allocate space for the 2D array
		board = new char*[numRows];
		for (int count = 0; count < numRows; count++)
		{
			board[count] = new char[numCols];
		}
		
		do
		{
			cout << "How many turns would you like to see?" << endl;
			cout << "Choose a number between 1 and 500." << endl;
			numOfTurns = inputValid1.isPosInteger();
		} while (numOfTurns < 1 || numOfTurns > 500);
		
			cout << endl;
}

/*****************************************************************************************************
**										setBoard function
**					Initializes each cell of the 2D array to an empty character
*****************************************************************************************************/
void Board::setBoard()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			board[row][col] = ' ';
		}
	}
}

/******************************************************************************************************
**										printBoard function
**					clears the screen and then prints the board with current values
******************************************************************************************************/
void Board::printBoard()
{
	system("cls");
	for (int row = 0; row < numRows; row++)
	{
		for (int cols = 0; cols < numCols; cols++)
		{
			cout << board[row][cols] << "|";
		}
		cout << endl;
	}
	cout << endl;
	
	// Prints the direction the ant is currently facing
	cout << "Ant is facing " << ant1.getAntFacingDirection() << endl;
	// Prints the turn number
	cout << "Turn number: " << turnNumber + 1 << endl;
	cin.get();
}


/***************************************************************************************************
**										placeAnt function
**				Places the ant on the board based on menu choice by user
***************************************************************************************************/
void Board::placeAnt(int choice)
{
	// Predefined position, which is in the middle of the board
	if (choice == 1)
	{
		ant1.setDefaultAnt(numRows, numCols);
	}
	
	// User chooses starting point
	else if (choice == 2)
	{
		ant1.setAnt(numRows, numCols);
	}

	// Random starting position
	else if (choice == 3)
	{
		ant1.setRandomAnt(numRows, numCols);
	}
	
	// Place '@' - ant - on coordinates
	board[ant1.getXCoord()][ant1.getYCoord()] = '@';

	printBoard();
}

/******************************************************************************************************
**										makeMove function
**			Calls functions to move ant based on direction the ant is facing and the color
**							of the space the ant is currently occupying
******************************************************************************************************/
void Board::makeMove()
{
	// Loops through turns and makes moves based on criteria
	for (turnNumber = 0; turnNumber < numOfTurns; turnNumber++)
	{
		// If the next space (space ant currently occupies) is white (' ')
		if (nextSpace == ' ')
		{
			// Calls function based on the direction the ant is facing
			if (ant1.getAntFacingDirection() == 's')
			{
				antFacingSouth();
			}
			
			else if (ant1.getAntFacingDirection() == 'e')
			{
				antFacingEast();
			}

			else if (ant1.getAntFacingDirection() == 'n')
			{
				antFacingNorth();
			}

			else if (ant1.getAntFacingDirection() == 'w')
			{
				antFacingWest();
			}
		}

		// If the space the ant is occupying is black ('#')
		else
		{
			if (ant1.getAntFacingDirection() == 's')
			{
				antFacingSouth();
			}

			else if (ant1.getAntFacingDirection() == 'e')
			{
				antFacingEast();
			}

			else if (ant1.getAntFacingDirection() == 'n')
			{
				antFacingNorth();
			}

			else if (ant1.getAntFacingDirection() == 'w')
			{
				antFacingWest();
			}
		}
	}
	
	// Deallocates the 2D array memory
	deallocateMem();
}

/***************************************************************************************************
**								         outOfBoundary function
**				Function for determining if the ant is out of the bounds of the board
***************************************************************************************************/
bool Board::outOfBoundary()
{
	// If the coordinates of the ant are not greater or less than the number of rows or columns, it returns true
	// and the ant is considered in bounds
	if ((ant1.getXCoord() < numRows && ant1.getYCoord() < numCols) && (ant1.getXCoord() >= 0 && ant1.getYCoord() >= 0))
	{
		return true;
	}

	return false;
}


/***************************************************************************************************
**									   antFacingEast function
**			Function that determines what the ant does when turning east from previous space.
***************************************************************************************************/
void Board::antFacingEast()
{
	// If the current space is white
	if (nextSpace == ' ')
	{
		// The space that the ant is currently occupying becomes black
		board[ant1.getXCoord()][ant1.getYCoord()] = '#';
		// Call the ant class function to make the ant take a right and move south
		ant1.moveAntSouth();
		// If the ant is not out of the boundary
		if (outOfBoundary())
		{
			// Sets nextSpace variable to the same value of the space that the ant was
			// previously occupying
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			// Sets the space that the ant is currently occupying to '@'
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}
		
		else
		{
			// If the ant is not out of the boundary, move the ant coordinates, to the previously occupied space
			ant1.moveAntNorth();
			// Sets the space that the ant is currently occupying to '@'
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			// Because the ant is going to hit a wall, we will do an about face and call the function to react
			// to the white space based on a new facing position of west
			antFacingWest();
		}
	}
	
	// If the space the ant is currently occupying is black
	else
	{
		// Using the same algorithms, but it's flipped because the space currently occupied is black
		
		board[ant1.getXCoord()][ant1.getYCoord()] = ' ';
		ant1.moveAntNorth();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}

		else
		{
			ant1.moveAntSouth();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingWest();
		}
	}
}


/***************************************************************************************************
**										antFacingWest function
**			Function that determines what the ant does when turning west from previous space.
**							Function algorithm description is in antFacingEast
***************************************************************************************************/
void Board::antFacingWest()
{
	if (nextSpace == ' ')
	{
		board[ant1.getXCoord()][ant1.getYCoord()] = '#';
		ant1.moveAntNorth();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}

		else
		{
			ant1.moveAntSouth();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingEast();
		}
	}

	else
	{
		board[ant1.getXCoord()][ant1.getYCoord()] = ' ';
		ant1.moveAntSouth();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}

		else
		{
			ant1.moveAntNorth();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingEast();
		}
	}
}


/***************************************************************************************************
**										antFacingSouth function
**			Function that determines what the ant does when turning south from previous space.
**							Function algorithm description is in antFacingEast
***************************************************************************************************/
void Board::antFacingSouth()
{
	if (nextSpace == ' ')
	{
		board[ant1.getXCoord()][ant1.getYCoord()] = '#';
		ant1.moveAntWest();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}

		else
		{
			ant1.moveAntEast();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingNorth();
		}
	}

	else
	{
		board[ant1.getXCoord()][ant1.getYCoord()] = ' ';
		ant1.moveAntEast();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}
		else
		{
			ant1.moveAntWest();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingNorth();
		}
	}
}


/***************************************************************************************************
**										antFacingNorth function
**			Function that determines what the ant does when turning north from previous space.
**							Function algorithm description is in antFacingEast
***************************************************************************************************/
void Board::antFacingNorth()
{
	if (nextSpace == ' ')
	{
		board[ant1.getXCoord()][ant1.getYCoord()] = '#';
		ant1.moveAntEast();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}

		else
		{
			ant1.moveAntWest();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingSouth();
		}
	}

	else
	{
		board[ant1.getXCoord()][ant1.getYCoord()] = ' ';
		ant1.moveAntWest();
		if (outOfBoundary())
		{
			nextSpace = board[ant1.getXCoord()][ant1.getYCoord()];
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			printBoard();
		}

		else
		{
			ant1.moveAntEast();
			board[ant1.getXCoord()][ant1.getYCoord()] = '@';
			antFacingSouth();
		}
	}
}


/***************************************************************************************************
**										deallocateMem function
**								Deallocates the memory of the 2D array
***************************************************************************************************/
void Board::deallocateMem()
{
	for (int count = 0; count < numRows; count++)
	{
		delete[] board[count];
	}
	delete[] board;
}
