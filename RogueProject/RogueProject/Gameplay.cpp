#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "npc.h"
#include "GameManager.h"
using namespace std;

player gamePlayer('@', 5, 5, 20, 25, 5);
enemy gameEnemy('e', 32, 2, 20, 20, 2);
merchant shop('M', 2, 1, 100);
unsigned int newPlayerPositionX;
unsigned int newPlayerPositionY;
const int BUFFSIZE = 100;
const int MAXLEVELWIDTH = 100;
const int MAXLEVELHEIGHT = 20;

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
	gamemanager manager("map_1.txt");

	newPlayerPositionX = gamePlayer.getplayerPositionX();
	newPlayerPositionY = gamePlayer.getplayerPositionY();
	//Initial player render.
	manager.renderEntity(gamePlayer);
	manager.readMap();
	manager.renderItem();
	renderGUI();

	while (true)
	{
		manager.handleInput(gamePlayer, gameEnemy);

		manager.renderMap();

		manager.renderEntity(gamePlayer);

		manager.renderNPC(gameEnemy);
		manager.renderNPC(shop);

		set_cursor(false);
	}
	system("pause");
}