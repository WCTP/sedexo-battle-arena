/*		Author: Adam DeCosta, Jimmy Griffiths, Walter Proulx
 *		Class : CSI-120-06
 *		Assignment : Final Project
 * 		Date Assigned : April 14, 2017
 * 		Due Date : April 28, 2017
 *	
 *		Description :
 *			A text-based game that shows everything that was learned so far this semester.
 *			Everything includin dynamic arrays, polymorphism, linked lists, classes, structs,
 *			and inheritance will be included. The game has a Sedexo theme where the player
 *			must get past all the obstacles to win.
 *	
 *		Certification of Authenticity :
 *			I certify that this is entirely my own work, except where I have given fully 
 *			documented references to the work of others. I understand the definition and
 *			consequences of plagiarism and acknowledge that the assessor of this assignment
 *			may, for the purpose of assessing this assignment :
 *			-	Reproduce this assignment and provide a copy to another member of
 *				academic staff; and / or
 *			-	Communicate a copy of this assignment to a plagiarism checking service
 *				(which may then retain a copy of this assignment on its database for
 *				the purpose of future plagiarism checking)
 *
 ***********************************************************************************************/

#include "rest_operations.h"
#include "battle_operations.h"

/*		Pre: none
 *	   Post: none
 *	Purpose: explores room based off of random variables
 *********************************************************/
void explore()
{
	/* needs to be written */
}

/*		Pre: none
 *	   Post: none
 *	Purpose: displays rest menu and gets input
 *********************************************************/
int restMenu()
{
	int input;

	system("cls");

	cout	<< "--------------------------------------------" << endl
			<< "-- REST MENU                              --" << endl
			<< "--------------------------------------------" << endl
			<< "-- 1.) Explore                            --" << endl
			<< "-- 2.) Battle                             --" << endl
			<< "--------------------------------------------" << endl
			<< "  Command: ";

	cin >> input;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return input;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: executes command based on input
 *********************************************************/
void restOperations()
{
	int input = 1;

	do
	{
		input = restMenu();

		switch (input)
		{
			case EXPLORE : 
				explore();
				break;
			case BATTLE :
				battleOperations();
				break;
			default :
				cout << "INVALID COMMAND";
		}

	} while (input < ITEMS && input > ATTACK);
}