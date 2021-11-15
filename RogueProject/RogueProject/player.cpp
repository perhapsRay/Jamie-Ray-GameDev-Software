#include "player.h"
#include <iostream>


player::player(char charParam, int posxParam, int posyParam, int healthParam, int maxHealthParam)
{
	playerPositionX = posxParam;
	playerPositionY = posyParam;
	playerChar = charParam;
	health = healthParam;
	maxHealth = maxHealthParam;
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
int player::getHealth()
{
	return health;
}
int player::getMaxHealth()
{
	return maxHealth;
}