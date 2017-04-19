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

#include "constants.h"
#include "battle_operations.h"

/*		Pre: none
 *	   Post: none
 *	Purpose: none
 *********************************************************/
void attack()
{
	/* needs to be written */
}

/*		Pre: none
 *	   Post: int
 *	Purpose: shows options in battle and gets input
 *********************************************************/
int battleMenu()
{
	int input;

	system("cls");

	cout	<< "--------------------------------------------" << endl
			<< "-- BATTLE MENU                            --" << endl
			<< "--------------------------------------------" << endl
			<< "-- 1.) Attack                             --" << endl
			<< "-- 2.) Skills                             --" << endl
			<< "-- 3.) Items                              --" << endl
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
void battleOperations()
{
	int input = 1;

	do
	{
		input = battleMenu();

		switch (input)
		{
			case ATTACK : 
				attack();
				break;
			case SKILLS :
				useSkill();
				break;
			case ITEMS :
				useItem();
				break;
			default :
				cout << "INVALID COMMAND";
		}

	} while (input < ITEMS && input > ATTACK);
}

/*		Pre: none
 *	   Post: none
 *	Purpose: none
 *********************************************************/
Entity* initializeBattle()
{
	/* needs to be written */
	Entity* person = NULL;

	return person;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: none
 *********************************************************/
void useItem()
{
	/* needs to be written */
}


/*		Pre: none
 *	   Post: none
 *	Purpose: none
 *********************************************************/
void useSkill()
{
	/* needs to be written */
}