#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class map
{
public:
	int getLEVELWIDTH();
	int getLEVELHEIGHT();
	int getBUFFSIZE();
	void readMap();
	void renderMap();
	
private:
	static const int LEVELWIDTH = 100;
	static const int LEVELHEIGHT = 20;
	const int BUFFSIZE = 100;
	char level[LEVELHEIGHT][LEVELWIDTH + 1];
};