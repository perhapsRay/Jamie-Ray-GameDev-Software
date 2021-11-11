#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "source.h"
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
	
private:
	static const int LEVELWIDTH = 100;
	static const int LEVELHEIGHT = 20;
	static const int BUFFSIZE = 100;

	string level;
	int levelHeight = 0;
	int levelWidth = 0;

	char level[LEVELHEIGHT][LEVELWIDTH + 1];
};