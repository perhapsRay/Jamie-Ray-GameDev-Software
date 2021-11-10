#include "map.h"
#include <iostream>

int map::getLEVELWIDTH()
{
	return LEVELWIDTH;
}

int map::getLEVELHEIGHT()
{
	return LEVELHEIGHT;
}

int map::getBUFFSIZE()
{
	return BUFFSIZE;
}

void map::readMap()
{
	/*char buff[BUFFSIZE];
	fstream infile("map_1.txt");
	stringstream ss;
	if (infile.is_open())
	{
		for (int row = 0; row < LEVELHEIGHT; ++row)
		{
			infile.getline(buff, BUFFSIZE);
			ss << buff;

			for (int col = 0; col < LEVELWIDTH; ++col)
			{
				map[row][col] = buff[col];
			}
			ss << "";
			ss.clear();
		}
	}

	infile.close();*/
}

void map::renderMap()
{
	for (int i = 0; i < LEVELHEIGHT; i++)
	{
		cout << level[i] << endl;
	}
}