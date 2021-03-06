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

#include "item.h"


/*		Pre: none
 *	   Post: none
 *	Purpose: default constructor
 *********************************************************/
Item::Item() : SpecialAbility()
{
	mHealMod = 0;
}

Item::Item(int id)
{
	if (id == WATER)
	{
		mId = id;
		mUses = 10;
		mName = "Water";
		mPossess = true;
		mHealMod = 10;
	}

	else if (id == COFFEE)
	{
		mId = id;
		mUses = 5;
		mName = "Coffee";
		mPossess = true;
		mHealMod = 20;
	}

	else if (id == APPLE_JUICE)
	{
		mId = id;
		mUses = 2;
		mName = "Apple Juice";
		mPossess = true;
		mHealMod = 50;
	}
}

/*		Pre: none
 *	   Post: none
 *	Purpose: destructor
 *********************************************************/
Item::~Item()
{
	/* left blank intentionally */
}

/*
pre: an int of the new heal modifier
post: the heal modifier of the object will change
purpose: to change the heal modifier of an Item object
*/
void Item::setHealMod(int newHealMod)
{
	mHealMod = newHealMod;
}

/*
pre: an Item object must be instantiated
post: an int containing the heal modifier of the object will be returned
purpose: to obtain the int containing the heal modifier of the object
*/
int Item::getHealMod()
{
	return mHealMod;
}

void Item::useItem(int &health)
{
	health += mHealMod;
	mUses--;
}