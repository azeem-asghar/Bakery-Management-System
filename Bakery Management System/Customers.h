#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct customer
{
	int id;
	string fName;
	string lName;
	string phone;
};

void addCustomer(vector<customer>& custs) {
	int id;
	string fName, lName, phone;
	cout << "\nEnter Customer ID: ";
	cin >> id;
	cout << "Enter Customer's first name: ";
	cin >> fName;
	cout << "Enter Customer's last name: ";
	cin >> lName;
	cout << "Enter Customer's phone no.: ";
	cin >> phone;

	custs.push_back({ id, fName, lName, phone });
	cout << "Record Added!\n";
}

void viewCustomers(const vector<customer>& custs) {
	for (int i = 0; i < custs.size(); i++)
	{
		cout << "\nCustomer ID: " << custs.at(i).id << "\n";
		cout << "Customer first name: " << custs.at(i).fName << "\n";
		cout << "Customer last name: " << custs.at(i).lName << "\n";
		cout << "Customer phone no.: " << custs.at(i).phone << "\n";
	}
}

int searchCustomer(const vector<customer>& custs) {
	int searchKey, foundIndex = -1;
	bool found = false;
	cout << "\nEnter customer ID: ";
	cin >> searchKey;

	for (int i = 0; i < custs.size(); i++)
	{
		if (searchKey == custs.at(i).id) {
			found = true;
			foundIndex = i;
		}
	}
	if (found)
	{
		cout << "ID Found:\n";
		cout << "\nCustomer ID: " << custs.at(foundIndex).id << "\n";
		cout << "Customer first name: " << custs.at(foundIndex).fName << "\n";
		cout << "Customer last name: " << custs.at(foundIndex).lName << "\n";
		cout << "Customer phone no.: " << custs.at(foundIndex).phone << "\n\n";
	}
	else
	{
		cout << "ID not found\n";
	}
	return foundIndex;
}

void editCustomerPhone(vector<customer>& custs) {
	int editIndex = searchCustomer(custs);
	if (editIndex == -1)
	{
		return;
	}
	cout << "Enter new phone no.:\n";
	cin >> custs.at(editIndex).phone;
	cout << "Phone no. Updated!\n";
}

void deleteCustomer(vector<customer>& custs) {
	int delIndex = searchCustomer(custs);
	if (delIndex == -1)
	{
		return;
	}
	cout << "Delete Customer?(y/n)\n";

	char confirm;
	cin >> confirm;
	while (!(confirm == 'y' || confirm == 'n')) {
		cout << "Enter 'y' or 'n'\n";
		cin >> confirm;
	}

	if (confirm == 'n') {
		cout << "_________________________________________________\n\n\n\n";
		return;
	}

	vector<customer>::iterator delIt = custs.begin() + delIndex;

	custs.erase(delIt);
	"Customer Record Deleted\n";
}

void customersMenu(vector<customer>& custs) {
	while (true)
	{
		cout << "\n\n";
		cout << "----------------------------------------\n";
		cout << "\t\tCustomers\n";
		cout << "----------------------------------------\n";


		cout << " 1. Add Customer\n 2. View Customers\n 3. Search Customer\n 4. Update Customer Phone no.\n 5. Delete Customer \n 6. Back\n";
		int option = 0;
		cin >> option;

		switch (option) {
		case 1:
			cout << "\n[Add Customer]\n";
			addCustomer(custs);
			break;

		case 2:
			cout << "\n[View Customers]\n\n";
			viewCustomers(custs);
			break;

		case 3:
			cout << "\n[Search Customer]\n";
			searchCustomer(custs);
			break;

		case 4:
			cout << "\n[Update Price]\n";
			editCustomerPhone(custs);
			break;

		case 5:
			cout << "\n[Delete Customer]\n";
			deleteCustomer(custs);
			break;

		case 6:
			cout << "\nGoing Back\n";
			return;

		default:
			cout << "invalid option\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}
}
