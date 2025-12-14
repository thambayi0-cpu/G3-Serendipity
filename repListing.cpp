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

void repListing(bookNode*& head, bookNode*& tail)
{
	int totalPage;
	int currentPage = 1;
	bookNode* current = head;
	string currentDate = printCurrentDate();

	const int BOOKS_SHOWN = 5;
	const int DATABASE_SIZE = 20;

	const int TITLE_WIDTH = 16;
	const int ISBN_WIDTH = 13;
	const int AUTHOR_WIDTH = 11;
	const int PUBLISHER_WIDTH = 10;
	const int QTY_WIDTH = 3;
	const int WHOLESALE_WIDTH = 9;
	const int RETAIL_WIDTH = 8;


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
		cout << "│                                REPORT LISTING                                │" << endl;

		printBorder();

		cout << "│ " << left << setw(20) << ("DATE: " + currentDate)
			  << setw(14) << ("PAGE: " + currentStr + " of " + pageStr)
			  << setw(24) << ("DATABASE SIZE: " + databaseStr + "   CURRENT BOOK COUNT: " + countStr) << " │" << endl;


		printBorder();

		cout << "│ " << setw(TITLE_WIDTH) << "TITLE" << " " << setw(ISBN_WIDTH) << "ISBN" << " " << setw(AUTHOR_WIDTH) << "AUTHOR"
			  << " " << setw(PUBLISHER_WIDTH) << "PUBLISHER" << " " << setw(QTY_WIDTH) << "QTY" << " "
			  << setw(WHOLESALE_WIDTH) << "WHOLESALE" << " " << setw(RETAIL_WIDTH) << "RETAIL" << setw(TOTAL_WIDTH-79) << " │" << endl;

		printMidDash();

		for (int i = 0; i < BOOKS_SHOWN; i++)
		{
			cout << "│ " << setw(TITLE_WIDTH) << ((current->book->getTitle().length() > TITLE_WIDTH) ? current->book->getTitle().substr(0, TITLE_WIDTH-1) + "…" : current->book->getTitle()) << " "
		 		  << setw(ISBN_WIDTH) << current->book->getIsbn() << " "
				  << setw(AUTHOR_WIDTH) << ((current->book->getAuthor().length() > AUTHOR_WIDTH) ? current->book->getAuthor().substr(0, AUTHOR_WIDTH) : current->book->getAuthor()) << " "
				  << setw(PUBLISHER_WIDTH) << ((current->book->getPublisher().length() > PUBLISHER_WIDTH) ? current->book->getPublisher().substr(0, PUBLISHER_WIDTH) : current->book->getPublisher()) << " "
				  << setw(QTY_WIDTH) << current->book->getQty() << " "
			     << setw(WHOLESALE_WIDTH) << current->book->getWholesale() << " "
				  << setw(RETAIL_WIDTH) << current->book->getRetail()
				  << setw(TOTAL_WIDTH-79) << " │" << endl;
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

		cout << setw(TOTAL_WIDTH) << "│ Press any key to coninue ->" << "│" << endl;

		printBottomDash();

		cin.get();

		currentPage++;

		currentStr = to_string(currentPage);

	}

	return;
}

