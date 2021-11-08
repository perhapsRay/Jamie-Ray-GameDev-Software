#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class player
{

private:
	unsigned int playerPositionX = 5;
	unsigned int playerPositionY = 5;
	unsigned int newPlayerPositionX = playerPositionX;
	unsigned int newPlayerPositionY = playerPositionY;
	char playerChar = '@';
};
