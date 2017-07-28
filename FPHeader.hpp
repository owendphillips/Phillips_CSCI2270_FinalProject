#ifndef FPHEADER
#define FPHEADER
#include <vector>
using namespace::std;
struct vertex	//VERTEX STRUCT
{
	string product;
	int cost;
	string category;
	vector<vertex*> adj;
};
struct shoppingCart
{
	vertex* item;
	int num;
};
class estore	//VERY IMPORTANT CLASS
{
	private:
		vector<shoppingCart*> cart;
	public:
		estore();
		~estore();
		void addToCart(vertex*);	//ADDS AN ITEM TO THE CART
		void addVertex(vertex*, vertex*);	//ADDS VERTEX THE GRAPH
		void printInventory(vertex*);	//PRINTS EVERYTHING IN THE GRAPH
		int hash(vertex*, int);		//CALCULATES THE HASH VALUE FOR A VERTEX
		vertex* hashSearch(string, vertex*[], int);		//RETURNS A POINTER TO VERTEX CONTAINING STRING
		void viewCart();	//PRINTS EVERYTHING IN THE CART
		void checkout();
};
estore::estore()	//CONSTRUCTOR
{
	
}
estore::~estore()	//DESTRUCTOR
{
	cout << "Goodbye!";
}
void estore::addVertex(vertex* start, vertex* newVertex)	//ADDS A NEW VERTEX
{
	if (!start->adj.empty())
	{
		for (int i = 0; i < start->adj.size(); i++)	   //LINKS NEW VERTEX TO VERTICES OF SAME CATEGORY
		{
			vertex *temp = start->adj[i];
			if (temp->category == newVertex->category)
			{
				temp->adj.push_back(newVertex);
				newVertex->adj.push_back(temp);
			}
		}
	}
	start->adj.push_back(newVertex);	//LINKS VERTEX TO STARTING VERTEX
}
void estore::printInventory(vertex* start) 	//PRINTS EVERYTHING IN THE GRAPH
{
	cout << "Inventory:" << endl;
	vector<string> cat;		//VECTOR CONTAINING PREVIOUSLY FOUND CATEGORIES
	cat.push_back("");
	bool toPrint;
	for (int i = 0; i < start->adj.size(); i++)	//RUNS THROUGH EVERY VERTEX
	{
		vertex *temp = start->adj[i];
		for (int j = 0; j < cat.size(); j++)	//CHECKS IF IT IS A NEW CATEGORY
		{
			if (cat[j] == temp->category)
			{
				toPrint = false;
				break;
			}
			else 
			{
				toPrint = true;
			}
		}
		if (toPrint == true) 	//PRINTS EVERYTHING IN THE CATEGORY IF NOT PREVIOUSLY PRINTED
		{
			cat.push_back(temp->category);
			cout << "Category: " << temp->category << endl;
			cout << "	" << temp->product << ", $" << temp->cost << endl;
			for (int k = 0; k < temp->adj.size(); k++)
			{
				cout << "	" << temp->adj[k]->product << ", $" << temp->cost << endl;
			}
		}
	}
}
int estore::hash(vertex* temp, int size)	//TAKES PRODUCT NAME FROM VERTEX AND RETURNS ITS HASH VALUE
{
	string name = temp->product;
	int sum = 0;
	for (int i = 0; i < name.length(); i++)
	{
		sum = sum + name[i];
	}
	sum = sum % size;
return sum;
}
vertex* estore::hashSearch(string name, vertex* arr[], int size) //GENERATES HASH VALUE FROM ENTERED NAME AND CHECKS TO SEE IF IT IS IN TABLE.
//IF IT IS, IT RETURNS THE POINTER TO THE MATCHING VERTEX, OTHERWISE IT RETURNS NULLPTR
{
	int sum = 0;
	for (int i = 0; i < name.length(); i++)
	{
		sum = sum + name[i];
	}
	sum = sum % size;
	if (arr[sum] != nullptr && arr[sum]->product == name)
	{
		return arr[sum];
	}
	else
	{
		cout << "Item not found." << endl;
		return nullptr;
	}
}
void estore::addToCart(vertex* v)	//ADDS A VERTEX TO CART VECTOR, ALONG WITH THE NUMBER BEING ADDED
{
	cout << "How many would you like to add?" << endl;
	int quantity;
	cin >> quantity;
	shoppingCart* sc = new shoppingCart;
	sc->item = v;
	sc->num = quantity;
	cart.push_back(sc);
	cout << "Item added" << endl;
	cout << '\n' << "You might also like:" << endl;	//RECOMMENDS OTHER PRODUCTS, WHICH ARE ALL THE ADJACENT VERTICES
	for (int i = 0; i < v->adj.size(); i++)
	{
		cout << v->adj[i]->product << ", $" << v->adj[i]->cost << endl;
	}
}
void estore::viewCart()	//PRINTS EVERYTHING IN CART VECTOR
{
	int total = 0;
	if (!cart.empty())
	{
		for (int i = 0; i < cart.size(); i++)
		{
			cout << "Item: " << cart[i]->item->product << endl;
			cout << "Cost: $" << cart[i]->item->cost << " x " << cart[i]->num << " = $" << cart[i]->item->cost * cart[i]->num << endl;
			total = total + (cart[i]->item->cost * cart[i]->num);
		}
		cout << "Total: $" << total << endl;
	}
	else
	{
		cout << "Cart is empty" << endl;
	}
}
void estore::checkout()	//TOTALS EVERYTHING IN THE CART AND EMPTIES IT
{
	int total = 0;
	for (int i = 0; i < cart.size(); i++)
	{
		cout << "Item: " << cart[i]->item->product << " , Cost: $" << cart[i]->item->cost * cart[i]->num << endl;
		total = total + (cart[i]->item->cost * cart[i]->num);
	}
	cout << "Total: $" << total << endl;
	cart.clear();
}
#endif
