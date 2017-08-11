/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "langtonsMenu.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**                                         displayMenu
**                       Displays the menu of game options on the screen.
**                        I pulled this function idea from the textbook.
****************************************************************************************************/
void Menu::displayMenu()
{
	system("cls");
	
	cout << "\n Langton's Ant" << endl;
	cout << "1.  Play with a predefined ant position." << endl;
	cout << "2.  Choose your own starting position." << endl;
	cout << "3.  Play with a random ant position." << endl;
	cout << "4.  Quit game" << endl;
}


/****************************************************************************************************
**                                          setChoice
**                              Sets the menu choice from the user
****************************************************************************************************/
void Menu::setChoice()
{
	cout << "Choose an option: " << endl;
	choice = inputVal1.isPosInteger();

	while (choice > 4 || choice < 1)
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	}
}


/****************************************************************************************************
**                                          getChoice
**                       Gets the menu choice from the user and returns it
****************************************************************************************************/
int Menu::getChoice()
{
	return choice;
}