#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Customers.h"
#include "Products.h"

using namespace std;

struct order
{
	int cust_id;
	int prod_id;
	int order_num;
	int qty;
};

void addOrder(vector<order>& orders, const vector<customer>& custs, const vector<product>& prods) {
	int cust_id, prod_id, order_num, qty;

	cust_id = searchCustomer(custs);

	if (cust_id == -1) {
		cout << "\nNo customer record found. Enter customer record first.\n";
		return;
	}

	prod_id = searchProduct(prods);
	if (prod_id == -1) {
		cout << "\nNo product record found. Enter product record first.\n";
		return;
	}

	cout << "Enter Order no.: ";
	cin >> order_num;
	cout << "Enter Product Quantity: ";
	cin >> qty;

	orders.push_back({ cust_id, prod_id, order_num, qty });
	cout << "Record Added!\n";
}

void viewOrders(const vector<order>& orders) {
	for (int i = 0; i < orders.size(); i++)
	{
		cout << "\nCustomer ID: " << orders.at(i).cust_id << "\n";
		cout << "Product ID: " << orders.at(i).prod_id << "\n";
		cout << "Order no.: " << orders.at(i).order_num << "\n";
		cout << "Product Quantity: " << orders.at(i).qty << "\n";
	}
}

void searchOrder(const vector<order>& orders) {
	int searchKey, foundIndex = -1;
	bool found = false;
	cout << "\nEnter Order no.: ";
	cin >> searchKey;

	for (int i = 0; i < orders.size(); i++)
	{
		if (searchKey == orders.at(i).order_num) {
			found = true;
			foundIndex = i;
		}
	}
	if (found)
	{
		cout << "Order Found:\n";
		cout << "\nCustomer ID: " << orders.at(foundIndex).cust_id << "\n";
		cout << "Product ID: " << orders.at(foundIndex).prod_id << "\n";
		cout << "Order no.: " << orders.at(foundIndex).order_num << "\n";
		cout << "Product Quantity: " << orders.at(foundIndex).qty << "\n\n";
	}
	else
	{
		cout << "order not found\n";
	}
}

void ordersMenu(vector<order>& orders, const vector<customer>& custs, const vector<product>& prods) {
	while (true)
	{
		cout << "\n\n";
		cout << "----------------------------------------\n";
		cout << "\t\tOrders\n";
		cout << "----------------------------------------\n";


		cout << " 1. Add Order\n 2. View Orders\n 3. Search Order\n 4. Update Order Price\n 5. Delete Order \n 6. Back\n";
		int option = 0;
		cin >> option;

		switch (option) {
		case 1:
			cout << "\n[Add Order]\n";
			addOrder(orders, custs, prods);
			break;

		case 2:
			cout << "\n[View Orders]\n\n";
			viewOrders(orders);
			break;

		case 3:
			cout << "\n[Search Order]\n";
			searchOrder(orders);
			break;

		case 4:
			cout << "\nGoing Back\n";
			return;

		default:
			cout << "invalid option\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}
}

