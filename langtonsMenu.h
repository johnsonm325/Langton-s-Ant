/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/9/2017
** Description: Header file for the Menu class
***************************************************************************************************/

#ifndef LANGTONSMENU_H
#define LANGTONSMENU_H

#include "inputValidation.h"
#include <string>

class Menu
{
	private:
		int		   choice;		// Variable for the menu choice of the user
		InputValid inputVal1;	// Input validation class object

	public:
		void displayMenu();
		void setChoice();
		int getChoice();

};

#endif