#pragma once
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;


class item
{
public:
	item(char modelParam, string nameParam, int IDParam);
	char getModel();
	string getName();
	int getID();

private:
	char model;
	string name;
	int ID;
};

class weapon : public item
{
public:
	weapon(char modelParam, string nameParam, int IDParam);
private:
	int damage = 5;
};

class potion : public item
{
public:
	potion(char modelParam, string nameParam, int IDParam);
private:
	int healing = 5;
};

class armour : public item
{
public:
	armour(char modelParam, string nameParam, int IDParam);
private:
	int defence = 5;
};