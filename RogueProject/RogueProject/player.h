#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "Gameplay.h"
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
	int getHealth();
	int getMaxHealth();
	//void handleInput();
	//bool handleCollisions(int y, int x);
	//void render();
	

private:
	int playerPositionX;
	int playerPositionY;
	char playerChar;
	int health;
	int maxHealth;
};
