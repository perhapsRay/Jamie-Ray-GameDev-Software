#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class inventory
{
public:

	void itemCheck();
	void inventoryScreen();

private:
	string potion = "Health potion.";
	string sword = "Sword.";
	int itemNumber;
	int itemnum;
	vector<string> inventory;
	vector<int> itemStore;
	vector<char> vItemChar;
};