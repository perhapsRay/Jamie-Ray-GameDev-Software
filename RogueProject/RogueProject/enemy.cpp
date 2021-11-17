#include "enemy.h"


enemy::enemy(char enemyCharParam, int posxParam, int posyParam, int healthParam, int maxHealthParam, int damageParam)
{
	enemyPositionX = posxParam;
	enemyPositionY = posyParam;
	enemyChar = enemyCharParam;
	health = healthParam;
	damage = damageParam;
	maxHealth = maxHealthParam;
}

int enemy::getEnemyPositionX()
{
	return enemyPositionX;
}

int enemy::getEnemyPositionY()
{
	return enemyPositionY;
}

char enemy::getEnemyChar()
{
	return enemyChar;
}

int enemy::getMaxHealth()
{
	return maxHealth;
}

int &enemy::getHealth()
{
	return health;
}


void enemy::setHealth(int healthParam)
{
	health = healthParam;
}

int enemy::getDamage()
{
	return damage;
}