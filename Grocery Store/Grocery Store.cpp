#include "Item.h"
#include "Grocery Store.h"


void GroceryStore::AddItem(string n, int s, double p, char c)
{
	items.push_back(Item(n, s, p, c));
}

void GroceryStore::Print()
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << "          Report of Items           " << endl;
		cout << "------------------------------------" << endl;
		cout << "Item " << i << " name: " << items[i].getName() << endl;
		cout << "Item " << i << " size: " << items[i].getSize() << endl;
		cout << "Item " << i << " price: " << items[i].getPrice() << endl;
		cout << "Item " << i << " category: " << items[i].getCategory() << endl;
		cout << "------------------------------------" << endl;
	}
}

int GroceryStore::FindName(string name)
{
	for (int i = 0; i < items.size(); i++)
	{

		if (items[i].getName() == name) //checks where the item to be found is found at if found
			return i;

	}


	return -1; //if not found
}

void GroceryStore::SetPrice(string name, double price)
{
	if (FindName(name) == -1)
		cout << "Item not found" << endl;
	else
		items[FindName(name)].changePrice(price); //set new price

}

double GroceryStore::GetPrice(string name)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].getName() == name)
			return items[i].getPrice();
	}
	return -1;//if not found
}

int GroceryStore::GetSize(string name)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].getName() == name)
			return items[i].getSize();
	}
	return -1;//if not found}
}

vector<string>GroceryStore::GetItems(char category)
{
	vector<string>GetItems;

	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].getCategory() == category)
			GetItems.push_back(items[i].getName());
	}

	return GetItems;
}

