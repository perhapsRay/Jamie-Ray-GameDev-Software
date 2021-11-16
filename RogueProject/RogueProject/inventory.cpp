#include "inventory.h"
#include <iostream>

void inventory::itemCheck()
{
	srand(time(NULL));
	itemNumber = rand() % 2;
	if (itemNumber == 0)
	{
		bag.push_back(potion);
		item.push_back(itemNumber);
	}
	else if (itemNumber == 1)
	{
		bag.push_back(sword);
		item.push_back(itemNumber);
	}
}

/*void inventory::inventoryScreen()
{
	system("CLS");
	gotoScreenPosition(0, 0);
	cout << "Inventory:";


	for (int i = 0; i < inventory.size(); i++)
	{
		gotoScreenPosition(2, 2 + i);
		cout << i + 1 << ". " << inventory[i];
	}

	//Drop item.
	while (true)
	{
		if (GetKeyState('I') & 0x8000)
		{
			break;
		}

		if (inventory.size() <= 0)
		{
			gotoScreenPosition(2, 2);
			cout << "Inventory is empty!";
			continue;
		}

		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			Sleep(120);
			while (true)
			{
				if (GetKeyState(0x31) & 0x8000)
				{
					dropItem(0);
					break;
				}
				if (GetKeyState(0x32) & 0x8000)
				{
					dropItem(1);
					break;
				}
				if (GetKeyState(0x33) & 0x8000)
				{
					dropItem(2);
					break;
				}
			}
			break;
		}

	}
	system("CLS");
	renderMap();
}*/