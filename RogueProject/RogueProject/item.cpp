#include "item.h"
using namespace std;


item::item(char modelParam, string nameParam, int IDParam)
{
	model = modelParam;
	name = nameParam;
	ID = IDParam;
}

weapon::weapon(char modelParam, string nameParam, int IDParam)
	: item(modelParam, nameParam, IDParam)
{

}

potion::potion(char modelParam, string nameParam, int IDParam)
	: item(modelParam, nameParam, IDParam)
{

}

armour::armour(char modelParam, string nameParam, int IDParam)
	: item(modelParam, nameParam, IDParam)
{

}

char item::getModel()
{
	return model;
}
string item::getName()
{
	return name;
}
int item::getID()
{
	return ID;
}

