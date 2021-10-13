#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//const int LEVELWIDTH = 20;
//const int LEVELHEIGHT = 10;
unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;
unsigned int itemPosX;
unsigned int itemPosY;
unsigned int enemyPosX = 18;
unsigned int enemyPosY = 3;
string potion = "Health potion.";
string sword = "Sword.";
unsigned int itemNumber;
unsigned int itemnum;
vector<string> inventory;
vector<int> itemStore;
vector<char> vItemChar;
unsigned int maxHealth = 25;
unsigned int health = 20;
char playerChar = '@';
char itemChar = '?';

char enemyChar = 'e';




/*char map[LEVELHEIGHT][LEVELWIDTH + 1] =
{
"####################",
"#..................#",
"#..................#",
"#..................#",
"#..................#",
"#..................#",
"#..................#",
"#..................#",
"#..................#",
"####################"
};*/

int LEVELHEIGHT = 0;
int LEVELWIDTH = 0;
char* map = NULL;

void readMap()
{
	string buffer;
	ifstream myfile("map_1.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, buffer))
		{
			LEVELHEIGHT++;
			//cout << ch;
		}
		LEVELWIDTH = buffer.length();
	}
	map = new char[LEVELWIDTH * LEVELHEIGHT];
}


void gotoScreenPosition(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


//Renders the map.
void renderMap(char* m, int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << m[i*height + j];
		}
		cout << endl;
	}
}

//Chooses random number between 0 and 1 to determine which item is picked up.
void itemCheck()
{
	srand(time(NULL));
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

//Allows item to be placed ontop of another.
bool itemCollision(int y, int x)
{
	char nextMove = map[y * x];

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
	char nextMove = map[y * x];

	switch (nextMove)
	{
	case '#':
		return false;
		break;
	case '.':
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
		map[itemPosY * itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else if (itemCollision(playerPositionY, playerPositionX - 1))
	{
		itemPosX = playerPositionX - 1;
		itemPosY = playerPositionY;
		cout << vItemChar[itemnum];
		map[itemPosY * itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else if ((itemCollision(playerPositionY + 1, playerPositionX)))
	{
		itemPosX = playerPositionX;
		itemPosY = playerPositionY + 1;
		cout << vItemChar[itemnum];
		map[itemPosY * itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else if ((itemCollision(playerPositionY - 1, playerPositionX)))
	{
		itemPosX = playerPositionX;
		itemPosY = playerPositionY - 1;
		cout << vItemChar[itemnum];
		map[itemPosY * itemPosX] = vItemChar[itemnum];
		inventory.erase(inventory.begin() + thing);
		itemStore.erase(itemStore.begin() + thing);
	}
	else
	{
		
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
			Sleep(120);
			while (true)
			{
				if (GetKeyState(0x31))
				{
					Sleep(500);
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
	renderMap(&map[0 * 0], LEVELWIDTH, LEVELHEIGHT);
}

//Handles Input.
void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	while (true)
	{
		Sleep(120);
		if (GetKeyState(VK_UP) & 0x8000 && handleCollisions(playerPositionY - 1, playerPositionX))
		{
			newPlayerPositionY = playerPositionY - 1;
			break;
		}

		if (GetKeyState(VK_DOWN) & 0x8000 && handleCollisions(playerPositionY + 1, playerPositionX))
		{
			newPlayerPositionY = playerPositionY + 1;
			break;
		}

		if (GetKeyState(VK_RIGHT) & 0x8000 && handleCollisions(playerPositionY, playerPositionX + 1))
		{
			newPlayerPositionX = playerPositionX + 1;
			break;
		}

		if (GetKeyState(VK_LEFT) & 0x8000 && handleCollisions(playerPositionY, playerPositionX - 1))
		{
			newPlayerPositionX = playerPositionX - 1;
			break;
		}

		if (GetKeyState('I') & 0x8000)
		{
			inventoryScreen();
			break;
		}
	}
}

void renderPlayer()
{
	//Blank old player position.
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << '.';
	map[playerPositionY * playerPositionX] = '.';

	//Draw new player position.
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;
	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;
	map[playerPositionY * playerPositionX] = playerChar;
}


//Handles item rendering.
void renderItem()
{
	//srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		itemPosX = rand() % LEVELWIDTH;
		itemPosY = rand() % LEVELHEIGHT;

		if (map[itemPosY * itemPosX] == '.' || map[itemPosY * itemPosX] == '@' || map[itemPosY * itemPosX] == '?' || 
			map[itemPosY * itemPosX] == '/' || map[itemPosY * itemPosX] == '+')
		{
			gotoScreenPosition(itemPosX, itemPosY);
			std::cout << itemChar;
			map[itemPosY * itemPosX] = itemChar;
		}
		else
		{
			renderItem();
		}
	}
}

//Renders enemy
void renderEnemy()
{
	if (map[enemyPosY * enemyPosX] == '.')
	{
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << enemyChar;
		map[enemyPosY * enemyPosX] = enemyChar;
	}
	else
	{
		renderEnemy();
	}
}

//Lets enemy move toward player
void moveEnemy()
{
	if (enemyPosX > playerPositionX)
	{
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << '.';
		map[enemyPosY * enemyPosX] = '.';

		enemyPosX = enemyPosX - 1;
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << enemyChar;
		map[enemyPosY * enemyPosX] = enemyChar;
	}
	else if (enemyPosX < playerPositionX)
	{
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << '.';
		map[enemyPosY * enemyPosX] = '.';

		enemyPosX = enemyPosX + 1;
		gotoScreenPosition(enemyPosX, enemyPosY);
		std::cout << enemyChar;
		map[enemyPosY * enemyPosX] = enemyChar;
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
	renderMap(&map[0 * 0], LEVELWIDTH, LEVELHEIGHT);

	//Renders items.
	renderItem();

	renderEnemy();

	//Makes item have relevant char when it is dropped.
	itemAssign();

	//Initial player render.
	renderPlayer();


	while (true)
	{
		//Handles the input and updates the players position.
		handleInput();

		//Render the scene.
		renderPlayer();

		moveEnemy();

		readMap();

		//Render the GUI.
		renderGUI();

		//Makes cursor not visible.
		set_cursor(false);
	}

	system("pause");
}