#pragma once
#include <windows.h>
#include <vector>
#include "Gameplay.h"
#include "item.h"
#include "npc.h"
using namespace std;

class player
{
public:
	player(char charParam, int posxParam, int posyParam, int healthParam, int maxHealthParam, int damageParam);
	int getplayerPositionX();
	void setplayerPositionX(int playerPositionXParam);
	int getplayerPositionY();
	void setplayerPositionY(int playerPositionYParam);
	char getPlayerChar();
	int getDamage();
	int getHealth();
	void setHealth(int healthParam);
	int getMaxHealth();
	int getItemNumber();
	void setItemNumber(int itemNumParam);
	void itemCheck();
	void combat(enemy& e, player& p);
	//int getGold();
	//void setGold(int goldParam);
	vector<item> getInventory();
	void setInventory(vector<item> inventoryParam);

private:
	int playerPositionX;
	int playerPositionY;
	char playerChar;
	int health;
	int maxHealth;
	int damage;
	//int gold;
	vector<item> inventory;
};
