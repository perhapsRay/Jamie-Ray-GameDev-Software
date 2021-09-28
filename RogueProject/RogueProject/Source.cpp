#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;
unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;
unsigned int itemPosX;
unsigned int itemPosY;
string potion = "Health potion.";
string sword = "Sword.";
unsigned int itemNumber;
vector<string> inventory;
vector<int> itemStore;
vector<char> vItemChar;
unsigned int maxHealth = 25;
unsigned int health = 20;
char playerChar = '@';
char itemChar = '?';


char map[LEVELHEIGHT][LEVELWIDTH + 1] =
{
"aaaaaaaaaaaaaaaaaaaa",
"a         a        a",
"a         a        a",
"a         a        a",
"a         a        a",
"a                  a",
"a                  a",
"a                  a",
"a                  a",
"aaaaaaaaaaaaaaaaaaaa"
};


void gotoScreenPosition(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//Renders the map.
void renderMap()
{
	for (int i = 0; i < LEVELHEIGHT; i++)
	{
		std::cout << map[i] << std::endl;
	}
}

//Chooses random number between 1 and 2 to determine which item is picked up.
void itemCheck()
{
	//srand(time(NULL));
	itemNumber = rand() % 2;
	if (itemNumber == 0)
	{
		inventory.push_back(potion);
		itemStore.push_back(itemNumber);
	}
	else if (itemNumber == 1)
	{
		inventory.push_back(sword);
		itemStore.push_back(itemNumber);
	}
}

//New item chars will add appropriate item to inventory.
void itemPickup(char thing)
{
	switch (thing)
	{
	case '+':
		inventory.push_back(potion);
		itemStore.push_back(0);
		break;
	case '/':
		inventory.push_back(sword);
		itemStore.push_back(1);
		break;
	}
}


//Checks if position is wall, empty or item.
bool handleCollisions(int y, int x)
{
	char nextMove = map[y][x];

	switch (nextMove)
	{
	case 'a':
		return false;
		break;
	case ' ':
		return true;
		break;
	case '?':
		itemCheck();
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
void dropItem(int thing)
{
	//Checks if position is wall, empty or item. If returns false the item can be placed on the spot.
	if (handleCollisions(playerPositionY, playerPositionX + 1))
	{
		itemPosX = playerPositionX + 1;
		itemPosY = playerPositionY;
		cout << vItemChar[0];
		//cout << itemChar;
		// Put it in the 
		map[itemPosY][itemPosX] = vItemChar[0];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	//If returns true it will place it to the left of the player instead.
	else
	{
		itemPosX = playerPositionX - 1;
		itemPosY = playerPositionY;
		cout << vItemChar[0];
		map[itemPosY][itemPosX] = vItemChar[0];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
}

//Clears screen and prints inventory.
void inventoryScreen()
{
	system("CLS");
	Sleep(120);

	if (inventory.size() <= 0)
	{
		gotoScreenPosition(0, 0);
		cout << "Inventory is empty!";
	}
	else
	{
		gotoScreenPosition(0, 0);
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i+1 << ". " << inventory[i] << endl;
		}
	}

	//Drop item.
	while (true)
	{
		if (GetKeyState(VK_SPACE))
		{
			while (true)
			{
				if (GetKeyState(0x31))
				{
					dropItem(0);
					break;
				}
				if (GetKeyState(0x32))
				{
					dropItem(1);
					break;
				}
				if (GetKeyState(0x33))
				{
					dropItem(2);
					break;
				}
			}
			break;
		}
		if (GetKeyState('I') & 0x8000)
		{
			break;
		}
	}
	system("CLS");
	renderMap();
}

//Handles Input.
void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	Sleep(120);
	if (GetKeyState(VK_UP) & 0x8000 && handleCollisions(playerPositionY - 1, playerPositionX))
	{
		newPlayerPositionY = playerPositionY - 1;
	}

	if (GetKeyState(VK_DOWN) & 0x8000 && handleCollisions(playerPositionY + 1, playerPositionX))
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000 && handleCollisions(playerPositionY, playerPositionX + 1))
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState(VK_LEFT) & 0x8000 && handleCollisions(playerPositionY, playerPositionX - 1))
	{
		newPlayerPositionX = playerPositionX - 1;
	}

	if (GetKeyState('I') & 0x8000)
	{
		inventoryScreen();
	}
}

void renderPlayer()
{
	//Blank old player position.
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << ' ';
	map[playerPositionY][playerPositionX] = ' ';

	//Draw new player position.
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;
	map[playerPositionY][playerPositionX] = playerChar;
}


//Handles item rendering.
void renderItem()
{
	//srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		itemPosX = rand() % LEVELWIDTH;
		itemPosY = rand() % LEVELHEIGHT;

		if (map[itemPosY][itemPosX] == ' ' || map[itemPosY][itemPosX] == '@' || map[itemPosY][itemPosX] == '?')
		{
			gotoScreenPosition(itemPosX, itemPosY);
			std::cout << itemChar;
			map[itemPosY][itemPosX] = itemChar;
		}
		else
		{
			renderItem();
		}
	}
}
//Renders GUI elements.
void renderGUI()
{
	gotoScreenPosition(2, LEVELHEIGHT + 3);
	std::cout << "Health: " << health << "/" << maxHealth;
}

//Sets cursor invisible
void set_cursor(bool visible) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	//Renders map.
	renderMap();

	//Renders items.
	renderItem();

	//Makes item have relevant char when it is dropped.
	itemAssign();

	while (true)
	{
		//Handles the input and updates the players position.
		handleInput();

		//Render the scene.
		renderPlayer();

		//Render the GUI.
		renderGUI();

		//Makes cursor not visible.
		set_cursor(false);
	}

	system("pause");
}