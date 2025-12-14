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
#include "reports.h"

void repWholesale(bookNode*& head, bookNode*& tail)
{

	int totalPage;
	int currentPage = 1;
	float total = 0;

	bookNode* current = head;
	string currentDate = printCurrentDate();

	const int BOOKS_SHOWN = 10;
	const int DATABASE_SIZE = 200;

	const int TITLE_WIDTH = 37;
	const int ISBN_WIDTH = 13;
	const int QTY_WIDTH = 3;
	const int WHOLESALE_WIDTH = 8;

	string databaseStr = to_string(DATABASE_SIZE);
	string currentStr = to_string(currentPage);
	string countStr = to_string(bookType::bookCount);

	if (bookType::bookCount % BOOKS_SHOWN != 0)
		totalPage = bookType::bookCount / BOOKS_SHOWN + 1;
	else
		totalPage = bookType::bookCount / BOOKS_SHOWN;

	string pageStr = to_string(totalPage);

	while (currentPage <= totalPage)
	{
		cout << "\033[H\033[2J";

		printTopDash();

		cout << "│                           SERENDIPITY BOOKSELLERS                            │" << endl;
		cout << "│                               WHOLESALE REPORT                               │" << endl;

		printBorder();

		cout << "│ " << left << setw(16) << ("DATE: " + currentDate)
			  << setw(15) << (" PAGE: " + currentStr + " of " + pageStr)
			  << setw(45) << (" DATABASE SIZE: " + databaseStr + "  CURRENT BOOK COUNT: " + countStr) << " │" << endl;


		printBorder();

		cout << "│ " << setw(TITLE_WIDTH) << "TITLE" << " "
			  << setw(ISBN_WIDTH) << "ISBN" << " "
			  << setw(QTY_WIDTH) << "QTY" << " "
			  << setw(WHOLESALE_WIDTH) << "WHOLESALE" << right << setw(TOTAL_WIDTH-66) << " │" << endl;
		cout << left;

		printMidDash();

		for (int i = 0; i < BOOKS_SHOWN; i++)
		{
			total += current->book->getWholesale();

			cout << "│ " << setw(TITLE_WIDTH) << ((current->book->getTitle().length() > TITLE_WIDTH) ? current->book->getTitle().substr(0, TITLE_WIDTH-1) + "…" : current->book->getTitle()) << " "
		 		  << setw(ISBN_WIDTH) << current->book->getIsbn() << " "
				  << setw(QTY_WIDTH) << fixed << setprecision(0) << current->book->getQty() << " "
			     << setprecision(2) << "$ " << setw(WHOLESALE_WIDTH-2) << current->book->getWholesale() << right
				  << setw(TOTAL_WIDTH-65) << " │" << endl;
			cout << left;

			if (current->next == nullptr)
			{
				for (int j = 0; j < BOOKS_SHOWN-i-1; j++)
					printBorder();
				break;
			}
			else
				current = current->next;
		}

		printMidDash();

		if (currentPage == totalPage)
		{
			cout << "│ Total Wholesale Inventory Value: $ " << setw(TOTAL_WIDTH-39) << total << "│" << endl;

			printMidDash();
		}

		cout << setw(TOTAL_WIDTH) << "│ Press any key to coninue ->" << "│" << endl;

		printBottomDash();

		cin.get();

		currentPage++;

		currentStr = to_string(currentPage);

	}

	return;
}
