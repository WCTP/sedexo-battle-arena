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

#include "monster.h"


/*		Pre: none
 *	   Post: none
 *	Purpose: default constructor
 *********************************************************/
Monster::Monster() : Entity()
{
	mExpAwarded = 0;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: constructor
 *********************************************************/
Monster::Monster(string name, int health, int maxHealth, int speed, int attack, int defense, int expAwarded)
{
	mName = name;
	mHealth = health;
	mMaxHealth = maxHealth;
	mSpeed = speed;
	mAttack = attack;
	mDefense = defense;
	mExpAwarded = expAwarded;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: destructor
 *********************************************************/
Monster::~Monster()
{
	/* left blank intentionally */
}

/*		Pre: none
 *	   Post: int
 *	Purpose: retrieves expAwarded
 *********************************************************/
int Monster::getExpAwarded()
{
	return mExpAwarded;
}

/*		Pre: int
 *	   Post: none
 *	Purpose: sets expAwarded
 *********************************************************/
void Monster::setExpAwarded(int expAwarded)
{
	mExpAwarded = expAwarded;
}