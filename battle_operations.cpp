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
#include "player.h"
#include "constants.h"
#include "battle_operations.h"

/*		Pre: Player, Monster
*	   Post: none
*	Purpose: sets health to appropriate levels
*********************************************************/
void attack(Player& player, Monster& monster, int playerInt, int monsterInt)
{
	int playerAttack, monsterAttack;

	playerAttack = ((player.getAttack() - monster.getDefense() + ((rand() % ATTACK_ROLE) + 1)));
	monsterAttack = ((monster.getAttack() - player.getDefense() + ((rand() % ATTACK_ROLE) + 1)));

	if (playerAttack < 0)
		playerAttack = 0;
	if (monsterAttack < 0)
		monsterAttack = 0;

	if (playerInt > monsterInt)
	{
		monster.setHealth(monster.getHealth() - playerAttack);

		if (monster.getHealth() > 0) // fixed
		{
			player.setHealth(player.getHealth() - monsterAttack);
		}
	}
	else
	{
		player.setHealth(player.getHealth() - monsterAttack);

		if (player.getHealth() > 0)
		{
			monster.setHealth(monster.getHealth() - playerAttack);
		}
	}

	cout << player.getName() << " took " << monsterAttack << " damage." << endl;
	cout << monster.getName() << " took " << playerAttack << " damage." << endl;
	system("pause");

}

/*		Pre: none
*	   Post: int
*	Purpose: shows options in battle and gets input
*********************************************************/
int battleMenu(Player player, Monster monster)
{
	int input;

	system("cls");

	cout << "--------------------------------------------" << endl
		<< "-- BATTLE MENU                            --" << endl
		<< "--------------------------------------------" << endl
		<< "-- " << setw(20) << left << player.getName() << " HP: "
		<< setw(4) << player.getHealth() << " / "
		<< setw(4) << player.getMaxHealth() << "   --"
		<< endl << "-- Atk: "
		<< setw(4) << player.getAttack() << " Def: "
		<< setw(4) << player.getDefense() << " Spd: "
		<< setw(4) << player.getSpeed() << "          --" << endl
		<< "-- " << setw(20) << left << monster.getName() << " HP: "
		<< setw(4) << monster.getHealth() << " / "
		<< setw(4) << monster.getMaxHealth() << "   --"
		<< endl << "-- Atk: "
		<< setw(4) << monster.getAttack() << " Def: "
		<< setw(4) << monster.getDefense() << " Spd: "
		<< setw(4) << monster.getSpeed() << "          --" << endl
		<< "--------------------------------------------" << endl
		<< "-- 1.) Attack                             --" << endl
		<< "-- 2.) Skills                             --" << endl
		<< "-- 3.) Items                              --" << endl
		<< "--------------------------------------------" << endl
		<< "  Command: ";

	cin >> input;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return input;
}

/*		Pre: none
*	   Post: none
*	Purpose: executes command based on input
*********************************************************/
void battleOperations(Player& player, Monster monster, int playerInt, int monsterInt)
{
	int input = 1;

	do
	{
		input = battleMenu(player, monster);

		switch (input)
		{
		case ATTACK:
			attack(player, monster, playerInt, monsterInt);
			break;
		case SKILLS:
			useSkill(player, monster, playerInt, monsterInt);
			break;
		case ITEMS:
			useItem(player, monster, playerInt, monsterInt);
			break;
		default:
			cout << "INVALID COMMAND";
		}

	} while (player.getHealth() > 0 && monster.getHealth() > 0);
}

/*		Pre: Player, string, Monster, int, int
*	   Post: Monster
*	Purpose: initializes initiatives  and monster
*********************************************************/
Monster initializeBattle(Player player, string stage, Monster monsters[], int& playerInt, int& monsterInt)
{
	Monster monster(stage, monsters);

	playerInt = ((rand() % MAX_INITIATIVE) + player.getSpeed());
	monsterInt = ((rand() % MAX_INITIATIVE) + monster.getSpeed());

	return monster;
}

/*		Pre: Player, Monster, string, string array, int,
*			 bool
*	   Post: pass-by-reference string, string array, int
*	Purpose: handles post battle resetting of HP, leveling
*			 up, and stage progression
*********************************************************/
void postBattle(Player& player, Monster monster, string& stage, string stages[], int& stageIndex, bool isBoss)
{
	system("cls");

	if (player.getHealth() > 0)
	{
		player.setExp(player.getExp() + monster.getExpAwarded());
		player.setHealth(player.getMaxHealth());

		if (player.getExp() > player.getExpToLevel())
		{
			player.levelUp();
		}

		cout << "You won!" << endl
			<< "Xp Gained: " << monster.getExpAwarded() << endl;
		system("pause");

		if (isBoss == true)
		{
			stageIndex++;
			stage = stages[stageIndex];
		}
	}
	else
	{
		cout << "You died." << endl;
	}
}

/*		Pre: none
*	   Post: none
*	Purpose: none
*********************************************************/
void useItem(Player& player, Monster& monster, int playerInt, int monsterInt)
{
	int input, monsterAttack, playerAttack;

	for (int i = 0; i < MAX_ITEMSKILL; i++)
	{
		cout << "-- " << i + 1 << ".) " << player.getItem(i).getName() << " Uses: " << player.getItem(i).getUses() << "--" << endl;
	}

	cin >> input;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	input--;

	monsterAttack = ((monster.getAttack() - player.getDefense() + ((rand() % ATTACK_ROLE) + 1)));

	if (monsterAttack < 0)
	{
		monsterAttack = 0;
	}

	if (playerInt > monsterInt)
	{
		player.useItem(input);

		player.setHealth(player.getHealth() - monsterAttack);
	}
	else
	{
		player.setHealth(player.getHealth() - monsterAttack);

		if (player.getHealth() > 0)
		{
			player.useItem(input);
		}
	}

	cout << player.getName() << " took " << monsterAttack << " damage." << endl;
	system("pause");

}


/*		Pre: none
*	   Post: none
*	Purpose: none
*********************************************************/
void useSkill(Player& player, Monster& monster, int playerInt, int monsterInt)
{
	int input, monsterAttack, playerAttack;

	for (int i = 0; i < player.getNumSkills(); i++)
	{
		cout << "-- " << i + 1 << ".) " << player.getSkill(i).getName() << " Uses: " << player.getSkill(i).getUses() << "--" << endl;
	}

	cin >> input;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	input--;

	monsterAttack = ((monster.getAttack() - player.getDefense() + ((rand() % ATTACK_ROLE) + 1)));
	if (player.getSkill(input).getUses() > 0)
	{
		playerAttack = player.useSkillBattle(input);
	}

	else
	{
		playerAttack = 0;
	}

	if (playerAttack < 0)
		playerAttack = 0;
	if (monsterAttack < 0)
		monsterAttack = 0;

	if (playerInt > monsterInt)
	{
		monster.setHealth(monster.getHealth() - playerAttack);

		if (monster.getHealth() > 0)
		{
			player.setHealth(player.getHealth() - monsterAttack);
		}
	}
	else
	{
		player.setHealth(player.getHealth() - monsterAttack);

		if (player.getHealth() > 0)
		{
			monster.setHealth(monster.getHealth() - playerAttack);
		}
	}

	cout << player.getName() << " took " << monsterAttack << " damage." << endl;
	cout << monster.getName() << " took " << playerAttack << " damage." << endl;
	system("pause");
}