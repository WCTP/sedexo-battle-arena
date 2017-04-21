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

#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MAX_INITIATIVE = 20;
const int MIN_INITIATIVE = 0;
const int HEALTH_LEVEL_UP_ROLL = 8;
const int LEVEL_UP_ROLL = 4;

enum BATTLE_OP { ATTACK = 1, SKILLS, ITEMS };
enum REST_OP { EXPLORE = 1, BATTLE };
enum SODEXO_MONSTERS {
	PIZZA = 0, BREAD_STICKS, MARINARA_SAUCE,
	CROUTON, CUCUMBER, CARROT, LETTUCE, KUNG_PAO_CHICKEN,
	RAMEN, GENERAL_TSO_BEEF, FLAVORED_WATER, CHEESE_BURGER,
	PULLED_PORK_BURGER, FRENCH_FRIES, FRIED_CHICKEN, CHIMICHANGA,
	MASHED_POTATO, SHEPHERDS_PIE, PASTA, CHICKEN_PARM_SANDWHICH,
	SCRAMBLED_EGGS, OMELETTE, TURKEY_RUBEN, SWEET_POTATO,
	LASAGNA, BACON, GARLIC_BREAD, NACHOS, FRUIT_NACHOS,
	PHILLY_CHEESE_STEAK, CHOCOLATE_MILK, BAGEL, APPLE, ORANGE,
	PAIR, JELLO, CHEESECAKE, BROWNIE, BLONDIE, COOKIE, HOT_CHOCOLATE,
	CEREAL
};

#endif