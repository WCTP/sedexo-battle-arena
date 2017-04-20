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

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class Entity 
{
	protected:
		string mName;
		int mHealth, mMaxHealth, mSpeed, mAttack, mDefense;

	public: 
		/* Constructors and Destructors */
		Entity();
		Entity(string name, int health, int maxHealth, int speed, int attack, int defense);

		~Entity();

		/* Getters */
		int getAttack();
		int getDefense();
		int getHealth();
		int getMaxHealth();
		string getName();
		int getSpeed();
		
		/* Setters */
		void setAttack(int attack);
		void setDefense(int defense);
		void setHealth(int health);
		void setMaxHealth(int maxHealth);
		void setName(string name);
		void setSpeed(int speed);

		/* Other Functions */
		int rollInitiative();

		friend ostream& operator<<(ostream& output, Entity obj);

};

#endif