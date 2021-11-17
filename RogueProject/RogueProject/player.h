#pragma once
#include <windows.h>
#include <vector>
#include "Gameplay.h"
#include "item.h"
using namespace std;

class player
{
public:
	player(char charParam, int posxParam, int posyParam, int healthParam, int maxHealthParam);
	int getplayerPositionX();
	void setplayerPositionX(int playerPositionXParam);
	int getplayerPositionY();
	void setplayerPositionY(int playerPositionYParam);
	char getPlayerChar();
	vector<item> &getInventory();
	void setInventory(vector<item> inventoryParam);
	int getHealth();
	int getMaxHealth();
	int getItemNumber();
	void setItemNumber(int itemNumParam);
	void itemCheck();
	//void handleInput();
	//bool handleCollisions(int y, int x);
	//void render();
	

private:
	int playerPositionX;
	int playerPositionY;
	char playerChar;
	int health;
	int maxHealth;
	vector<item> inventory;
};
