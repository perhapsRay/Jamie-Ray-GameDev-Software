#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "source.h"
using namespace std;

class player
{

public:
	player(char charParam, int posxParam, int posyParam);
	int getplayerPositionX();
	void setplayerPositionX(int playerPositionXParam);
	int getplayerPositionY();
	void setplayerPositionY(int playerPositionYParam);
	char getPlayerChar();
	void handleInput();
	bool handleCollisions(int y, int x);
	void render();
	

private:
	int playerPositionX;
	int playerPositionY;
	char playerChar;
};
