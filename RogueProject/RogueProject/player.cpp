#include "player.h"

player::player(char charParam, int posxParam, int posyParam, int healthParam, int maxHealthParam, int damageParam)
{
	playerPositionX = posxParam;
	playerPositionY = posyParam;
	playerChar = charParam;
	health = healthParam;
	maxHealth = maxHealthParam;
	damage = damageParam;
	//gold = goldParam;
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
int player::getDamage()
{
	return damage;
}
void player::setHealth(int healthParam)
{
	health = healthParam;
}
/*int player::getGold()
{
	return gold;
}
void player::setGold(int goldParam)
{
	gold = goldParam;
}*/

vector<item> player::getInventory()
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
		inventory.push_back(Sword);	
	}
	else if (itemNumber == 1)
	{
		inventory.push_back(Healing);
	}
}

void player::combat(enemy& e, player& p)
{
	e.setHealth(e.getHealth() - damage);
	gotoScreenPosition(2, MAXLEVELHEIGHT + 4);
	std::cout << "Enemy: " << e.getHealth() << "/" << e.getMaxHealth();
	p.setHealth(p.getHealth() - e.getDamage());
	gotoScreenPosition(2, MAXLEVELHEIGHT + 3);
	std::cout << "Health: " << p.getHealth() << "/" << p.getMaxHealth();
}