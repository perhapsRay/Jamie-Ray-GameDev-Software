#include "enemy.h"


enemy::enemy(char enemyCharParam, int posxParam, int posyParam, int healthParam)
{
	enemyPositionX = posxParam;
	enemyPositionY = posyParam;
	enemyChar = enemyCharParam;
	health = healthParam;
}

int enemy::getEnemyPositionX()
{
	return enemyPositionX;
}

int enemy::getEnemyPositionY()
{
	return enemyPositionX;
}

char enemy::getEnemyChar()
{
	return enemyChar;
}