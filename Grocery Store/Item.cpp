
#include "Item.h"

Item::Item(string n, int s, double p, char c)
{
	name = n;
	size = s;
	price = p;
	category = c;
}

string Item::getName()
{
	return name;
}

int Item::getSize()
{
	return size;
}

double Item::getPrice()
{
	return price;
}

char Item::getCategory()
{
	return category;
}

void Item::changePrice(double newP)
{
	price = newP;
}