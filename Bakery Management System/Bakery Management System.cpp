
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <iomanip>
#include "Customers.h"
#include "Products.h"
#include "Orders.h"

using namespace std;

void readFromFile(vector<order>& orders, vector<customer>& custs, vector<product>& prods);
void writeToFile(vector<order>& orders, vector<customer>& custs, vector<product>& prods);
void main_menu(vector<order>& orders, vector<customer>& custs, vector<product>& prods);

vector<customer>custs;
vector<product>prods;
vector<order>orders;


int main() {
	try {
		readFromFile(orders, custs, prods);
	}
	catch (runtime_error& e) {
		cout << "ignore if running program for the first time\n" << e.what();
	}
	main_menu(orders, custs, prods);
	writeToFile(orders, custs, prods);
}

void readFromFile(vector<order>& orders, vector<customer>& custs, vector<product>& prods)
{
	int cust_id_order;
	int prod_id_order;
	int order_num_order;
	int qty_order;

	int id_prod;
	string name_prod;
	string type_prod;
	double price_prod;

	int id_cust;
	string fName_cust;
	string lName_cust;
	string phone_cust;

	ifstream fin_orders; fin_orders.open("orders.txt");
	if (fin_orders.fail())
	{
		throw runtime_error("error opening orders file");
	}
	while (fin_orders >> cust_id_order >> prod_id_order >> order_num_order >> qty_order)
	{
		orders.push_back({ cust_id_order,prod_id_order,order_num_order,qty_order });
	}

	ifstream fin_custs; fin_custs.open("customers.txt");
	if (fin_custs.fail())
	{
		throw runtime_error("error opening orders file");
	}
	while (fin_custs >> id_cust >> fName_cust >> lName_cust >> phone_cust)
	{
		custs.push_back({ id_cust, fName_cust, lName_cust, phone_cust });
	}

	ifstream fin_prods; fin_prods.open("products.txt");
	if (fin_prods.fail())
	{
		throw runtime_error("error opening orders file");
	}
	while (fin_prods >> id_prod >> name_prod >> type_prod >> price_prod)
	{
		prods.push_back({ id_prod, name_prod, type_prod, price_prod });
	}
}

void writeToFile(vector<order>& orders, vector<customer>& custs, vector<product>& prods)
{
	ofstream fout_custs, fout_prods, fout_orders;

	fout_custs.open("customers.txt");
	for (int i = 0; i < custs.size(); i++)
	{
		fout_custs << custs.at(i).id << " " << custs.at(i).fName << " " << custs.at(i).lName << " " << custs.at(i).phone << "\n";
	}

	fout_prods.open("products.txt");
	for (int i = 0; i < custs.size(); i++)
	{
		fout_prods << prods.at(i).id << " " << prods.at(i).name << " " << prods.at(i).type << " " << prods.at(i).price << "\n";
	}

	fout_orders.open("customers.txt");
	for (int i = 0; i < orders.size(); i++)
	{
		fout_orders << orders.at(i).cust_id << " " << orders.at(i).prod_id << " " << orders.at(i).order_num << " " << orders.at(i).qty << "\n";
	}
}

void main_menu(vector<order>& orders, vector<customer>& custs, vector<product>& prods)
{
	while (true)
	{
		cout << "\n\n";
		cout << "----------------------------------------\n";
		cout << "\t\tBakery Mangement System\n";
		cout << "----------------------------------------\n";


		cout << " 1. Products\n 2. Customers\n 3. Orders\n 4. Exit\n";
		int option = 0;
		cin >> option;

		switch (option) {
		case 1:
			cout << "\n[Products]\n";
			productsMenu(prods);
			break;

		case 2:
			cout << "\n[Customers]\n\n";
			customersMenu(custs);
			break;

		case 3:
			cout << "\n[Orders]\n";
			ordersMenu(orders, custs, prods);
			break;

		case 4:
			cout << "\nSaving and Exiting\n";
			return;

		default:
			cout << "invalid option\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}

}

