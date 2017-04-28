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

#include "rest_operations.h"
#include "battle_operations.h"

/*		Pre: Player, Monster, string, Monster array,
 *			 int, int, string array, int, bool
 *	   Post: none
 *	Purpose: explores room based off of random variables
 *********************************************************/
void explore(Player &player, Monster &monster, string stage, Monster monsters[], int playerInt, int monsterInt,
			 string stages[], int stageIndex, bool isBoss)
{
	int randChoice = rand() % 20 + 1;

	if (randChoice == 1)
	{
		player.setHealth(player.getMaxHealth());
		for (int i = 0; i < player.getNumSkills(); i++)
		{
			player.setSkill(i, i);
			player.getSkill(i).setPossess(true);
		}

		for (int i = 0; i < MAX_ITEMSKILL; i++)
		{
			player.setItem(i, i);
		}

		cout << "Mr. Sodexo blesses " << player.getName() << endl;

		system("pause");
	}

	else if (randChoice > 1 && randChoice <= 6)
	{
		int randItem = rand() % 3;

		player.getItem(randItem).setUses(player.getItem(randItem).getUses() + 1);

		cout << player.getName() << " found a " << player.getItem(randItem).getName() << endl;

		system("pause");
	}

	else
	{
		cout << "A battle!!!!!!!" << endl;

		system("pause");

		monster = initializeBattle(player, stage, monsters, playerInt, monsterInt);
		battleOperations(player, monster, playerInt, monsterInt);
		postBattle(player, monster, stage, stages, stageIndex, isBoss);

	}

}

/*		Pre: none
 *	   Post: none
 *	Purpose: loads stages into stage array
 *********************************************************/
void loadStages(string stages[])
{
	int stageIndex = 0;

	stages[stageIndex] = FIRST_STAGE;
	stageIndex++;
	stages[stageIndex] = SECOND_STAGE;
	stageIndex++;
	stages[stageIndex] = THIRD_STAGE;
	stageIndex++;
	stages[stageIndex] = FOURTH_STAGE;
	stageIndex++;
	stages[stageIndex] = FIFTH_STAGE;
	stageIndex++;
	stages[stageIndex] = SIXTH_STAGE;
	stageIndex++;
	stages[stageIndex] = SEVENTH_STAGE;
	stageIndex++;
	stages[stageIndex] = FINISH;
}

void notifyInvalid()
{
	cout << "  INVALID COMMAND" << endl << "  ";
	system("pause");
}

/*		Pre: none
 *	   Post: none
 *	Purpose: displays rest menu and gets input
 *********************************************************/
int restMenu(Player player, string stage)
{
	int input;

	system("cls");

	cout	<< "--------------------------------------------" << endl
			<< "-- REST MENU | STAGE: " << left << setw(20) << stage <<  "--" << endl
			<< "--------------------------------------------" << endl
			<< "-- Level: " << left << setw(3) << player.getLevel() 
			<< "                             --" << endl
			<< "-- " << setw(20) << left << player.getName() << " HP: " 
			<< setw(4) << player.getHealth() << " / "
			<< setw(4) << player.getMaxHealth() << "   --" 
			<< endl << "-- Atk: " 
			<< setw(4) << player.getAttack() << " Def: "
			<< setw(4) << player.getDefense() << " Spd: "
			<< setw(4) << player.getSpeed() << " Xp: " 
			<< setw(5) << player.getExp() << "--" << endl
			<< "-- 1.) Explore                            --" << endl
			<< "-- 2.) Battle                             --" << endl
			<< "-- 3.) Face Boss                          --" << endl
			<< "--------------------------------------------" << endl
			<< "  Command: ";

	cin >> input;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return input;
}