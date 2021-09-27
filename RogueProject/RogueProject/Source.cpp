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
string item;
unsigned int itemNumber;
vector<string> inventory;


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

//Clears screen and prints inventory.
void inventoryScreen()
{
	while (true)
	{
		system("CLS");
		gotoScreenPosition(0, 0);
		cout << inventory[0];

		if (GetKeyState('I') & 0x8000)
			break;
	}
}

//Handles Input.
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

	if (GetKeyState('I') & 0x8000)
	{
		inventoryScreen();
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


//Handles item rendering.
void renderItem()
{
	//srand(time(NULL));
	//srand((unsigned int)time(NULL));
	//itemPosX = rand() % LEVELWIDTH;
	//itemPosY = rand() % LEVELHEIGHT;

	itemPosY = 8;
	itemPosX = 8;

	if (map[itemPosY][itemPosX] == ' ' || map[itemPosY][itemPosX] == '@')
	{
		gotoScreenPosition(itemPosX, itemPosY);
		std::cout << itemChar;
		// Put it in the 
		map[itemPosY][itemPosX] = itemChar;
	}
	else
	{
		renderItem();
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
	case '*':
		inventory.push_back(potion);
		map[itemPosY][itemPosX] = ' ';
		break;
	}

	/*if (playerPositionX == itemPosX && playerPositionY == itemPosY)
	{
		inventory.push_back(potion);
		itemPosX = NULL;
		itemPosY = NULL;
	}*/

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