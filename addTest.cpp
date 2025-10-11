//This is a test for the add_book function. Do not include in build or make file//

#include <iostream>
#include "invMenu.h"
#include "cashier.h"

using namespace std;

int main()
{
	vector<bookType> books;
	bool b1 = true;
	bool b2 = true;
	cout << "\033[H\033[2J";
	cout << "PRESS ENTER TO CONTINUE";
	cin.get();
	//cashier();
	addBook(b1, b2, books);
	cout << "Thank you!" << endl;
	return 0;
}
