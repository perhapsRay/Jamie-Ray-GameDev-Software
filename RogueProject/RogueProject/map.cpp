#include "map.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int map::getLevelWidth()
{
	return levelWidth;
}
void map::setLevelWidth(int widthParam)
{
	levelWidth = widthParam;
}
int map::getLevelHeight()
{
	return levelHeight;
}
void map::setLevelHeight(int heightParam)
{
	levelHeight = heightParam;
}


map::map(string levelName)
{
	string level = levelName;
}

void map::readMap()
{
	char buff[BUFFSIZE];
	string line;
	fstream infile("map_1.txt");
	if (infile.is_open())
	{
		levelHeight = 0;
		while (getline(infile, line))
		{
			levelHeight++;
		}
		levelWidth = line.length();
	}
	infile.close();

	infile.open("map_1.txt");
	stringstream ss;
	if (infile.is_open())
	{
		for (int row = 0; row < levelHeight; row++)
		{
			infile.getline(buff, BUFFSIZE);
			ss << buff;

			for (int col = 0; col < levelWidth; col++)
			{
				level[row][col] = buff[col];
			}
			ss << "";
			ss.clear();
		}
	}
	infile.close();
}

void map::renderMap()
{
	for (int i = 0; i < levelHeight; i++)
	{
		for (int j = 0; j < levelWidth; j++)
		{
			cout << level[i][j];
		}
		cout << endl;
	}
}