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
#include "invMenu.h"

void editBook (vector<bookType>& books)
{

	bool notDone = true;
	int choice;
	int index;
	char choice2;

	string t;
	string i;
	string a;
	string p;
	string d;
	int    q;
	float  w;
	float  r;

	bookType displayBook;

	index = lookUpBook(books);

	do
	{

		while (index == -1)
		{
			cout << "\033[H\033[2J";
			cout << "Edit another book? (Y/N) ";
			cin.get(choice2);
			choice2 = toupper(choice2);

			while (choice2 != 'Y' && choice2 != 'N')
			{
            cout << "Invalid input. Please enter Y or N: ";
				cin.ignore(1000, '\n');
            cin.get(choice2);
            choice2 = toupper(choice2);
			}

			if (choice2 == 'N')
				return;
			else if(choice2 == 'Y')
			{
				cin.ignore(1000, '\n');
				index = lookUpBook(books);
			}
			cin.ignore(1000, '\n');
		}


		displayBook.bookFill(books.at(index));

		printEditBookMenu(displayBook);

		do
		{
			cout << "\x1b[17;3H" << string(77, ' ');
			cout << "\x1b[17;3H" << "Choice: ";
			cin >> choice;
			cout << "\x1b[18;1H";
			printBottomDash();
			cout << "\x1b[J";

			if (cin.fail() || choice < 0)
			{
		      cin.clear();
		      cin.ignore(1000, '\n');
		      cout << "\x1b[20;1H" << "INVALID CHOICE";
		      cout << "\x1b[17;11H" << string(69, ' ') << "\x1b[17;11H";
		      cin >> choice;
			}
			cout << "\x1b[20;1H" << "\x1b[2K"; //Clear Bottom of screen

			switch (choice)
			{
				case 0:
					notDone = false;
					cin.ignore(1000, '\n');
					index = -1;
					break;
				case 1:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Title: ";
					cin.ignore(1000, '\n');
					getline(cin, t);
					displayBook.setTitle(t);
					printEditBookMenu(displayBook);
					break;
				case 2:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book ISBN: ";
					cin.ignore(1000, '\n');
					getline(cin, i);
					displayBook.setIsbn(i);
					printEditBookMenu(displayBook);
					break;
				case 3:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Author: ";
					cin.ignore(1000, '\n');
					getline(cin, a);
					displayBook.setAuthor(a);
					printEditBookMenu(displayBook);
					break;
				case 4:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Publisher: ";
					cin.ignore(1000, '\n');
					getline(cin, p);
					displayBook.setPublisher(p);
					printEditBookMenu(displayBook);
					break;
				case 5:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Date Added: ";
					cin.ignore(1000, '\n');
					getline(cin, d);
					displayBook.setDate(d);
					printEditBookMenu(displayBook);
					break;
				case 6:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Quantity: ";
					cin >> q;
					while (cin.fail() || q < 0)
					{
						cout << "\x1b[20;1H" << "INVALID INPUT";
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "\x1b[17;3H" << string(77, ' ');
						cout << "\x1b[17;3H" << "Enter New Book Quantity: ";
						cin >> q;
					}
					cout << "\x1b[20;1H" << "\x1b[2K";
					displayBook.setQty(static_cast<unsigned int>(q));
					printEditBookMenu(displayBook);
					break;
				case 7:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Wholesale Price: ";
					cin >> w;
					while (cin.fail() || w < 0)
					{
						cout << "\x1b[20;1H" << "INVALID INPUT";
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "\x1b[17;3H" << string(77, ' ');
						cout << "\x1b[17;3H" << "Enter New Book Wholesale Price: ";
						cin >> w;
					}
					cout << "\x1b[20;1H" << "\x1b[2K";
					displayBook.setWholesale(w);
					printEditBookMenu(displayBook);
					break;
				case 8:
					cout << "\x1b[17;3H" << string(77, ' ');
					cout << "\x1b[17;3H" << "Enter New Book Retail Price: ";
					cin >> r;
					while (cin.fail() || r < 0)
					{
						cout << "\x1b[20;1H" << "INVALID INPUT";
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "\x1b[17;3H" << string(77, ' ');
						cout << "\x1b[17;3H" << "Enter New Book Retail Price: ";
						cin >> r;
					}
					cout << "\x1b[20;1H" << "\x1b[2K";
					displayBook.setRetail(r);
					printEditBookMenu(displayBook);
					break;
				case 9:
					books.at(index).bookFill(displayBook);
					printEditBookMenu(displayBook);
					cout << "\x1b[04;51H" << "BOOK SUCCESSFULLY EDITED!";
					break;
			}
		} while (notDone);
	} while(index == -1);
	return;

}

