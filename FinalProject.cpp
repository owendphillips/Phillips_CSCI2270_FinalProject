#include <iostream>
#include <fstream>
#include "FPHeader.hpp"
using namespace::std;
int main() 
{
	estore store;	//CREATES OBJECT
	vertex *start = new vertex;	//CREATES STARTING VERTEX
	vertex *hashTable[701];	//CREATES HASHTABLE ARRAY
	for (int i = 0; i < 701; i++)	//SETS ALL EMPTY SPOTS IN HASHTABLE TO NULLPTR
	{
		hashTable[i] = nullptr;
	}
	int whatdo = 0;
	cout << "Enter filename: ";
	string filename;
	getline(cin, filename);
	ifstream file(filename);	//CREATES STREAM
	if (file.is_open())	//READS FROM THE FILE IF IT IS FOUND
	{
		char *point;
		char str[100];
		string line;
		while (getline(file, line))	   //GETS EACH LINE AND TOKENIZES IT, PASSING IT INTO A NEW VERTEX
		{
			vertex *item = new vertex;
			strcpy(str, line.c_str());
			point = strtok (str, ",\n");
			item->product = point;
			point = strtok (NULL, ",");
			item->cost = atoi(point);
			point = strtok (NULL, ",");
			item->category = point;
			point = strtok (NULL, ",");
			store.addVertex(start,item);	//ADDS THE VERTEX TO THE GRAPH
			hashTable[store.hash(item, 701)] = item;	//ADDS VERTEX TO HASH TABLE
		}
		while (whatdo != 5)	//RUNS WHILE 5(QUIT) IS NOT ENTERED
		{
			cout << ".-*^Welcome to Estore!^*-." << endl;	//MENU
			cout << "1. View inventory" << endl;
			cout << "2. Search inventory" << endl;
			cout << "3. View Shopping Cart" << endl;
			cout << "4. Checkout" << endl;
			cout << "5. Quit Program" << endl;
			cin >> whatdo;
			if (whatdo == 1)	//CALLS PRINTING METHOD
			{
				store.printInventory(start);
			}
			if (whatdo == 2)	//PROMPTS USER FOR NAME OF PRODUCT, THEN CALLS METHOD TO SEARCH FOR IT
			{
				cout << "Enter product name:" << endl;
				string name;
				getline(cin, name);
				getline(cin, name);
				vertex* point = store.hashSearch(name, hashTable, 701);
				if (point != nullptr)	//IF IT IS FOUND, ASKS THE USER IF THEY WANT TO ADD IT TO THE CART. IF SO, THE METHOD FOR THAT IS CALLED
				{	
					cout << "Name: " << point->product << endl;
					cout << "Cost: " << point->cost << endl;
					cout << '\n' << "Add to cart?  [y/n]" << endl;
					char yn;
					cin >> yn;
					if (yn == 'y')
					{
						store.addToCart(point);
					}
				}
			}
			if (whatdo == 3)	//CALLS METHOD FOR PRINTING CONTENTS OF CART
			{
				store.viewCart();
			}
			if (whatdo == 4)	//CALLS METHOD THAT EMPTIES THE CART AND PRINTS ITS TOTAL
			{
				store.checkout();
			}
		}	 
	}
	else	//PRINTS AN ERROR IF THE ENTERED FILE CAN'T BE FOUND
	{
		cout << "File not found!!!" << endl;
	}
}
