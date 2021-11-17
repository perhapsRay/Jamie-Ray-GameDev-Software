#include "player.h"

player::player(char charParam, int posxParam, int posyParam, int healthParam, int maxHealthParam)
{
	playerPositionX = posxParam;
	playerPositionY = posyParam;
	playerChar = charParam;
	health = healthParam;
	maxHealth = maxHealthParam;
}

weapon Sword('/', "Short Sword", 1);
potion Healing('+', "Potion of Healing", 2);

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

vector<item> &player::getInventory()
{
	return inventory;
}

void player::setInventory(vector<item> inventoryParam)
{
	inventory = inventoryParam;
}

void player::itemCheck()
{
	srand(time(NULL));
	int itemNumber = rand() % 2;
	if (itemNumber == 0)
	{
		getInventory().push_back(Sword);
	}
	else if (itemNumber == 1)
	{
		getInventory().push_back(Healing);
	}
}