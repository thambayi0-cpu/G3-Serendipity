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

#include "format.h"
#include "bookNode.h"

using namespace std;

void addBook (bookNode*& head, bookNode*& tail)
{
	bool notDone = true;
	int choice;
	bookType emptyBook;
	bookNode *newBook = nullptr;

	string t;
	string i;
	string a;
	string p;
	string d;
	int q;
	float w;
	float r;

	if (bookType::bookCount >= 20)
	{
		return;
	}

	printAddBookMenu(emptyBook);

	do
	{
		cout << "\x1b[20;3H" << string(77, ' ');
		cout << "\x1b[20;3H" << "Choice: ";
		cin >> choice;
		cout << "\x1b[21;1H";
		printBottomDash();
		cout << "\x1b[J";
		if (cin.fail() || choice < 0 || choice > 9)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\x1b[23;1H" << "INVALID CHOICE";
			cout << "\x1b[20;11H" << string(69, ' ') << "\x1b[20;11H";
			cin >> choice;
		}
		cout << "\x1b[23;1H" << "\x1b[2K";

		switch (choice)
		{
			case 0:
				notDone = false; break;

			case 1:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Title: ";
				cin.ignore(1000, '\n');
				getline(cin, t);
				emptyBook.setTitle(t);
				printAddBookMenu(emptyBook);
				break;

			case 2:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book ISBN: ";
				cin.ignore(1000, '\n');
				getline(cin, i);
				emptyBook.setIsbn(i);
				printAddBookMenu(emptyBook);
				break;

			case 3:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Author: ";
				cin.ignore(1000, '\n');
				getline(cin, a);
				emptyBook.setAuthor(a);
				printAddBookMenu(emptyBook);
				break;

			case 4:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Publisher: ";
				cin.ignore(1000, '\n');
				getline(cin, p);
				emptyBook.setPublisher(p);
				printAddBookMenu(emptyBook);
				break;

			case 5:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Date Added: ";
				cin.ignore(1000, '\n');
				getline(cin, d);
				emptyBook.setDate(d);
				printAddBookMenu(emptyBook);
				break;

			case 6:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Quantity: ";
				cin >> q;
				while (cin.fail() || q < 1)
				{
					cout << "\x1b[23;1H" << "INVALID INPUT";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\x1b[20;3H" << string(77, ' ');
					cout << "\x1b[20;3H" << "Enter Book Quantity: ";
					cin >> q;
				}
				cout << "\x1b[23;1H" << "\x1b[2K";
				emptyBook.setQty(static_cast<unsigned int>(q));
				printAddBookMenu(emptyBook);
				break;

			case 7:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Wholesale Price: ";
				cin >> w;
				while (cin.fail() || w < 0)
				{
					cout << "\x1b[23;1H" << "INVALID INPUT";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\x1b[20;3H" << string(77, ' ');
					cout << "\x1b[20;3H" << "Enter Book Wholesale Price: ";
					cin >> w;
				}
				cout << "\x1b[23;1H" << "\x1b[2K";
				emptyBook.setWholesale(w);
				printAddBookMenu(emptyBook);
				break;

			case 8:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Retail Price: ";
				cin >> r;
				while (cin.fail() || r < 0)
				{
					cout << "\x1b[23;1H" << "INVALID INPUT";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\x1b[20;3H" << string(77, ' ');
					cout << "\x1b[20;3H" << "Enter Book Retail Price: ";
					cin >> r;
				}
				cout << "\x1b[23;1H" << "\x1b[2K";
				emptyBook.setRetail(r);
				printAddBookMenu(emptyBook);
				break;

			case 9:

				newBook = new bookNode;
				newBook->book = new bookType(emptyBook);
				newBook->next = nullptr;
				insertOrdered(head, tail, newBook);
				bookType::bookCount++;
				emptyBook.bookEmpty();
				printAddBookMenu(emptyBook);

				cout << "\x1b[7;51H" << "BOOK SUCCESSFULLY ADDED!";
				break;
		}


	} while (notDone && bookType::bookCount < 20);

	return;
}

