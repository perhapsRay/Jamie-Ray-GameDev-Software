#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

//System(CLS) - clear screen - use functions

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;


unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;
unsigned int itemPosX;
unsigned int itemPosY;
string potion;
string item;
unsigned int itemNumber;
vector<string> inventory;
bool render = true;


unsigned int maxHealth = 25;
unsigned int health = 20;

char playerChar = '@';
char itemChar = '*';


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

void renderMap()
{
	for (int i = 0; i < LEVELHEIGHT; i++)
	{
		std::cout << map[i] << std::endl;
	}
}

void handleInput()
{
	//newPlayerPositionX = playerPositionX;
	//newPlayerPositionY = playerPositionY;

	if (GetKeyState(VK_UP) & 0x8000 && map[playerPositionY - 1][playerPositionX] != 'a')
	{
		newPlayerPositionY = playerPositionY - 1;
	}

	if (GetKeyState(VK_DOWN) & 0x8000 && map[playerPositionY + 1][playerPositionX] != 'a')
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000 && map[playerPositionY][playerPositionX + 1] != 'a')
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState(VK_LEFT) & 0x8000 && map[playerPositionY][playerPositionX - 1] != 'a')
	{
		newPlayerPositionX = playerPositionX - 1;
	}
}

void renderPlayer()
{
	// Blank old enemy position
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << ' ';

	// Draw new enemy position
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	Sleep(120);
}

void itemCheck()
{
	gotoScreenPosition(2, LEVELHEIGHT + 5);
	std::cout << inventory[0];
}


void renderItem()
{

	//srand((unsigned int)time(NULL));
	itemPosX = rand() % LEVELWIDTH;
	itemPosY = rand() % LEVELHEIGHT;

	

	if (map[itemPosY][itemPosX] == ' ' || map[itemPosY][itemPosX] == '@')
	{
		gotoScreenPosition(itemPosX, itemPosY);
		if (render == true)
		{
			std::cout << itemChar;
		}
		else if (render == false)
		{
			itemNumber = rand() % 2 + 1;
			if (itemNumber == 1)
			{
				inventory.push_back(potion);
			}
			else if (itemNumber == 2)
			{
				inventory.push_back(item);
			}
			itemPosX = NULL;
			itemPosY = NULL;
			itemCheck();
		}
		
	}
	else
	{
		renderItem();
	}
}



void inventoryScreen()
{
	if (GetKeyState('I') & 0x8000)
	{
		system("CLS");
	}
}



void renderGUI()
{
	gotoScreenPosition(2, LEVELHEIGHT + 3);
	std::cout << "Health: " << health << "/" << maxHealth;
}

void handleCollisions()
{
	char nextMove = map[newPlayerPositionY][newPlayerPositionX];

	int currentPosX = playerPositionX;
	int currentPosY = playerPositionY;

	switch (nextMove)
	{
	case 'a':
		gotoScreenPosition(2, LEVELHEIGHT + 5);
		newPlayerPositionX = currentPosX;
		newPlayerPositionY = currentPosY;
		std::cout << "Hit Wall";
		break;
	case ' ':
		playerPositionX = newPlayerPositionX;
		playerPositionY = newPlayerPositionY;
		break;
	}
}

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

	renderMap();

	renderItem();
	inventoryScreen();

	while (true)
	{
		// Handles the input and updates the players position
		handleInput();

		// Render the scene
		renderPlayer();

		// Render the GUI
		renderGUI();

		

		handleCollisions();

		set_cursor(false);
	}

	system("pause");
}