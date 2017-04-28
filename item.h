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

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "special_ability.h"

const enum itemId{WATER = 0, COFFEE, APPLE_JUICE};

class Item : public SpecialAbility
{
	protected: 
		int mId, mHealMod;

	public:
		/* Constructors and Destructors*/
		Item();
		Item(int id);

		~Item();

		/* Setters and Getters */
		void setHealMod(int mod);

		int getHealMod();

		void useItem(int &health);
};

#endif