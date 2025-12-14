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
#include "invMenu.h"

using namespace std;

struct cartItem
{
	bookType* bookPtr;
	int qty;
};

void cashier(bookNode*& head, bookNode*& tail)
{
	const int QTY_WIDTH = 3;
	const int ISBN_WIDTH = 13;
	const int TITLE_WIDTH = 37;
	const int PRICE_WIDTH = 8;
	const int PRICETOTAL_WIDTH = 11;

	float tax;
	float subTotal = 0;
	float total;

	vector<cartItem> cart;

	cartItem item;

	bool addItems = true;
	bool stillShopping = true;
	bool lookAgain = true;
	char choice;

	cout << "\033[H\033[2J"; //Clear screem
	do
	{
		do
		{
			item.bookPtr = lookUpBook(head);
			while (item.bookPtr == nullptr && lookAgain) //Checks to see if this is the book you want to purchase
			{
				cout << "\033[H\033[2J";
				cout << "Choose another book? (Y/N) ";
				cin.get(choice);
				choice = toupper(choice);

				while (choice != 'Y' && choice != 'N')
				{
					cout << "Invalid input. Please enter Y or N: ";
					cin.ignore(1000, '\n');
					cin.get(choice);
					choice = toupper(choice);
				}
				if (choice == 'N')
					lookAgain = false;
				else if(choice == 'Y')
				{
					item.bookPtr = lookUpBook(head);
				}
				cin.ignore(1000, '\n');
			} //By the end of this block, the stream is clean
			if (item.bookPtr != nullptr) //Checks to see if you chose any book at all
			{
				cout << "\033[H\033[2J";
				cout << "Add item to cart? (Y/N) ";
				cin.get(choice);
				choice = toupper(choice);
				while (choice != 'Y' && choice != 'N')
				{
					cout << "Invalid input. Please enter Y or N: ";
					cin.ignore(1000, '\n');
					cin.get(choice);
					choice = toupper(choice);
				}

				if (choice == 'Y')
				{
					cout << "Enter quantity: ";
					cin >> item.qty;
					if (item.qty > static_cast<int>(item.bookPtr->getQty()))
					{
						cout << "Sorry, but that exceeds our current inventory size of " << item.bookPtr->getQty() << ". Please enter a new value: ";
						cin >> item.qty;
					}
					if (item.qty != 0)
						cart.push_back(item);
					item.bookPtr = nullptr;
					item.qty = 0;
				}
			}

			cout << "Continue to purchase? (Y/N) ";
			cin.ignore(1000, '\n'); //By this point, the stream is clean again
			cin.get(choice);
			choice = toupper(choice);

			while (choice != 'Y' && choice != 'N')
			{
				cout << "Invalid input. Please enter Y or N: ";
				cin.ignore(1000, '\n');
				cin.get(choice);
				choice = toupper(choice);
			}
			if (choice == 'Y')
				addItems = false;
			else
				addItems = true;

			cin.ignore(1000, '\n'); //Again, the stream is clean

		} while (addItems); //Checks to see if you want to buy more books

		if (cart.size() != 0)
		{
			//subTotal = price*qty;
			for (cartItem c : cart)
				subTotal += c.bookPtr->getRetail()*c.qty; //Not sure if I'm supposed to use wholesale or retail, but I'm using retail

			tax = subTotal*0.06;
			total = subTotal+tax;

			cout << "\033[H\033[2J";

			printTopDash();

			printBorder();

			cout << setw(TOTAL_WIDTH) << "│Serendipity Booksellers" << "│" << endl;

			printBorder();

			cout << "│Date: " << printCurrentDate() << right << setw(TOTAL_WIDTH - 6 - 10) << "│" << endl;

			printBorder();

			printMidDash();

			cout << "│Qty  " << setw(ISBN_WIDTH) << "ISBN" << " " << setw(TITLE_WIDTH) << "Title" << " " << setw(PRICE_WIDTH) << "Price" << "    " << setw(PRICETOTAL_WIDTH-3) << "Total" << " │" << endl;

			printMidDash();

			cout << fixed;

			for (cartItem c : cart)
			{
				cout << "│" << right << setprecision(0) << setw(QTY_WIDTH) << c.qty
				<< "  " << left << setw(ISBN_WIDTH) << c.bookPtr->getIsbn()
				<< " " << setw(TITLE_WIDTH) << ((c.bookPtr->getTitle().length() > TITLE_WIDTH) ? c.bookPtr->getTitle().substr(0, TITLE_WIDTH - 3) + "[…]" : c.bookPtr->getTitle())
				<< " $" << right << setw(PRICE_WIDTH-1) << setprecision(2) << c.bookPtr->getRetail()
				<< "    $" << setw(PRICETOTAL_WIDTH-4) << c.bookPtr->getRetail()*c.qty << " │" << left << endl;
				printBorder();
			}

			cout << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+7) << "│" << setw(PRICE_WIDTH) << "Subtotal" << " $" << right << setw(PRICETOTAL_WIDTH-1) << subTotal << " │" << left << endl;

			cout << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+7) << "│" << setw(PRICE_WIDTH) << "Tax" << " $" << right << setw(PRICETOTAL_WIDTH-1) << tax << " │" << left << endl;

			cout << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+7) << "│" << setw(PRICE_WIDTH) << "Total" << " $" << right << setw(PRICETOTAL_WIDTH-1) << total << " │" << left << endl;

			printBorder();

			cout << setw(TOTAL_WIDTH) << "│ Thank you for shopping at Serendipity!" << "│" << endl;

			printBottomDash();

			cout << "Confirm purchase? (Y/N) ";

			cin >> choice;

			choice = toupper(choice);

			while (choice != 'Y' && choice != 'N')
			{
				cout << "Invalid input. Please enter Y or N: ";
				cin.ignore(1000, '\n');
				cin.get(choice);
				choice = toupper(choice);
			}
			if (choice == 'Y')
			{
				for (cartItem c : cart)
					c.bookPtr->setQty(c.bookPtr->getQty() - c.qty);

				cout << "Thank you!" << endl;
			}
			else if (choice == 'N')
			{
				cout << "Transaction cancelled." << endl;
			}
			cin.ignore(1000, '\n'); //Clean stream
		}

		cout << "Press enter to continue";

		cin.get();

		cout << "Would you like to make another transaction? (Y/N) ";

		cin >> choice;

		choice = toupper(choice);

		while (choice != 'Y' && choice != 'N')
		{
			cout << "Invalid input. Please enter Y or N: ";
			cin.ignore(1000, '\n');
			cin.get(choice);
			choice = toupper(choice);
		}
		if (choice == 'N')
			stillShopping = false;
		else if (choice == 'Y')
			cart.clear();

		cin.ignore(1000, '\n'); //Clean stream

	} while (stillShopping);

	return;
}
