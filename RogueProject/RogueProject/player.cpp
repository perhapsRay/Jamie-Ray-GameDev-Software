#include "player.h"
#include "source.h"
#include <iostream>


player::player(char charParam, int posxParam, int posyParam)
{
	playerPositionX = posxParam;
	playerPositionY = posyParam;
	playerChar = charParam;
}

int player::getplayerPositionX()
{
	return playerPositionX;
}
void player::setplayerPositionX(int playerPositionXParam)
{
	playerPositionX = playerPositionXParam;
}
int player::getplayerPositionY()
{
	return playerPositionY;
}
void player::setplayerPositionY(int playerPositionYParam)
{
	playerPositionY = playerPositionYParam;
}
char player::getPlayerChar()
{
	return playerChar;
}

bool player::handleCollisions(int y, int x)
{
	char nextMove = map[y][x];

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

void player::handleInput()
{
	Sleep(120);
	if (GetKeyState(VK_UP) & 0x8000 && handleCollisions(playerPositionY - 1, playerPositionX))
	{
		newPlayerPositionY = playerPositionY - 1;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000 && handleCollisions(playerPositionY + 1, playerPositionX))
	{
		newPlayerPositionY = playerPositionY + 1;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000 && handleCollisions(playerPositionY, playerPositionX + 1))
	{
		newPlayerPositionX = playerPositionX + 1;
	}
	else if (GetKeyState(VK_LEFT) & 0x8000 && handleCollisions(playerPositionY, playerPositionX - 1))
	{
		newPlayerPositionX = playerPositionX - 1;
	}

	/*if (GetKeyState('I') & 0x8000)
	{
		inventoryScreen();
		break;
	}*/
}

void player::render()
{
	//Blank old player position.
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << '.';
	map[playerPositionX][playerPositionY] = '.';

	//Draw new player position.
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;
	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;
	map[playerPositionY][playerPositionX] = playerChar;
}