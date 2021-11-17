#pragma once
#include <windows.h>
using namespace std;

class enemy
{
public:
	enemy(char enemyCharParam, int posxParam, int posyParam, int healthParam);
	int getEnemyPositionX();
	int getEnemyPositionY();
	char getEnemyChar();

private:
	int enemyPositionX;
	int enemyPositionY;
	char enemyChar;
	int health;
};
