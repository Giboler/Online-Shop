#include "Orders.h"
void Orders::placeOrder()
{
	string n;
	cout << "Enter the name of the product to add to cart: ";
	cin >> n;
	if (searchProducts(n)) {
		cout << "Order added to cart!" << endl;
	}
	else {
		placeOrder();
	}
	fstream table;
	table.open("Shopping Cart.txt", ios::app);
	table << line;
	table.close();
}
void Orders::viewOrders(){
	fstream table;
	table.open("Shopping Cart.txt", ios::in);
	cout << "Here are all the items in your cart:" << endl;
	while (!table.eof()) {
		getline(table, line);
		if (line == "") {
			break;
		}
		cout << line << endl;
	}
	table.close();
}
void Orders::removeOrder(string n) {
	string key;
	key = n;
	fstream table1;
	fstream table2;
	table2.open("updatedData.txt", ios::out | ios::app);
	table1.open("Shopping Cart.txt", ios::in);
	while (!table1.eof())
	{
		getline(table1, line);
		if (line == "") {
			break;
		}
		unpack();
		if (key == productName) {
			cout << "Deleted!" << endl;
			continue;
		}
		pack();
		table2 << line;
	}
	table1.close();
	table2.close();
	remove("Shopping Cart.txt");
	rename("updatedData.txt", "Shopping Cart.txt");
}
void Orders::calculateCost() {
	int total = 0;
	fstream table;
	table.open("Shopping Cart.txt", ios::in);
	while (!table.eof()) {
		getline(table, line);
		if (line == "") {
			break;
		}
		unpack();
		 total += productCost;
	}
	cout << "Total Cost: " << total << endl;
	table.close();
}