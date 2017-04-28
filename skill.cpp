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

#include "skill.h"


/*		Pre: none
 *	   Post: none
 *	Purpose: default constructor
 *********************************************************/
Skill::Skill() : SpecialAbility()
{
	mDamageMod = 0;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: destructor
 *********************************************************/
Skill::~Skill()
{
	/* left blank intentionally */
}

/*
Skill
pre: an int pertaining to some id
post: a Skill will be created based on the given id
purpose: to create a skill based on some id given to the object
*/
Skill::Skill(int id)
{
	if (id == COOK)
	{
		mId = id;
		mUses = 5;
		mName = "Cook";
		mPossess = false;
		mDamageMod = 2;

	}

	else if (id == THROW_FORK)
	{
		mId = id;
		mUses = 3;
		mName = "Throw Fork";
		mPossess = false;
		mDamageMod = 3;

	}

	else if (id == WASH_DISHES)
	{
		mId = id;
		mUses = 2;
		mName = "Wash Dishes";
		mPossess = false;
		mDamageMod = 4;

	}

	else
	{
		Skill();
	}
}

/*
getDamageMod
pre: a Skill object must be instantiated
post: an int containing the damage mod will be returned
purpose: to return the damage modifier of the Skill object
*/
int Skill::getDamageMod()
{
	return mDamageMod;
}

/*
setDamageMod
pre: an int of a new modifier will be passed in
post: the damamge modifier of the Skill object will change to the new modifier
purpose: to change the damage modifier of some currently instantiated Skill object.
*/
void Skill::setDamageMod(int newMod)
{
	mDamageMod = newMod;
}

/*
useSkill
pre: an int of the Player's attack must be passed in
post: the damage that the skill does will be returned
purpose: to use a skill in battle
*/
int Skill::useSkill(int attack)
{
	attack *= mDamageMod;
	int damage = rand() % 6 + attack;

	mUses--;

	return damage;
}