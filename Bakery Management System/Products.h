#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct product
{
	int id;
	string name;
	string type;
	double price;
};

void addProduct(vector<product>& prods) {
	int id;
	string name, type;
	double price;
	cout << "\nEnter Product ID: ";
	cin >> id;
	cout << "Enter Product Name: ";
	cin >> name;
	cout << "Enter Product Type: ";
	cin >> type;
	cout << "Enter Product Price ($): ";
	cin >> price;

	prods.push_back({ id, name, type, price });
	cout << "Record Added!\n";
}

void viewProducts(const vector<product>& prods) {
	for (int i = 0; i < prods.size(); i++)
	{
		cout << "\nProduct ID: " << prods.at(i).id << "\n";
		cout << "Product Name: " << prods.at(i).name << "\n";
		cout << "Product Type: " << prods.at(i).type << "\n";
		cout << "Product Price ($): " << fixed << setprecision(2) << prods.at(i).price << "\n";
	}
}

int searchProduct(const vector<product>& prods) {
	int searchKey, foundIndex = -1;
	bool found = false;
	cout << "\nEnter Product ID: ";
	cin >> searchKey;

	for (int i = 0; i < prods.size(); i++)
	{
		if (searchKey == prods.at(i).id) {
			found = true;
			foundIndex = i;
		}
	}
	if (found)
	{
		cout << "ID Found:\n";
		cout << "\nProduct ID: " << prods.at(foundIndex).id << "\n";
		cout << "Product Name: " << prods.at(foundIndex).name << "\n";
		cout << "Product Type: " << prods.at(foundIndex).type << "\n";
		cout << "Product Price: " << prods.at(foundIndex).price << "\n\n";
	}
	else
	{
		cout << "ID not found\n";
	}
	return foundIndex;
}

void editProductprice(vector<product>& prods) {
	int editIndex = searchProduct(prods);
	if (editIndex == -1)
	{
		return;
	}
	cout << "Enter new Price ($):\n";
	cin >> prods.at(editIndex).price;
	cout << "Price Updated!\n";
}

void deleteProduct(vector<product>& prods) {
	int delIndex = searchProduct(prods);
	if (delIndex == -1)
	{
		return;
	}
	cout << "Delete Product?(y/n)\n";

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

	vector<product>::iterator delIt = prods.begin() + delIndex;

	prods.erase(delIt);
	"Product Record Deleted\n";
}

void productsMenu(vector<product>& prods) {
	while (true)
	{
		cout << "\n\n";
		cout << "----------------------------------------\n";
		cout << "\t\tProducts\n";
		cout << "----------------------------------------\n";


		cout << " 1. Add Product\n 2. View Products\n 3. Search Product\n 4. Update Product Price\n 5. Delete Product \n 6. Back\n";
		int option = 0;
		cin >> option;

		switch (option) {
		case 1:
			cout << "\n[Add Product]\n";
			addProduct(prods);
			break;

		case 2:
			cout << "\n[View Products]\n\n";
			viewProducts(prods);
			break;

		case 3:
			cout << "\n[Search Product]\n";
			searchProduct(prods);
			break;

		case 4:
			cout << "\n[Update Price]\n";
			editProductprice(prods);
			break;

		case 5:
			cout << "\n[Delete Product]\n";
			deleteProduct(prods);
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
