#include "Customer.h"
void Customer::setData()
{
	setID();
	cout << "Please enter your username: "; cin >> userName;
	cout << "Please enter your full name (No Whitespaces): "; cin >> name;
	cout << "Please enter your address(No Whitespaces): "; cin >> address;
	cout << "Please enter your Phone Number: "; cin >> phone;
	cout << "Please enter your Email: "; cin >> email;
	while (true) {
		cout << "Please enter your Password: ";
		cin >> password;
		cout << "Please confirm your Password: ";
		cin >> confirmPass;
		if (confirmPass == password)
		{
			cout << "You have been registered succesfully!" << endl;
			break;
		}
		else {
			cout << "The passwords do not match, Please try again!" << endl;
		}
	}
}
void Customer::setID() {
	int counter = 0;
	fstream table;
	table.open("Accounts.txt", ios::in);
	while (!table.eof()) {
		getline(table, line);
		if (line == "") {
			customerID = counter;
			break;
		}
		unpack();
		counter++;
		if (customerID == counter) {
			counter++;
			continue;
		}
	}
	table.close();
}
void Customer::pack()
{
	line = userName + "|"
		+ name + "|"
		+ address + '|'
		+ phone + '|'
		+ email + '|'
		+ confirmPass + '|'
		+ to_string(customerID) + '|'
		+ "\n";
}
void Customer::unpack()
{
	string values[7];
	string temp = "";
	int counter = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '|')
		{
			values[counter] = temp;
			temp = "";
			counter++;
		}
		else if (i == line.length() - 1)
		{
			values[counter] = temp;
		}
		else
		{
			temp += line[i];
		}
	}
	userName = values[0];
	name = values[1];
	address = values[2];
	phone = values[3];
	email = values[4];
	confirmPass = values[5];
	customerID = stoi(values[6]);
}
void Customer::registerCustomer()
{
	setData();
	pack();
	fstream table;
	table.open("Accounts.txt", ios::app);
	table << line;
	table.close();
}
bool Customer::searchUser(string n) {
	string key;
	key = n;
	fstream table;
	table.open("Accounts.txt", ios::in);
	while (!table.eof())
	{
		getline(table, line);
		if (line == "") {
			cout << "Username Not found, Please try again!" << endl;
			return false;
			break;
		}
		unpack();
		if (userName == key) {
			pack();
			return true;
			break;
		}
	}
	table.close();
}
bool Customer::searchPass()
{
	string n;
	cout << "Enter your Password: ";  cin >> n;
	if (n == confirmPass) {
		cout << "Username and Password confirmed!" << endl;
		return true;
	}
	else {
		cout << "Password is incorrect." << endl;
		return false;
	}
}
bool Customer::login()
{
	string n;
	cout << "Enter your Username: ";
	cin >> n;
	while (true) {
		if (searchUser(n)) {
			if (searchPass()) {
				cout << "Welcome " << userName << "!" << endl;
				return true;
				break;
			}
			else {
				string choice;
				cout << "Would you like to try again?(y/n): "; cin >> choice;
				if (choice == "y") {
					login();
				}
				else {
					return false;
					break;
				}
			}
		}
		else {
			string choice;
			cout << "Would you like to try again?(y/n): "; cin >> choice;
			if (choice == "y") {
				login();
			}
			else {
				return false;
				break;
			}
		}
	}
}
bool Customer::custStart()
{
	char choice;
	cout << "Please choose an action from the following: " << endl;
	cout << "Option 1: Log in." << endl;
	cout << "Option 2: Sign up." << endl;
	while (true) {
	cout << "Choose: "; cin >> choice;
		if (choice == '1') {
			if (login()) {
				return true;
			}
			else {
				return false;
			}
			break;
		}
		else if (choice == '2') {
			registerCustomer();
			break;
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
			continue;
		}
	}
}

