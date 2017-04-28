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

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "entity.h"
#include "skill.h"
#include "item.h"
#include "constants.h"

using namespace std;

class Player : public Entity
{
	protected:
		int mExp, mExpToLevel, mMoney, mLevel;
		Skill* mSkills;
		Item mItems[MAX_ITEMSKILL];
		int mNumSkills;

	public:
		/* Constructors and Destructors*/
		Player();
		Player(string name, int health, int maxHealth, int speed, int attack, int defense, int exp, int expToLevel, int money, int level);

		~Player();

		/* Getters */
		int getExp();
		int getExpToLevel();
		int getLevel();
		int getMoney();
		int getNumSkills();
		Skill getSkill(int index);
		Item& getItem(int index);

		/* Setters */
		void setExp(int exp);
		void setExpToLevel(int expToLevel);
		void setLevel(int level);
		void setMoney(int money);
		void setNumSkills(int numSkills);
		void setSkill(int index, int skillid);
		void setItem(int index, int itemid);

		void unlockSkill(int index);

		friend Player generatePlayer();

		void levelUp();

		void useItem(int index);

		int useSkillBattle(int index);

		
};

#endif