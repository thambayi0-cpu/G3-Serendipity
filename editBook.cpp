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
//	bool notDone = true;
//	int choice;
	int index = lookUpBook(books);

	if (index == -1)
		return;

	bookType displayBook(books.at(index));

	/*string t;
	string i;
	string a;
	string p;
	string d;
	int q;
	float w;
	float r;*/

	printEditBookMenu(displayBook);

	cin.get();

	return;

}

