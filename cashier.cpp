/***************************************************************************
* PROGRAMMED BY : Ahmer Yasin & Thokozile Hambayi
* ID            : A00349012   & 127485
* CLASS         : CS1B
* SECTION       : TTh 1:30pm
* MODULE        : 2
* GROUP PROJECT : 2
* PROGRAM NAME  : Menus (Navigation & Stubs)
* PURPOSE       : Bookstore POS
* DUE DATE      : 09/23/2025
****************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "format.h"

using namespace std;

void cashier()
{
	const int QTY_WIDTH = 3;
	const int ISBN_WIDTH = 13;
	const int TITLE_WIDTH = 37;
	const int PRICE_WIDTH = 8;
	const int PRICETOTAL_WIDTH = 8;

	string date;
	string title;
	unsigned int qty;
	string isbn;
	float price;

	float tax;
	float subTotal;
	float total;

	cout << "\033[H\033[2J"; //Clear screem

	cout << "Enter Date: ";
	getline(cin, date);
	cout << "Enter Title: ";
	getline(cin, title);
	cout << "Enter ISBN: ";
	getline(cin, isbn);
	cout << "Enter quantity: ";
	cin >> qty;
	while (cin.fail() || qty < 0) //Test for fail state
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid. Please enter the quantity: ";
		cin >> qty;
	}
	if (qty > 100)
		qty = 100;
	cout << "Enter price: ";
	cin >> price;
	while (cin.fail() || price < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid. Please enter the price: ";
		cin >> price;
	}

	if (title.size() > TITLE_WIDTH) // Truncates string if too lomg
		title = title.substr(0, TITLE_WIDTH - 3) + "[…]";
	if (isbn.size() > ISBN_WIDTH)
		isbn = isbn.substr(0, ISBN_WIDTH);
	if (date.size() > 10)
		date = date.substr(0, 10);

	subTotal = price*qty;
	tax = subTotal*0.06;
	total = subTotal+tax;

	cout << "\033[H\033[2J";

	printDash();

	printBorder();

	cout << setw(TOTAL_WIDTH) << "|Serendipity Booksellers" << "|" << endl;

	printBorder();

	cout << "|Date: " << date << right << setw(TOTAL_WIDTH - 6 - date.size()) << "|" << endl;

	printBorder();

	printDash();

	cout << "|Qty  " << setw(ISBN_WIDTH) << "ISBN" << " " << setw(TITLE_WIDTH) << "Title" << " " << setw(PRICE_WIDTH) << "Price" << "    " << setw(PRICETOTAL_WIDTH) << "Total" << " |" << endl;

	printDash();

	cout << fixed;

	cout << "|" << right << setprecision(0) << setw(QTY_WIDTH) << qty << "  " << left << setw(ISBN_WIDTH) << isbn << " " << setw(TITLE_WIDTH) << title << " $" << right << setw(PRICE_WIDTH-1) << setprecision(2) << price << "    $" << setw(PRICETOTAL_WIDTH-1) << subTotal << " |" << left << endl;

	printBorder();

	printBorder();

	cout << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+5) << "|" << setw(PRICE_WIDTH) << "Subtotal" << "    $" << right << setw(PRICETOTAL_WIDTH-1) << subTotal << " |" << left << endl;

	cout << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+5) << "|" << setw(PRICE_WIDTH) << "Tax" << "    $" << right << setw(PRICETOTAL_WIDTH-1) << tax << " |" << left << endl;

	cout << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+5) << "|" << setw(PRICE_WIDTH) << "Total" << "    $" << right << setw(PRICETOTAL_WIDTH-1) << total << " |" << left << endl;

	printBorder();

	cout << setw(TOTAL_WIDTH) << "| Thank you for shopping at Serendipity!" << "|" << endl;

	printDash();

	cout << "PRESS ENTER TO CONTINUE";

	cin.ignore(1000, '\n'); //Clears input stream

	cin.get();

	return;
}
