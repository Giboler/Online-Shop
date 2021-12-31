#include "ShoppingCart.h"
void ShoppingCart::checkOut() {
	cout << "Select payment method:" << endl;
	char choice;
	cout << "Option 1: Paypal." << endl;
	cout << "Option 2: Cash on Delivery." << endl;
	cout << "Choose: "; cin >> choice;
	while (true) {

		if (choice == '1') {
			cout << "Paypal selected, Please keep track of your delivery with your post office!" << endl;
			break;
		}
		else if (choice == '2') {
			cout << "Cash on delivery selected, Please keep track of your delivery with your post office!" << endl;
			break;
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
		}
	}
	remove("Shopping Cart.txt");
}
void ShoppingCart::shoppingStart()
{
	char choice;
	cout << "Option 1: Add a product to cart." << endl;
	cout << "Option 2: View cart." << endl;
	cout << "Option 3: Delete an order." << endl;
	cout << "Option 4: Check out." << endl;
	cout << "Choose: "; cin >> choice;
	while (true) {
		
		if (choice == '1') {
			displayAll();
			placeOrder();
			break;
		}
		else if (choice == '2') {
			viewOrders();
			calculateCost();
			break;
		}
		else if (choice == '3') {
			string n;
			cout << "Enter the name of the product to delete: ";
			cin >> n;
			removeOrder(n);
			break;
		}
		else if (choice == '4') {
			checkOut();
			break;
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
		}
	}
	char choice2;
	cout << "Would you like to do something else in the shopping cart?(y/n): "; cin >> choice2;
	if (choice2 == 'y') {
		shoppingStart();
	}
	else {
		NULL;
	}
}