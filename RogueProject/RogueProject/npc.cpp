#include "npc.h"

npc::npc(char modelParam, int posxParam, int posyParam)
{
	model = modelParam;
	npcPositionX = posxParam;
	npcPositionY = posyParam;
}

char npc::getModel()
{
	return model;
}

int npc::getNPCPositionX()
{
	return npcPositionX;
}

int npc::getNPCPositionY()
{
	return npcPositionY;
}

merchant::merchant(char modelParam, int posxParam, int posyParam, int goldParam)
	: npc(modelParam, posxParam, posyParam)
{
	gold = goldParam;
}

int merchant::getGold()
{
	return gold;
}

void merchant::setGold(int goldParam)
{
	gold = goldParam;
}

enemy::enemy(char modelParam, int posxParam, int posyParam, int healthParam, int maxHealthParam, int damageParam)
	: npc(modelParam, posxParam, posyParam)
{
	health = healthParam;
	maxHealth = maxHealthParam;
	damage = damageParam;
}

int enemy::getHealth()
{
	return health;
}

int enemy::getMaxHealth()
{
	return maxHealth;
}

int enemy::getDamage()
{
	return damage;
}

void enemy::setHealth(int healthParam)
{
	health = healthParam;
}