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

void itemCheck()
{
	itemNumber = rand() % 2;
	if (itemNumber == 0)
	{
		inventory.push_back(potion);
	}
	else if (itemNumber == 1)
	{
		inventory.push_back(item);
	}
}

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
	case '*':
		itemCheck();
		return true;
		break;
	default:
		return true;
	}
}

void dropItem(int thing)
{
	itemPosX = playerPositionX;
	itemPosY = playerPositionY;
	// Put it in the 
	map[itemPosY][itemPosX] = itemChar;
	inventory.erase(inventory.begin() + thing);
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
	// Blank old enemy position
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << ' ';
	map[playerPositionY][playerPositionX] = ' ';

	// Draw new enemy position
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;
	map[playerPositionY][playerPositionX] = playerChar;
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