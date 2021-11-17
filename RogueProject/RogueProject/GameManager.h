#pragma once
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "player.h"
#include "npc.h"
using namespace std;

class gamemanager
{
public:
	gamemanager(string levelName);
	int getLevelWidth();
	void setLevelWidth(int widthParam);
	int getLevelHeight();
	void setLevelHeight(int heightParam);
	void readMap();
	void renderMap();
	void renderItem();
	void renderEntity(player& p);
	void renderNPC(npc& n);
	bool handleCollisions(int y, int x, player p, enemy e);
	void handleInput(player& p, enemy& e);
	
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