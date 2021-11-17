#include "gamemanager.h"
#include "interface.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int gamemanager::getLevelWidth()
{
	return levelWidth;
}
void gamemanager::setLevelWidth(int widthParam)
{
	levelWidth = widthParam;
}
int gamemanager::getLevelHeight()
{
	return levelHeight;
}
void gamemanager::setLevelHeight(int heightParam)
{
	levelHeight = heightParam;
}

gamemanager::gamemanager(string levelName)
{
	this->levelName = levelName;
}

void gamemanager::renderEntity(player& p)
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

void gamemanager::renderNPC(npc& n)
{
		gotoScreenPosition(n.getNPCPositionX(), n.getNPCPositionY());
		std::cout << n.getModel();
		level[n.getNPCPositionY()][n.getNPCPositionX()] = n.getModel();
}

bool gamemanager::handleCollisions(int y, int x, player p, enemy e)
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
	case 'e':
		p.combat(e, p);
		return false;
		break;
	case 'M':
		//shop();
		return false;
		break;
	case '%':
		//new_level();
		return false;
		break;
	default:
		return true;
	}
}

void gamemanager::handleInput(player& p, enemy& e)
{
	Sleep(120);
	if (GetKeyState(VK_UP) & 0x8000 && handleCollisions(p.getplayerPositionY() - 1, p.getplayerPositionX(), p, e))
	{
		newPlayerPositionY = p.getplayerPositionY() - 1;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000 && handleCollisions(p.getplayerPositionY() + 1, p.getplayerPositionX(), p, e))
	{
		newPlayerPositionY = p.getplayerPositionY() + 1;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000 && handleCollisions(p.getplayerPositionY(), p.getplayerPositionX() + 1, p, e))
	{
		newPlayerPositionX = p.getplayerPositionX() + 1;
	}
	else if (GetKeyState(VK_LEFT) & 0x8000 && handleCollisions(p.getplayerPositionY(), p.getplayerPositionX() - 1, p, e))
	{
		newPlayerPositionX = p.getplayerPositionX() - 1;
	}
	if (GetKeyState('I') & 0x8000)
	{
		inventoryScreen(p);
	}
}

void gamemanager::readMap()
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

void gamemanager::renderMap()
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

void gamemanager::renderItem()
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