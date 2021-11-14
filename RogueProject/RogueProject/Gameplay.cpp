#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "map.h"
using namespace std;

unsigned int newPlayerPositionX;
unsigned int newPlayerPositionY;


void set_cursor(bool visible) 
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);
	player gamePlayer('@', 5, 5);
	map map1("map_1.txt");


	newPlayerPositionX = gamePlayer.getplayerPositionX();
	newPlayerPositionY = gamePlayer.getplayerPositionY();
	//Initial player render.
	map1.renderEntity(gamePlayer);
	map1.readMap();

	while (true)
	{
		//Handles the input and updates the players position.
		map1.handleInput(gamePlayer);
		//Render the scene.

		map1.renderMap();
		map1.renderEntity(gamePlayer);
		//renderGUI();
		//Makes cursor not visible.
		set_cursor(false);
	}
	system("pause");
}