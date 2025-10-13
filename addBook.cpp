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

using namespace std;

void addBook (bool &keepInvMenuActive, bool &keepAddBookMenuActive, vector<bookType>& books)
{
	bool notDone = true;
	int choice;
	bookType emptyBook;

	string t;
	string i;
	string a;
	string p;
	string d;
	int q;
	float w;
	float r;

	printAddBookMenu(books, emptyBook);

	do
	{
		cout << "\x1b[20;3H" << string(77, ' ');
		cout << "\x1b[20;3H" << "Choice: ";
		cin >> choice;
		cout << "\x1b[21;1H";
		printBottomDash();
		cout << "\x1b[J";
		if (cin.fail() || choice < 0)
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
				printAddBookMenu(books, emptyBook);
				break;

			case 2:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book ISBN: ";
				cin.ignore(1000, '\n');
				getline(cin, i);
				emptyBook.setIsbn(i);
				printAddBookMenu(books, emptyBook);
				break;

			case 3:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Author: ";
				cin.ignore(1000, '\n');
				getline(cin, a);
				emptyBook.setAuthor(a);
				printAddBookMenu(books, emptyBook);
				break;

			case 4:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Publisher: ";
				cin.ignore(1000, '\n');
				getline(cin, p);
				emptyBook.setPublisher(p);
				printAddBookMenu(books, emptyBook);
				break;

			case 5:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Date Added: ";
				cin.ignore(1000, '\n');
				getline(cin, d);
				emptyBook.setDate(d);
				printAddBookMenu(books, emptyBook);
				break;

			case 6:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Quantity: ";
				cin >> q;
				while (cin.fail() || q < 0)
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
				printAddBookMenu(books, emptyBook);
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
				printAddBookMenu(books, emptyBook);
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
				printAddBookMenu(books, emptyBook);
				break;

			case 9:

				books.at(bookType::bookCount).bookFill(emptyBook);
				emptyBook.bookEmpty();
				bookType::bookCount++;
				printAddBookMenu(books, emptyBook);
				cout << "\x1b[7;51H" << "BOOK SUCCESSFULLY ADDED!";
				break;
		}


	} while (notDone && bookType::bookCount < 20);

	return;
}

//bookType//

unsigned int bookType::bookCount = 0;

//Setters//
void bookType::bookAdd()
{bookCount++;}
void bookType::bookFill(const bookType& other)
{
	title = other.getTitle();
	isbn = other.getIsbn();
	author = other.getAuthor();
	publisher = other.getPublisher();
	date = other.getDate();
	qty = other.getQty();
	wholesale = other.getWholesale();
	retail = other.getRetail();
}
void bookType::bookEmpty()
{
	title = "EMPTY";
	isbn = "EMPTY";
	author = "EMPTY";
	publisher = "EMPTY";
	date = "EMPTY";
	qty = 0;
	wholesale = 0.0;
	retail = 0.0;
}
void bookType::setTitle(string t)
{title = t;}
void bookType::setIsbn(string i)
{isbn = i;}
void bookType::setAuthor(string a)
{author = a;}
void bookType::setPublisher(string p)
{publisher = p;}
void bookType::setDate(string d)
{date = d;}
void bookType::setQty(unsigned int q)
{qty = q;}
void bookType::setWholesale(float w)
{wholesale = w;}
void bookType::setRetail(float r)
{retail = r;}

unsigned int bookType::getBookCount() const
{return bookCount;}
string bookType::getTitle() const
{return title;}
string bookType::getIsbn() const
{return isbn;}
string bookType::getAuthor() const
{return author;}
string bookType::getPublisher() const
{return publisher;}
string bookType::getDate() const
{return date;}
unsigned int bookType::getQty() const
{return qty;}
float bookType::getWholesale() const
{return wholesale;}
float bookType::getRetail() const
{return retail;}

bookType::bookType(string t, string i, string a, string p, string d, unsigned int q, float w, float r)
{
        //cout << "Calling default constructor" << endl;
        title = t;
        isbn = i;
        author = a;
        publisher = p;
        date = d;
        qty = q;
        wholesale = w;
        retail = r;
}

bookType::~bookType()
{
        //cout << "Destroying bookType instance" << endl;
}
