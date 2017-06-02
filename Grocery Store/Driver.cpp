/*Isaac Reich
Grocery Store*/

#include "Grocery Store.h"
#include "Item.h"
#include<fstream>

void OpenFile(ifstream &infile)
{
	string file;
	do
	{
		cout << "Enter file name: ";
		cin >> file;

		infile.open(file);
		cout << "running" << endl;

	} while (infile.fail());


}

void LoadInventory(GroceryStore g)
{
	ifstream infile;
	OpenFile(infile);

	string n;
	int s;
	double p;
	char c;


	while (infile >> n) //if name keeps in infiling then the other variables are present
	{
		infile >> s;
		infile >> p;
		infile >> c;

		g.AddItem(n, s, p, c); //makes new item for each values apparent in file
	}

}

void ChangePrices(GroceryStore g)
{
	ifstream infile;
	OpenFile(infile); //file of new prices

	string n;
	double p;

	while (infile >> n)
	{
		infile >> p;

		g.SetPrice(n, p);
	}

}

string BargainItem(GroceryStore g, char c)
{
	ifstream infile;
	OpenFile(infile);

	LoadInventory(g);



	double up_check = (g.GetPrice(g.GetItems(c)[0])) / g.GetSize(g.GetItems(c)[0]); //unit price of first in category
	int where_; //where in vector the bargain is

	for (int i = 1; i < g.GetItems(c).size(); i++)
	{

		if ((g.GetPrice(g.GetItems(c)[i])) / g.GetSize(g.GetItems(c)[i]) < up_check);
		{
			up_check = (g.GetPrice(g.GetItems(c)[i])) / g.GetSize(g.GetItems(c)[i]);
			where_ = i;
		}
	}

	if (g.GetItems(c).size() > 0)
	{
		return g.GetItems(c)[where_];
	}
	else
		return "none";

}

int main()
{
	GroceryStore g;

	LoadInventory(g);

	g.Print();

	cout << endl << endl;

	ChangePrices(g);

	g.Print();

	cout << endl << endl;

	cout << "Bargain Produce:" << BargainItem(g, 'P') << endl;
	cout << "Bargain Meat:" << BargainItem(g, 'M') << endl;
	cout << "Bargain Dariy:" << BargainItem(g, 'D') << endl;
	cout << "Bargain Bakery:" << BargainItem(g, 'B') << endl;

	_getch();
	return 0;
}
