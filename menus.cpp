
#include <iostream>
#include "format.h"

using namespace std;

int main()
{
	int choice;

	cout << "\033[H\033[2J"; //Clear screen

	printTopDash();

	printBorder();

	cout << "│                           SERENDIPITY BOOKSELLERS                            │" << endl;
	cout << "│                                     Menu                                     │" << endl;

	printBorder();

	printBorder();
	printBorder();
	printBorder();
	printBorder();
	printBorder();

	printBorder();

	printBorder();

	printBorder();

	printBottomDash();

	cout << "\x1b[06;20H" << "1.  Option 1" << endl;
	cout << "\x1b[07;20H" << "2.  Option 2" << endl;
	cout << "\x1b[08;20H" << "3.  Option 3" << endl;
	cout << "\x1b[09;20H" << "4.  Option 4" << endl;
	cout << "\x1b[10;20H" << "5.  Option 5" << endl;

	cout << "\x1b[12;20H" << "Enter choice: ";

	while(!(cin >> choice) && !(choice < 1 || choice > 5))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\x1b[14;20H" << "Please enter a valid number between 1-5";
		cout << "\x1b[12;20H" << "Enter choice: ";
	}

	return 0;
}
