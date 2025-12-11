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
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bookType* lookUpBook (const bookNode* head)
{
	const string CLEAR_SCREEN = "\x1b[H\x1b[2J";
	string headingString;
	string searchString;
	string menuString;
	vector <const bookNode*> matches;
	int bookIndex;
	int booksFound = 0;
	const bookNode* current = head;

	headingString = OutputClassHeading();
	menuString    = PrintLookUpBookMenu();


	cout << CLEAR_SCREEN;
	cout << headingString;
	cout << menuString;

	cin.clear();

	cout << "\x1b[20;35H";
	getline(cin, searchString);
	cout << "\x1b[27;0H";


	if (searchString.empty())
		return nullptr;
	else
	{
		toLower(searchString);
		while (current != nullptr)
		{
			if (toLower(current->book->getTitle()).find(searchString) != std::string::npos || current->book->getIsbn() == searchString)
			{
				booksFound++;
				matches.push_back(current);
				cout << " <" << booksFound-1 << "> " << current->book->getTitle() << endl
					  << "     ISBN: " << current->book->getIsbn() << endl;
				cout << endl;
			}
			current = current->next;
		}
		if (booksFound == 0)
		{
			cout << "No matches found!" << endl
				<< "Press enter to return to menu";
			cin.get();
			return nullptr;
		}
	}


	cout << endl << endl << "Enter index for book info or -1 to exit: ";
	cin  >> bookIndex;
	while (cin.fail() || bookIndex < -1 || bookIndex > booksFound-1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input. Please enter a valid index for book info or -1 to exit: ";
		cin >> bookIndex;
	}
	if (bookIndex == -1)
	{
		cin.ignore(1000, '\n');
		return nullptr;
	}
	else
	{
		cout << CLEAR_SCREEN;
		cout << "Title:      "  << matches.at(bookIndex)->book->getTitle() << endl;
		cout << "ISBN:       "  << matches.at(bookIndex)->book->getIsbn() << endl;
		cout << "Author:     "  << matches.at(bookIndex)->book->getAuthor() << endl;
		cout << "Publisher:  "  << matches.at(bookIndex)->book->getPublisher() << endl;
		cout << "Date Added: "  << matches.at(bookIndex)->book->getDate() << endl;
		cout << "Qty:        "  << matches.at(bookIndex)->book->getQty() << endl;
		cout << "Wholesale:  "  << matches.at(bookIndex)->book->getWholesale() << endl;
		cout << "Retail:     "  << matches.at(bookIndex)->book->getRetail() << endl;

		cout << "\nPress enter to return";
		cin.ignore(1000, '\n');
		cin.get();
		return matches.at(bookIndex)->book;
	}
}

