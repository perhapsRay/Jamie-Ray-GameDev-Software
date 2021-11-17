#pragma once
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "player.h"
#include "enemy.h"
using namespace std;

class map
{
public:
	map(string levelName);
	int getLevelWidth();
	void setLevelWidth(int widthParam);
	int getLevelHeight();
	void setLevelHeight(int heightParam);
	void readMap();
	void renderMap();
	void renderItem();
	void renderEntity(player& p);
	void renderEnemy(enemy& e);
	bool handleCollisions(int y, int x, player p);
	void handleInput(player p);
	
private:
	static const int LEVELWIDTH = 100;
	static const int LEVELHEIGHT = 20;
	static const int BUFFSIZE = 100;

	string levelName;
	int levelHeight = 0;
	int levelWidth = 0;
	char level[LEVELHEIGHT][LEVELWIDTH + 1];

	unsigned int itemPosX;
	unsigned int itemPosY;
	char itemChar = '?';
};