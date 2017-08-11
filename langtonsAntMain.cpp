/****************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: This is the main function for Langton's Ant
****************************************************************************************************/

#include <iostream>
#include "Board.h"
#include "langtonsMenu.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Menu menu1;		// Menu class object
	
	while (menu1.getChoice() != 4)
	{
		menu1.displayMenu();
		menu1.setChoice();
		
		// Exits the program
		if (menu1.getChoice() == 4)
		{
			return 0;
		}

		// Clears the screen
		system("cls");
		
		Board board1;	// Board class object

		board1.setBoard();
		board1.placeAnt(menu1.getChoice());
		board1.makeMove();
		
		cout << "Thank you for Playing!" << endl;

		cin.get();

	}
}