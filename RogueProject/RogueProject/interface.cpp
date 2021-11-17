#include "interface.h"

void gotoScreenPosition(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void inventoryScreen(player p)
{
	system("CLS");
	gotoScreenPosition(0, 0);
	cout << "Inventory:";


	for (int i = 0; i < p.getInventory().size(); i++)
	{
		gotoScreenPosition(2, 2 + i);
		cout << i + 1 << ". " << p.getInventory()[i].getName();
	}

	//Drop item.
	while (true)
	{
		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			break;
		}

		if (p.getInventory().size() <= 0)
		{
			gotoScreenPosition(2, 2);
		cout << "Inventory is empty!";
			continue;
		}

		/*if (GetKeyState(VK_SPACE) & 0x8000)
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
		}*/

	}
	system("CLS");
	//renderMap();
}