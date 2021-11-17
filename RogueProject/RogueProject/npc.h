#pragma once
#include <windows.h>
using namespace std;


class npc
{
public:
	npc(char modelParam, int posxParam, int posyParam);
	char getModel();
	int getNPCPositionX();
	int getNPCPositionY();

private:
	char model;
	int npcPositionX;
	int npcPositionY;
};

class merchant : public npc
{
public:
	merchant(char modelParam, int posxParam, int posyParam, int goldParam);
	int getGold();
	void setGold(int goldParam);
private:
	int gold;
};

class enemy : public npc
{
public:
	enemy(char modelParam, int posxParam, int posyParam, int healthParam, int maxHealthParam, int damageParam);
	int getHealth();
	int getMaxHealth();
	void setHealth(int healthParam);
	int getDamage();
private:
	int health;
	int maxHealth;
	int damage;
};