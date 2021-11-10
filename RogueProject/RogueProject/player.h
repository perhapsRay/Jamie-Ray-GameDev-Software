#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class player
{

public:
	int getplayerPositionX();
	void setplayerPositionX(int playerPositionXParam);
	int getplayerPositionY();
	void setplayerPositionY(int playerPositionYParam);
	void handleInput();

private:
	int playerPositionX = 5;
	int playerPositionY = 5;
	char playerChar = '@';
	//int newPlayerPositionX = playerPositionX;
	//int newPlayerPositionY = playerPositionY;
};
