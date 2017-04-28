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
	mNumSkills = 0;

	for (int i = 0; i < MAX_ITEMSKILL; i++)
	{
		mItems[i] = Item();
	}
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

	mNumSkills = 0;

	for (int i = 0; i < MAX_ITEMSKILL; i++)
	{
		mItems[i] = Item(i);
	}

	mSkills = NULL;
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

/*
getItem
pre: an int containing the index of the wanted item
post: an Item object at the index will be returned
purpose: to get an Item at a certain object
*/
Item& Player::getItem(int index)
{
	return mItems[index];
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

/*
pre: none
post: int
purpose: get the number of skills
*/
int Player::getNumSkills()
{
	return mNumSkills;
}

/*
getSkill
pre: an int containing the index of the wanted skill
post: the skill at the index will be returned
purpose: to get the skill at a certain index
*/
Skill Player::getSkill(int index)
{
	return mSkills[index];
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

/*
setItem
pre: an int containing the index of the array, and the needed itemId
post: an item at the index will change to a new item based on the id
purpose: to set the item at a location in the array to a new item (note, this will
reset the amount of uses left on items)
*/
void Player::setItem(int index, int itemid)
{
	mItems[index] = Item(itemid);
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

/*
pre: int
post: none
purpose: set number of skills
*/
void Player::setNumSkills(int numSkills)
{
	mNumSkills = numSkills;
}

/*
setSkill
pre: an int containing the index of the array, and the needed skillId
post: a skill at the index will change to a new skill based on the id
purpose: to change the skill at a location in the array to a new skill (note, this will reset
whether the player possesses the skill or not)
*/
void Player::setSkill(int index, int skillId)
{
	mSkills[index] = Skill(skillId);
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
	mLevel++;
	mMaxHealth += ((rand() % HEALTH_LEVEL_UP_ROLL) + 1);
	mSpeed += ((rand() % LEVEL_UP_ROLL) + 1);
	mAttack += ((rand() % LEVEL_UP_ROLL) + 1);
	mDefense += ((rand() % LEVEL_UP_ROLL) + 1);
	mExpToLevel += mExpToLevel * ((rand() % 2) + 2);

	cout << right << setw(20) << "LEVEL UP!" << endl;
	cout << setw(20) << "New Level: " << setw(3) << mLevel << endl;
	cout << setw(20) << "HP: " << setw(3) << mMaxHealth << endl
		 << setw(20) << "Attack: " << setw(3) << mAttack << endl
		 << setw(20) << "Defense: " << setw(3) << mDefense << endl
		 << setw(20) << "Speed: " << setw(3) << mSpeed << endl
		 << setw(20) << "Xp to Next Level: " << setw(3) << mExpToLevel << endl;
	system("pause");
}

/*
unlockSkill
pre: an index of the skill that will be unlocked
post: a skill at a certain index that is possessed will be true
purpose: to set the skill at a certain index will be set to true
*/
void Player::unlockSkill(int index)
{
	int i;
	mNumSkills++;
	Skill* temp = new Skill[mNumSkills];

	for (i = 0; i < mNumSkills - 1; i++)
	{
		temp[i] = mSkills[i];
	}

	temp[i] = Skill(index);

	delete[] mSkills;

	mSkills = temp;

	cout << mSkills[index].getName() << " unlocked!" << endl;

	mSkills[index].setPossess(true);

	//delete[] temp; 
	// breaks program???

}

/*		Pre: int
 *	   Post: none
 *	Purpose: uses item and heals certain amount of health
 *********************************************************/
void Player::useItem(int index)
{
	if (mItems[index].getUses() > 0)
	{
		mItems[index].useItem(mHealth);

		if (mHealth > mMaxHealth)
		{
			mHealth = mMaxHealth;
		}

		cout << "Healed for " << mItems[index].getHealMod() << " points!" << endl;
	}
}

/*		Pre: int
 *	   Post: int
 *	Purpose: returns damage of skill used
 *********************************************************/
int Player::useSkillBattle(int index)
{
	return mSkills[index].useSkill(mAttack);
}