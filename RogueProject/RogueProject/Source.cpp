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
string item = "Sword.";
unsigned int itemNumber;
vector<string> inventory(4);


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
	Sleep(120);

	if (inventory.size() <= 0)
	{
		system("CLS");
		gotoScreenPosition(0, 0);
		cout << "Inventory is empty!";
	}
	else
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			system("CLS");
			gotoScreenPosition(0, 0);
			cout << inventory[i] << endl;
		}
	}

	while (true)
	{
		if (GetKeyState('I') & 0x8000)
		{
			system("CLS");
			renderMap();
			break;
		}
	}
}

//Handles Input.
void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	Sleep(120);
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
	map[playerPositionY][playerPositionX] = NULL;

	// Draw new enemy position
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;
	map[newPlayerPositionY][newPlayerPositionX] = playerChar;

}


//Handles item rendering.
void renderItem()
{
	//srand(time(NULL));
	//srand((unsigned int)time(NULL));

	//itemPosY = 8;
	//itemPosX = 8;

	//not working :( 
	for (int i = 0; i < 2; i++)
	{
		itemPosX = rand() % LEVELWIDTH;
		itemPosY = rand() % LEVELHEIGHT;

		if (map[itemPosY][itemPosX] == ' ' || map[itemPosY][itemPosX] == '@' || map[itemPosY][itemPosX] == '*')
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
		itemNumber = rand() % 2;
		if (itemNumber == 0)
		{
			inventory.push_back(potion);
		}
		else if (itemNumber == 1)
		{
			inventory.push_back(item);
		}
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

		

		set_cursor(false);
	}

	system("pause");
}