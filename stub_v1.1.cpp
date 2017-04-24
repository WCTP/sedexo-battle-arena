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
#include "entity.h"
#include "player.h"
#include "monster.h"
#include "battle_operations.h"
#include "rest_operations.h"

int main()
{
	Player player;
	Monster monsters[NUMBER_OF_MONSTERS];
	Monster monster;
	string stage = FIRST_STAGE;
	int playerInt, monsterInt, input;
	
	srand(time(NULL));
	loadMonsters(monsters);
	player = generatePlayer();
	
	do
	{

		do
		{
			input = restMenu(player, stage);

			switch (input)
			{
				case EXPLORE : 
					explore();
					break;
				case BATTLE :
					monster = initializeBattle(player, stage, monsters, playerInt, monsterInt);
					battleOperations(player, stage, monster, playerInt, monsterInt);
					break;
				case FACE_BOSS :
					break;
				default :
					notifyInvalid();
			}

		} while (input < EXPLORE && input > FACE_BOSS && player.getHealth() > 0);
	} while (stage != FINISH);
	
	system("pause");

	return 0;
}