#include "map.h"
#include "interface.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int map::getLevelWidth()
{
	return levelWidth;
}
void map::setLevelWidth(int widthParam)
{
	levelWidth = widthParam;
}
int map::getLevelHeight()
{
	return levelHeight;
}
void map::setLevelHeight(int heightParam)
{
	levelHeight = heightParam;
}

map::map(string levelName)
{
	this->levelName = levelName;
}

void map::renderEntity(player& p)
{
	//Blank old player position.
	gotoScreenPosition(p.getplayerPositionX(), p.getplayerPositionY());
	std::cout << '.';
	level[p.getplayerPositionY()][p.getplayerPositionX()] = '.';

	//Draw new player position.
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << p.getPlayerChar();
	p.setplayerPositionX(newPlayerPositionX);
	p.setplayerPositionY(newPlayerPositionY);
	level[p.getplayerPositionY()][p.getplayerPositionX()] = p.getPlayerChar();
}

void renderEnemy(enemy& e)
{
	if (level[e.getEnemyPositionY()][e.getEnemyPositionX()] == '.')
	{
		gotoScreenPosition(e.getEnemyPositionX(), e.getEnemyPositionY());
		std::cout << e.getEnemyChar();
		level[e.getEnemyPositionY()][e.getEnemyPositionX()] = e.getEnemyChar();
	}
	else
	{
		renderEnemy();
	}
}

bool map::handleCollisions(int y, int x, player p)
{
	char nextMove = level[y][x];

	switch (nextMove)
	{
	case '#':
		return false;
		break;
	case '.':
		return true;
		break;
	case '?':
		p.itemCheck();
		return true;
		break;
	case '+':
		//itemPickup('+');
		return true;
		break;
	case '/':
		//itemPickup('/');
		return true;
		break;
	default:
		return true;
	}
}

void map::handleInput(player p)
{
	Sleep(120);
	if (GetKeyState(VK_UP) & 0x8000 && handleCollisions(p.getplayerPositionY() - 1, p.getplayerPositionX(), p))
	{
		newPlayerPositionY = p.getplayerPositionY() - 1;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000 && handleCollisions(p.getplayerPositionY() + 1, p.getplayerPositionX(), p))
	{
		newPlayerPositionY = p.getplayerPositionY() + 1;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000 && handleCollisions(p.getplayerPositionY(), p.getplayerPositionX() + 1, p))
	{
		newPlayerPositionX = p.getplayerPositionX() + 1;
	}
	else if (GetKeyState(VK_LEFT) & 0x8000 && handleCollisions(p.getplayerPositionY(), p.getplayerPositionX() - 1, p))
	{
		newPlayerPositionX = p.getplayerPositionX() - 1;
	}
	if (GetKeyState('I') & 0x8000)
	{
		inventoryScreen(p);
	}
}

void map::readMap()
{
	char buff[BUFFSIZE];
	string line;
	fstream infile(levelName);
	if (infile.is_open())
	{
		levelHeight = 0;
		while (getline(infile, line))
		{
			levelHeight++;
		}
		levelWidth = line.length();
	}
	infile.close();

	infile.open(levelName);
	stringstream ss;
	if (infile.is_open())
	{
		for (int row = 0; row < levelHeight; row++)
		{
			infile.getline(buff, BUFFSIZE);
			ss << buff;

			for (int col = 0; col < levelWidth; col++)
			{
				level[row][col] = buff[col];
			}
			ss << "";
			ss.clear();
		}
	}
	infile.close();
}

void map::renderMap()
{
	gotoScreenPosition(0, 0);
	for (int i = 0; i < levelHeight; i++)
	{
		for (int j = 0; j < levelWidth; j++)
		{
			cout << level[i][j];
		}
		cout << endl;
	}
}

void map::renderItem()
{
	srand((unsigned int)time(NULL));
	for (int j = 0; j < 4; j++)
	{
		itemPosX = rand() % levelWidth;
		itemPosY = rand() % levelHeight;
		if (level[itemPosY][itemPosX] == '.')
		{
			gotoScreenPosition(itemPosX, itemPosY);
			std::cout << itemChar;
			level[itemPosY][itemPosX] = itemChar;
		}
		else
		{
			j--;
		}
	}
}