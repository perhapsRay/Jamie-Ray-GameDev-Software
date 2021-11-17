#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "enemy.h"
#include "map.h"
using namespace std;

player gamePlayer('@', 5, 5, 20, 25, 5);
enemy gameEnemy('e', 32, 2, 20, 20, 2);
unsigned int newPlayerPositionX;
unsigned int newPlayerPositionY;

void set_cursor(bool visible) 
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void renderGUI()
{
	gotoScreenPosition(2, MAXLEVELHEIGHT + 3);
	std::cout << "Health: " << gamePlayer.getHealth() << "/" << gamePlayer.getMaxHealth();
}

void main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);
	map map1("map_1.txt");

	newPlayerPositionX = gamePlayer.getplayerPositionX();
	newPlayerPositionY = gamePlayer.getplayerPositionY();
	//Initial player render.
	map1.renderEntity(gamePlayer);
	map1.readMap();
	map1.renderItem();
	renderGUI();

	while (true)
	{
		map1.handleInput(gamePlayer, gameEnemy);

		map1.renderMap();

		map1.renderEntity(gamePlayer);

		map1.renderEnemy(gameEnemy);

		set_cursor(false);
	}
	system("pause");
}