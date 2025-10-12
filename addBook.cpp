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
	const int ENTER_WIDTH = 39;
	bool notDone = true;
	int choice;
	bookType emptyBook;

	string t;
	string i;
	string a;
	string p;
	string d;
	unsigned int q;
	float w;
	float r;

	cout << "\033[H\033[2J"; //Clear screen

	printTopDash();

	cout << "│                           SERENDIPITY BOOKSELLERS                            │" << endl;
	cout << "│                                   ADD BOOK                                   │" << endl;

	printBorder();

	cout << "│                             DATABASE SIZE:  20 CURRENT BOOK COUNT: " << left << setw(3) << bookType::bookCount << right << "       │" << endl;

	printBorder();

	cout << setw(TOTAL_WIDTH) << "│                                                 --PENDING VALUES" << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <1>  Enter Book Title" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << emptyBook.getTitle() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <2>  Enter ISBN" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << emptyBook.getIsbn() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <3>  Enter Author" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << emptyBook.getAuthor() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <4>  Enter Publisher" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << emptyBook.getPublisher() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <5>  Enter Date Added  (mm/dd/yyyy)" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << emptyBook.getDate() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <6>  Enter Quantity on Hand" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << fixed << setprecision(0) << emptyBook.getQty() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <7>  Enter Wholesale Cost" << setw(3) << ">" << "$ " << setw(TOTAL_WIDTH - ENTER_WIDTH - 5) << setprecision(2) << emptyBook.getWholesale() << "│" << endl;

	cout << setw(ENTER_WIDTH) << "│ <8>  Enter Retail Price" << setw(3) << ">" << "$ " << setw(TOTAL_WIDTH - ENTER_WIDTH - 5) << setprecision(2) << emptyBook.getRetail() << "│" << endl;

	cout << setw(TOTAL_WIDTH) << "│ <9>  Save Book to Database" << "│" << endl;

	cout << setw(TOTAL_WIDTH) << "│ <0>  Return to Inventory Menu" << "│" << endl;

	printBorder();

	printMidDash();

	cout << setw(TOTAL_WIDTH) << "│ Choice: " <<"│" << endl;

	printBottomDash();

	do
	{
		cout << "\x1b[20;3H" << string(77, ' ');
		cout << "\x1b[20;3H" << "Choice: ";
		cin >> choice;
		while (cin.fail() || choice < 0 || choice > 9)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\x1b[23;1H" << "INVALID CHOICE";
			cout << "\x1b[20;11H";
			cin >> choice;
		}

		switch (choice)
		{
			case 0:
				notDone = false; break;
			case 1:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Title: ";
				cin.ignore(1000, '\n');
				cin >> t;
				emptyBook.setTitle(t);
				break;
			case 2:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book ISBN: ";
				cin >> i;
				emptyBook.setIsbn(i);
				break;
			case 3:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Author: ";
				cin.ignore(1000, '\n');
				cin >> a;
				emptyBook.setAuthor(a);
				break;
			case 4:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Publisher: ";
				cin.ignore(1000, '\n');
				cin >> p;
				emptyBook.setPublisher(p);
				break;
			case 5:
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Enter Book Date Added: ";
				cin.ignore(1000, '\n');
				cin >> d;
				emptyBook.setDate(d);
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
				emptyBook.setQty(q);
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
				emptyBook.setWholesale(w);
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
					cout << "\x1b[20;3H" << "Enter Book Wholesale Price: ";
					cin >> r;
				}
				emptyBook.setRetail(r);
				break;
			case 9:
				books.at(bookType::bookCount).bookFill(emptyBook);
				cout << "\x1b[20;3H" << string(77, ' ');
				cout << "\x1b[20;3H" << "Book Successfully Added!";
				emptyBook.bookEmpty();
				bookType::bookCount++;
				cin.ignore(1000, '\n');
				cin.get();
				break;
		}

	} while (notDone);

	cout << "\x1b[23;1H" << "Press enter to continue";

	cin.ignore(1000, '\n');
	cin.get();
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
        cout << "Calling default constructor" << endl;
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
        cout << "Destroying bookType instance" << endl;
}
