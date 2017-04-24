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
	mLevel = 0;
}

/*		Pre: none
 *	   Post: none
 *	Purpose: constructor
 *********************************************************/
Player::Player(string name, int health, int maxHealth, int speed, int attack, int defense, int exp, int expToLevel, int money, int level)
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
	mLevel = level;
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
 *	Purpose: retrieves level
 *********************************************************/
int Player::getLevel()
{
	return mLevel;
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
 *	Purpose: sets level
 *********************************************************/
void Player::setLevel(int level)
{
	mLevel = level;
}

/*		Pre: int
 *	   Post: none
 *	Purpose: sets money
 *********************************************************/
void Player::setMoney(int money)
{
	mMoney = money;
}

/*		Pre: none
 *	   Post: Player
 *	Purpose: asks user what class they would like to be
 *			 and generates a character accordingly
 *********************************************************/
Player generatePlayer()
{
	
	string name;

	cout << "Enter a Name: ";
	getline(cin, name);

	/* default stats a player gets */
	Player player(name, 10, 10, 2, 2, 2, 0, 25, 0, 1);
	
	return player;
}

void Player::levelUp()
{
	mMaxHealth += ((rand() % HEALTH_LEVEL_UP_ROLL) + 1);
	mSpeed += ((rand() % LEVEL_UP_ROLL) + 1);
	mAttack += ((rand() % LEVEL_UP_ROLL) + 1);
	mDefense += ((rand() % LEVEL_UP_ROLL) + 1);
	mExpToLevel += mExpToLevel * ((rand() % 2) + 2);
}