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

#include "entity.h"


/*		Pre: none
 *	   Post: none
 *	Purpose: default constructor
 *********************************************************/
Entity::Entity()
{
	mName = "";
	mHealth = 0;
	mMaxHealth = 0;
	mSpeed = 0;
	mAttack = 0;
	mDefense = 0;
}

/*      Pre: none
 *     Post: none
 *	Purpose: constructor
 *********************************************************/
Entity::Entity(string name, int health, int maxHealth, int speed, int attack, int defense)
{
	mName = name;
	mHealth = health;
	mMaxHealth = maxHealth;
	mSpeed = speed;
	mAttack = attack;
	mDefense = defense;
}

/*      Pre: none
 *     Post: none
 *	Purpose: destructor
 *********************************************************/
Entity::~Entity()
{
	/* left blank intentionally */
}

/*      Pre: int
 *     Post: none
 *	Purpose: retrieves attack
 *********************************************************/
int Entity::getAttack()
{
	return mAttack;
}

/*      Pre: int
 *     Post: none
 *	Purpose: retrieves defense
 *********************************************************/
int Entity::getDefense()
{
	return mDefense;
}

/*      Pre: none
 *     Post: string
 *	Purpose: retrieves health
 *********************************************************/
int Entity::getHealth()
{
	return mHealth;
}

/*      Pre: none
 *     Post: int
 *	Purpose: retrieves max health
 *********************************************************/
int Entity::getMaxHealth()
{
	return mMaxHealth;
}

/*      Pre: none
 *     Post: string
 *	Purpose: retrieves name
 *********************************************************/
string Entity::getName()
{
	return mName;
}

/*      Pre: none
 *     Post: int
 *	Purpose: retrieves speed
 *********************************************************/
int Entity::getSpeed()
{
	return mSpeed;
}

/*      Pre: int
 *     Post: none
 *	Purpose: sets attack
 *********************************************************/
void Entity::setAttack(int attack)
{
	mAttack = attack;
}

/*      Pre: int
 *     Post: none
 *	Purpose: sets defense
 *********************************************************/
void Entity::setDefense(int defense)
{
	mDefense = defense;
}

/*      Pre: int
 *     Post: none
 *	Purpose: sets health
 *********************************************************/
void Entity::setHealth(int health)
{
	mHealth = health;
}

/*      Pre: int
 *     Post: none
 *	Purpose: sets max health
 *********************************************************/
void Entity::setMaxHealth(int maxHealth)
{
	mMaxHealth = maxHealth;
}

/*      Pre: string
 *     Post: none
 *	Purpose: sets name
 *********************************************************/
void Entity::setName(string name)
{
	mName = name;
}

/*      Pre: int
 *     Post: none
 *	Purpose: sets speed
 *********************************************************/
void Entity::setSpeed(int speed)
{
	mSpeed = speed;
}

/*      Pre: ostream
 *     Post: ostream
 *	Purpose: displays Entity
 *********************************************************/
ostream& operator<<(ostream& output, Entity obj)
{
	const int SPACING = 9;

	output	<< right << setw(SPACING) << "Name: " << obj.mName << endl
			<< right << setw(SPACING) << "HP: " << obj.mHealth << "/" << obj.mMaxHealth << endl
			<< right << setw(SPACING) << "Attack: " << obj.mAttack << endl
			<< right << setw(SPACING) << "Defense: " << obj.mDefense << endl
			<< right << setw(SPACING) << "Speed: " << obj.mSpeed << endl;

	return output;
}