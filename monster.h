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

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "entity.h"

using namespace std;

class Monster : public Entity
{
	protected:
		int mExpAwarded;

	public:
		/* Constructors and Destructors*/
		Monster();
		Monster(string name, int health, int maxHealth, int speed, int attack, int defense, int expAwarded);
		Monster(string stage, Monster monsters[]);

		~Monster();

		/* Getters */
		int getExpAwarded();

		/* Setters */
		void setExpAwarded(int expAwarded);
		
		/* Other Functions */
		friend void loadMonsters(Monster monsters[]);
};

#endif