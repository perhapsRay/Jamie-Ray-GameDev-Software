#pragma once
#include <windows.h>
using namespace std;

class enemy
{
public:
	enemy(char enemyCharParam, int posxParam, int posyParam, int healthParam, int maxHealthParam, int damageParam);
	int getEnemyPositionX();
	int getEnemyPositionY();
	char getEnemyChar();
	int getDamage();
	int &getHealth();
	int getMaxHealth();
	void setHealth(int healthParam);

private:
	int enemyPositionX;
	int enemyPositionY;
	char enemyChar;
	int damage;
	int health;
	int maxHealth;
};
