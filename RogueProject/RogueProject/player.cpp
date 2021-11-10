#include "player.h"
#include <iostream>

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

void player::handleInput()
{
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