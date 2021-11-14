#include "player.h"
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