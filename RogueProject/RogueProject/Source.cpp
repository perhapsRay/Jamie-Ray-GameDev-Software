#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "player.h"
#include "gamemanager.h"
using namespace std;


unsigned int itemPosX;
unsigned int itemPosY;
unsigned int enemyPosX = 18;
unsigned int enemyPosY = 3;
string potion = "Health potion.";
string sword = "Sword.";
unsigned int itemNumber;
unsigned int itemnum;
//vector<string> inventory;
vector<int> itemStore;
vector<char> vItemChar;
unsigned int maxHealth = 25;
unsigned int health = 20;
char itemChar = '?';
char enemyChar = 'e';

int levelHeight = 0;
int levelWidth = 0;
//char* map = NULL;
//Reads in map file and dynamically allocates the array based on the map size.

const int BUFFSIZE = 100;
const int MAXLEVELWIDTH = 100;
const int MAXLEVELHEIGHT = 20;
char currentMap[MAXLEVELHEIGHT][MAXLEVELWIDTH];
//player gamePlayer('@', 5, 5);
//map gameMap("map_2.txt");


//Goes to screen position for printing of certain aspects in certain areas. (GUI ect)
/*void gotoScreenPosition(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}*/

//Chooses random number between 0 and 1 to determine which item is picked up.
// 
//New item chars will add appropriate item to inventory.
void itemPickup(char thing)
{
	switch (thing)
	{
	case '+':
		//inventory.push_back(potion);
		itemStore.push_back(0);
		break;
	case '/':
		//inventory.push_back(sword);
		itemStore.push_back(1);
		break;
	}
}

//Allows item to be placed ontop of another.
bool itemCollision(int y, int x)
{
	char nextMove = currentMap[y][x];

	switch (nextMove)
	{
	case '#':
		return false;
		break;
	case '.':
		return true;
		break;
	case '?':
		return true;
		break;
	case '+':
		return false;
		break;
	case '/':
		return false;
		break;
	default:
		return true;
	}
}

//Checks if position is wall, empty or item.
bool handleCollisions(int y, int x)
{
	char nextMove = currentMap[y][x];

	switch (nextMove)
	{
	case '#':
		return false;
		break;
	case '.':
		return true;
		break;
	case '?':
		//itemCheck();
		return true;
		break;
	case '+':
		itemPickup('+');
		return true;
		break;
	case '/':
		itemPickup('/');
		return true;
		break;
	default:
		return true;
	}
}

//Assigns item a Char for when it is dropped.
void itemAssign()
{
	vItemChar.push_back('+');
	vItemChar.push_back('/');
}

//Drop item function.
/*void dropItem(int thing)
{

	if (inventory[thing] == potion)
	{
		itemnum = 0;
	}
	else
	{
		itemnum = 1;
	}

	//Checks if position is wall, empty or item. If returns false the item cant be placed on the spot.
	if (itemCollision(playerPositionY, playerPositionX + 1))
	{
		itemPosX = playerPositionX + 1;
		itemPosY = playerPositionY;
		cout << vItemChar[itemnum];
		map[itemPosY][itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else if (itemCollision(playerPositionY, playerPositionX - 1))
	{
		itemPosX = playerPositionX - 1;
		itemPosY = playerPositionY;
		cout << vItemChar[itemnum];
		map[itemPosY][itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else if ((itemCollision(playerPositionY + 1, playerPositionX)))
	{
		itemPosX = playerPositionX;
		itemPosY = playerPositionY + 1;
		cout << vItemChar[itemnum];
		map[itemPosY][itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else if ((itemCollision(playerPositionY - 1, playerPositionX)))
	{
		itemPosX = playerPositionX;
		itemPosY = playerPositionY - 1;
		cout << vItemChar[itemnum];
		map[itemPosY][itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else
	{
		
	}
}*/


//Clears screen and prints inventory.
/*void inventoryScreen()
{
	system("CLS");
	gotoScreenPosition(0, 0);
	cout << "Inventory:";


	for (int i = 0; i < inventory.size(); i++)
	{
		gotoScreenPosition(2, 2 + i);
		cout << i + 1 << ". " << inventory[i];
	}

	//Drop item.
	while (true)
	{
		if (GetKeyState('I') & 0x8000)
		{
			break;
		}

		if (inventory.size() <= 0)
		{
			gotoScreenPosition(2, 2);
			cout << "Inventory is empty!";
			continue;
		}

		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			Sleep(120);
			while (true)
			{
				if (GetKeyState(0x31) & 0x8000)
				{
					dropItem(0);
					break;
				}
				if (GetKeyState(0x32) & 0x8000)
				{
					dropItem(1);
					break;
				}
				if (GetKeyState(0x33) & 0x8000)
				{
					dropItem(2);
					break;
				}
			}
			break;
		}
		
	}
	system("CLS");
	renderMap();
}*/

//Renders enemy
void renderEnemy()
{
	if (currentMap[enemyPosY][enemyPosX] == '.')
	{
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << enemyChar;
		currentMap[enemyPosY][enemyPosX] = enemyChar;
	}
	else
	{
		renderEnemy();
	}
}

//Lets enemy move toward player
/*void moveEnemy()
{
	if (enemyPosX > playerPositionX)
	{
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << '.';
		map[enemyPosY][enemyPosX] = '.';

		enemyPosX = enemyPosX - 1;
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << enemyChar;
		map[enemyPosY][enemyPosX] = enemyChar;
	}
	else if (enemyPosX < playerPositionX)
	{
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << '.';
		map[enemyPosY][enemyPosX] = '.';

		enemyPosX = enemyPosX + 1;
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << enemyChar;
		map[enemyPosY][enemyPosX] = enemyChar;
	}
}*/

//Renders GUI elements.


/*void main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	gameMap.readMap();

	newPlayerPositionX = gamePlayer.getplayerPositionX();
	newPlayerPositionY = gamePlayer.getplayerPositionY();

	//Renders map.
	gameMap.renderMap();

	//Renders items.
	renderItem();

	//Renders enemy.
	//renderEnemy();

	//Makes item have relevant char when it is dropped.
	itemAssign();

	//Initial player render.
	gamePlayer.render();


	while (true)
	{
		//Handles the input and updates the players position.
		gamePlayer.handleInput();

		//Render the scene.
		gamePlayer.render();

		//Moves enemy.
		//moveEnemy();

		//Reads in map file and dynamically allocates array size based on map size.

		//Render the GUI.
		renderGUI();

		//Makes cursor not visible.
		set_cursor(false);
	}

	system("pause");
}*/