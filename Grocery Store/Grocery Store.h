
#ifndef _GroceryStore_
#define _GroceryStore_

#include "Item.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>

using namespace std;

class GroceryStore
{
private:
	vector<Item>items;
	jmp_buf money;
public:
	void AddItem(string n, int s, double p, char c);
	void Print();
	int FindName(string name);
	void SetPrice(string name, double price);
	double GetPrice(string name);
	int GetSize(string name);
	vector<string>GetItems(char category);





};

#endif

