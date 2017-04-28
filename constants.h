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

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_INITIATIVE = 20;
const int MIN_INITIATIVE = 0;

const int MAX_ITEMSKILL = 3;

const int NUMBER_OF_MONSTERS = 42;
const int NUMBER_OF_BOSSES = 7;
const int NUMBER_OF_STAGES = 7;

const int ATTACK_ROLE = 6;
const int HEALTH_LEVEL_UP_ROLL = 8;
const int LEVEL_UP_ROLL = 4;

const int FIRST_BOSS_INDEX = 2;
const int SECOND_BOSS_INDEX = 6;
const int THIRD_BOSS_INDEX = 10;
const int FOURTH_BOSS_INDEX = 13;
const int FIFTH_BOSS_INDEX = 23;
const int SIXTH_BOSS_INDEX = 29;
const int SEVENTH_BOSS_INDEX = 41;

const int FIRST_STAGE_MONSTER_NUM = 2;
const int SECOND_STAGE_MONSTER_NUM = 3;
const int THIRD_STAGE_MONSTER_NUM = 3;
const int FOURTH_STAGE_MONSTER_NUM = 2;
const int FIFTH_STAGE_MONSTER_NUM = 9;
const int SIXTH_STAGE_MONSTER_NUM = 5;
const int SEVENTH_STAGE_MONSTER_NUM = 11;

const string MONSTER_FILE = "monsters.txt";

const string FIRST_STAGE = "PIZZA_LAND";
const string SECOND_STAGE = "SALAD_LAND";
const string THIRD_STAGE = "INTERNATIONAL_LAND";
const string FOURTH_STAGE = "THE_GRILLE";
const string FIFTH_STAGE = "ENTREE_LAND_PT_ONE";
const string SIXTH_STAGE = "ENTREE_LAND_PT_TWO";
const string SEVENTH_STAGE = "DESSERT_LAND";
const string FINISH = "FINISH";


enum BATTLE_OP { ATTACK = 1, SKILLS, ITEMS };
enum REST_OP { EXPLORE = 1, BATTLE, FACE_BOSS };
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