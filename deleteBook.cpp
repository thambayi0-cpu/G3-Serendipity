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

void deleteBook (bookNode*& head, bookNode*& tail)
{
	bool notDone = true;
	char choice;
	bookType* target;

	target = lookUpBook(head);

	do
	{
		while (target == nullptr)
		{
			cout << "\033[H\033[2J";
			cout << "Delete another book? (Y/N) ";
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
				return;
			else if (choice == 'Y')
			{
				cin.ignore(1000, '\n');
				target = lookUpBook(head);
			}
			cin.ignore(1000, '\n');
		}

		cout << "\nErase this book? (Y/N) ";

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
			deleteNode(head, tail, target);

			cout << "BOOK SUCCESSFULLY DELETED" << endl;
		}

		target = nullptr;
		cin.ignore(1000, '\n');

	} while (notDone);

	return;
}
