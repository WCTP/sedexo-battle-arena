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
#include "constants.h"


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
 *	Purpose: constructs based off of id
 *********************************************************/
Monster::Monster(string stage, Monster monsters[])
{
	int monsterIndex;

	if (stage == FIRST_STAGE)
	{
		monsterIndex = (rand() % FIRST_STAGE_MONSTER_NUM);
	}
	else if (stage == SECOND_STAGE)
	{
		monsterIndex = ((rand() % SECOND_STAGE_MONSTER_NUM) + FIRST_BOSS_INDEX + 1);
	}
	else if (stage == THIRD_STAGE)
	{
		monsterIndex = ((rand() % THIRD_STAGE_MONSTER_NUM) + SECOND_BOSS_INDEX + 1);
	}
	else if (stage == FOURTH_STAGE)
	{
		monsterIndex = ((rand() % FOURTH_STAGE_MONSTER_NUM) + THIRD_BOSS_INDEX + 1);
	}
	else if (stage == FIFTH_STAGE)
	{
		monsterIndex = ((rand() % FIFTH_STAGE_MONSTER_NUM) + FOURTH_BOSS_INDEX + 1);
	}
	else if (stage == SIXTH_STAGE)
	{
		monsterIndex = ((rand() % SIXTH_STAGE_MONSTER_NUM) + FIFTH_BOSS_INDEX + 1);
	}
	else if (stage == SEVENTH_STAGE)
	{
		monsterIndex = ((rand() % SEVENTH_STAGE_MONSTER_NUM) + SIXTH_BOSS_INDEX + 1);
	}

	mName = monsters[monsterIndex].getName();
	mHealth = monsters[monsterIndex].getHealth();
	mMaxHealth = monsters[monsterIndex].getMaxHealth();
	mSpeed = monsters[monsterIndex].getSpeed();
	mAttack = monsters[monsterIndex].getAttack();
	mDefense = monsters[monsterIndex].getDefense();
	mExpAwarded = monsters[monsterIndex].getExpAwarded();
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

/*		Pre: Monster array, Monster array
 *	   Post: none
 *	Purpose: loads up bosses array with monsters array
 *********************************************************/
void loadBosses(Monster bosses[], Monster monsters[])
{
	int bossIndex = 0;

	bosses[bossIndex] = monsters[FIRST_BOSS_INDEX];
	bossIndex++;
	bosses[bossIndex] = monsters[SECOND_BOSS_INDEX];
	bossIndex++;
	bosses[bossIndex] = monsters[THIRD_BOSS_INDEX];
	bossIndex++;
	bosses[bossIndex] = monsters[FOURTH_BOSS_INDEX];
	bossIndex++;
	bosses[bossIndex] = monsters[FIFTH_BOSS_INDEX];
	bossIndex++;
	bosses[bossIndex] = monsters[SIXTH_BOSS_INDEX];
	bossIndex++;
	bosses[bossIndex] = monsters[SEVENTH_BOSS_INDEX];
}

/*		Pre: Monster array
 *	   Post: none
 *	Purpose: loads up monster array with monster text file
 *********************************************************/
void loadMonsters(Monster monsters[])
{
	ifstream fin;
	fin.open(MONSTER_FILE);

	for (int i = 0; i < NUMBER_OF_MONSTERS; i++)
	{
		getline(fin, monsters[i].mName);

		fin >> monsters[i].mHealth;
		fin >> monsters[i].mMaxHealth;
		fin.ignore();
		fin >> monsters[i].mSpeed;
		fin >> monsters[i].mAttack;
		fin >> monsters[i].mDefense;
		fin.ignore();
		fin >> monsters[i].mExpAwarded;
		fin.ignore();
	}

	fin.close();
}