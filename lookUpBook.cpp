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
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "bookType.h"
using namespace std;

int lookUpBook (const vector<bookType>& books)
{
	const string CLEAR_SCREEN = "\x1b[H\x1b[2J";
	string headingString;
	string searchString;
	string menuString;
	vector <string> titles;
	vector <string> isbns;
	string titleEmpty;
	string isbnEmpty;
	int bookIndex;
	int booksFound = 0;

	headingString = OutputClassHeading();
	menuString    = PrintLookUpBookMenu();


	cout << CLEAR_SCREEN;
	cout << headingString;
	cout << menuString;

	for (unsigned int i = 0; i < bookType::bookCount; i++) //Creates a list of lowercase titles
	{
		for (int j = 0; j < int(books.at(i).getTitle().length()); j++)
		{
			titleEmpty.push_back(char(tolower(books.at(i).getTitle()[j])));
		}
		titles.push_back(titleEmpty);
		titleEmpty.clear();
	}
	for (unsigned int i = 0; i < bookType::bookCount; i++) //Creates a list of lowercase isbns
	{
		for (int j = 0; j < int(books.at(i).getIsbn().length()); j++)
		{
			isbnEmpty.push_back(char(tolower(books.at(i).getIsbn()[j])));
		}
		isbns.push_back(isbnEmpty);
		isbnEmpty.clear();
	}
	cin.clear();

	cout << "\x1b[20;35H";
	getline(cin, searchString);
	cout << "\x1b[27;0H";


	if (searchString.empty())
		return -1;
	else
	{
		for (char& c : searchString)
    		c = std::tolower(c);
		for (unsigned int i = 0; i < bookType::bookCount; i++)
		{
			if (titles.at(i).find(searchString) != std::string::npos || isbns.at(i) == searchString)
			{
				booksFound++;
				cout << " <" << i << "> " << books.at(i).getTitle() << endl
					  << "     ISBN: " << books.at(i).getIsbn() << endl;
				cout << endl;
			}
		}
		if (booksFound == 0)
		{
			cout << "No matches found!" << endl
				<< "Press enter to return to menu";
			cin.get();
			return -1;
		}
	}


	cout << endl << endl << "Enter index for book info or -1 to exit: ";
	cin  >> bookIndex;
	while (cin.fail() || (bookIndex < -1 || (bookIndex >= 0 && bookIndex >= static_cast<int>(bookType::bookCount))))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input. Please enter a valid index for book info or -1 to exit: ";
		cin >> bookIndex;
	}
	if (bookIndex == -1)
		return -1;
	else
	{
		cout << CLEAR_SCREEN;
		cout << "Title:      "  << books.at(bookIndex).getTitle() << endl;
		cout << "ISBN:       "  << books.at(bookIndex).getIsbn() << endl;
		cout << "Author:     "  << books.at(bookIndex).getAuthor() << endl;
		cout << "Publisher:  "  << books.at(bookIndex).getPublisher() << endl;
		cout << "Date Added: "  << books.at(bookIndex).getDate() << endl;
		cout << "Qty:        "  << books.at(bookIndex).getQty() << endl;
		cout << "Wholesale:  "  << books.at(bookIndex).getWholesale() << endl;
		cout << "Retail:     "  << books.at(bookIndex).getRetail() << endl;

		cout << "\nPress enter to return";
		cin.ignore(1000, '\n');
		cin.get();
		return bookIndex;
	}

}

