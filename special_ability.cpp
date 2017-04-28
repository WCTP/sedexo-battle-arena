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

#include "special_ability.h"


/*		Pre: none
 *	   Post: none
 *	Purpose: default constructor
 *********************************************************/
SpecialAbility::SpecialAbility()
{
	mName = "";
	mUses = 0;
	mPossess = false;
	mId = 0;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: constructor
 *********************************************************/
SpecialAbility::SpecialAbility(int uses, string name, bool possess)
{
	mUses = uses;
	mName = name;
	mPossess = possess;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: destructor
 *********************************************************/
SpecialAbility::~SpecialAbility()
{
	/* left blank intentionally */
}

/*		Pre: none
 *	   Post: none
 *	Purpose: retrieves name
 *********************************************************/
string SpecialAbility::getName()
{
	return mName;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: retrieves possess
 *********************************************************/
bool SpecialAbility::getPossess()
{
	return mPossess;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: retrieves possess
 *********************************************************/
int SpecialAbility::getUses()
{
	return mUses;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: sets name
 *********************************************************/
void SpecialAbility::setName(string name)
{
	mName = name;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: sets possess
 *********************************************************/
void SpecialAbility::setPossess(bool possess)
{
	mPossess = possess;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: sets uses
 *********************************************************/
void SpecialAbility::setUses(int uses)
{
	mUses = uses;
}
