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

#include "player.h"


/*		Pre: none
 *	   Post: none
 *	Purpose: default constructor
 *********************************************************/
Player::Player() : Entity()
{
	mExp = 0;
	mExpToLevel = 0;
	mMoney = 0;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: constructor
 *********************************************************/
Player::Player(string name, int health, int maxHealth, int speed, int attack, int defense, int exp, int expToLevel, int money)
{
	mName = name;
	mHealth = health;
	mMaxHealth = maxHealth;
	mSpeed = speed;
	mAttack = attack;
	mDefense = defense;
	mExp = exp;
	mExpToLevel = expToLevel;
	mMoney = money;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: destructor
 *********************************************************/
Player::~Player()
{
	/* left blank intentionally */
}

/*		Pre: none
 *	   Post: int
 *	Purpose: retrieves exp
 *********************************************************/
int Player::getExp()
{
	return mExp;
}

/*		Pre: none
 *	   Post: int
 *	Purpose: retrieves exp to level
 *********************************************************/
int Player::getExpToLevel()
{
	return mExpToLevel;
}

/*		Pre: none
 *	   Post: int
 *	Purpose: retrieves money
 *********************************************************/
int Player::getMoney()
{
	return mMoney;
}

/*		Pre: int
 *	   Post: none
 *	Purpose: sets exp
 *********************************************************/
void Player::setExp(int exp)
{
	mExp = exp;
}

/*		Pre: int
 *	   Post: none
 *	Purpose: sets exp to level
 *********************************************************/
void Player::setExpToLevel(int expToLevel)
{
	mExpToLevel = expToLevel;
}

/*		Pre: int
 *	   Post: none
 *	Purpose: sets money
 *********************************************************/
void Player::setMoney(int money)
{
	mMoney = money;
}