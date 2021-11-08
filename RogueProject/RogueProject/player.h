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
	void handleInput();

private:
	int playerPositionX = 5;
	int playerPositionY = 5;
	//int newPlayerPositionX = playerPositionX;
	//int newPlayerPositionY = playerPositionY;
	char playerChar = '@';
};
