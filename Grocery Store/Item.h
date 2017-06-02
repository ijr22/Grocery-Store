#ifndef _Item_
#define _Item_

#include<iostream>
#include<conio.h>
#include<string>
#include<vector>

using namespace std;

class Item
{
private:
	string name;
	int size;
	double price;
	char category;

public:
	Item(string n, int s, double p, char c); //non-default constructor

	string getName();
	int getSize();
	double getPrice();
	char getCategory();  //accessor methods for item^

	void changePrice(double newP); //mutator method for item
};


#endif 

