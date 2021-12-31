#include "OnlineShop.h"
void OnlineShop::start1()
{
	string choice;
	cout << "Option 1: Product Section." << endl;
	cout << "Option 2: Shopping cart." << endl;
	while (true) {
		line = "";
		cout << "Choose: "; cin >> choice;
		if (choice == "1") {
			productStart();
			break;
		}
		else if (choice == "2") {
			shoppingStart();
			break;
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
		}
	}
	string choice2;
	cout << "Would you like to do something else in the store?(y/n): "; cin >> choice2;
	if (choice2 == "y") {
		start1();
	}
	else {
		NULL;
	}
}
void OnlineShop::startAll()
{
	cout << "Welcome to Online store!" << endl;
	if (custStart()) {
		start1();
	}
}