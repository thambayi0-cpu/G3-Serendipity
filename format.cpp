/*Function Documentation*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "format.h"

using namespace std;

void printDash()
{
	cout << right << "+" << setfill('-') << setw(TOTAL_WIDTH) << "+" << setfill(' ') << left << endl;
	return;
}

void printBorder()
{
	cout << left << setw(TOTAL_WIDTH) << "│" << "│" << endl;
	return;
}

void printTopDash()
{
	cout << right << "┌" << setfill('-') << setw(TOTAL_WIDTH) << "┐" << setfill(' ') << left << endl;
	return;
}

void printBottomDash()
{
	cout << right << "└" << setfill('-') << setw(TOTAL_WIDTH) << "┘" << setfill(' ') << left << endl;
	return;
}

void printMidDash()
{
	cout << right << "├" << setfill('-') << setw(TOTAL_WIDTH) << "┤" << setfill(' ') << left << endl;
	return;
}

void printAddBookMenu(const bookType& emptyBook)
{
	const int ENTER_WIDTH = 39;

	cout << "\033[H\033[2J"; //Clear screen

	printTopDash();

   cout << "│                           SERENDIPITY BOOKSELLERS                            │" << endl;
   cout << "│                                   ADD BOOK                                   │" << endl;

   printBorder();

   cout << "│                             DATABASE SIZE: 100 CURRENT BOOK COUNT: " << left << setw(3) << bookType::bookCount << right << "       │" << endl;

	printBorder();

   cout << setw(TOTAL_WIDTH) << "│                                                 --PENDING VALUES" << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <1>  Enter Book Title" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getTitle().size() > 39 ? emptyBook.getTitle().substr(0, 37) + "… " : emptyBook.getTitle()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <2>  Enter ISBN" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getIsbn().size() > 13 ? emptyBook.getIsbn().substr(0, 13) : emptyBook.getIsbn()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <3>  Enter Author" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getAuthor().size() > 39 ? emptyBook.getAuthor().substr(0, 37) + "…" : emptyBook.getAuthor()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <4>  Enter Publisher" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getPublisher().size() > 39 ? emptyBook.getPublisher().substr(0, 37) + "…" : emptyBook.getPublisher()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <5>  Enter Date Added  (mm/dd/yyyy)" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getDate().size() > 10 ? emptyBook.getDate().substr(0, 10) : emptyBook.getDate()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <6>  Enter Quantity on Hand" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << fixed << setprecision(0) << emptyBook.getQty() << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <7>  Enter Wholesale Cost" << setw(3) << ">" << "$ " << setw(TOTAL_WIDTH - ENTER_WIDTH - 5) << setprecision(2) << emptyBook.getWholesale() << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <8>  Enter Retail Price" << setw(3) << ">" << "$ " << setw(TOTAL_WIDTH - ENTER_WIDTH - 5) << setprecision(2) << emptyBook.getRetail() << "│" << endl;

   cout << setw(TOTAL_WIDTH) << "│ <9>  Save Book to Database" << "│" << endl;

   cout << setw(TOTAL_WIDTH) << "│ <0>  Return to Inventory Menu" << "│" << endl;

   printBorder();

	printMidDash();

   cout << setw(TOTAL_WIDTH) << "│ Choice: " <<"│" << endl;

   printBottomDash();

	return;
}

void printEditBookMenu(const bookType& emptyBook)
{
	const int ENTER_WIDTH = 39;

	cout << "\033[H\033[2J"; //Clear screen

	printTopDash();

   cout << "│                           SERENDIPITY BOOKSELLERS                            │" << endl;
   cout << "│                                  EDIT BOOK                                   │" << endl;

   printBorder();

   cout << setw(ENTER_WIDTH) << "│ <1>  Edit Book Title" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getTitle().size() > 39 ? emptyBook.getTitle().substr(0, 37) + "… " : emptyBook.getTitle()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <2>  Edit ISBN" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getIsbn().size() > 13 ? emptyBook.getIsbn().substr(0, 13) : emptyBook.getIsbn()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <3>  Edit Author" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getAuthor().size() > 39 ? emptyBook.getAuthor().substr(0, 37) + "…" : emptyBook.getAuthor()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <4>  Edit Publisher" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getPublisher().size() > 39 ? emptyBook.getPublisher().substr(0, 37) + "…" : emptyBook.getPublisher()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <5>  Edit Date Added  (mm/dd/yyyy)" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << (emptyBook.getDate().size() > 10 ? emptyBook.getDate().substr(0, 10) : emptyBook.getDate()) << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <6>  Edit Quantity on Hand" << setw(3) << ">" << setw(TOTAL_WIDTH - ENTER_WIDTH - 3) << fixed << setprecision(0) << emptyBook.getQty() << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <7>  Edit Wholesale Cost" << setw(3) << ">" << "$ " << setw(TOTAL_WIDTH - ENTER_WIDTH - 5) << setprecision(2) << emptyBook.getWholesale() << "│" << endl;

   cout << setw(ENTER_WIDTH) << "│ <8>  Edit Retail Price" << setw(3) << ">" << "$ " << setw(TOTAL_WIDTH - ENTER_WIDTH - 5) << setprecision(2) << emptyBook.getRetail() << "│" << endl;

   cout << setw(TOTAL_WIDTH) << "│ <9>  Confirm Edits" << "│" << endl;

   cout << setw(TOTAL_WIDTH) << "│ <0>  Return to Inventory Menu" << "│" << endl;

   printBorder();

	printMidDash();

   cout << setw(TOTAL_WIDTH) << "│ Choice: " <<"│" << endl;

   printBottomDash();

	return;
}

string printCurrentDate()
{
	std::time_t now = std::time(nullptr);
	std::tm* local = std::localtime(&now);

	ostringstream out;

	out << std::setfill('0')
	  << std::setw(2) << (local->tm_mon + 1) << "/"
	  << std::setw(2) << local->tm_mday << "/"
	  << (local->tm_year + 1900);

	return out.str();
}


/******************************************************************************
* FUNCTION OutputClassHeading
*------------------------------------------------------------------------------
* Receives a length for heading column, a name for the programmer, title for the
* class, a section for the days and time the class takes place, assignment
* type assignment name, and the number for the assignment, character for
* class heading border, size for left border spacing, length of border
*
*------------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need a defined value passed in
* HEADING_COL    : length for the class heading asterisk line
* TITLE_COL      : setw for header titles
* PROGRAMMER     : Name of the programmer
* CLASS          : Class the assignment is for
* SECTION        : section day and time of class
* MODULE         : module number
* PURPOSE        : purpose of program
* DUE_DATE       : due date of assignment
* AS_TYPE        : type of assignment (assignment or a lab)
* AS_NAME        : Assignment name
* AS_NUM         : lab number
* BORDER_CHAR    : character for border
* BORDER_SPACING : spacing between character and text
* LINE_LENGTH    : border length
*
* POST-CONDITIONS
* ==> Returns nothing - This will output the class heading for the assignment
*
*******************************************************************************/

string OutputClassHeading
(const short  HEADING_COL   ,   // IN - asterisk string length
 const int    TITLE_COL     ,   // IN - setw for header titles
 const string PROGRAMMER    ,   // IN - name of programmer
 const string ID            ,   // IN - student IDs
 const string CLASS         ,   // IN - class title
 const string SECTION       ,   // IN - day and time of class
 const string MODULE        ,   // IN - module number
 const string PURPOSE       ,   // IN - purpose of program
 const string DUE_DATE      ,   // IN - submission due date
 const string AS_TYPE       ,   // IN - assigment type
 const string AS_NAME       ,   // IN - assignment name
 const short  AS_NUM        ,   // IN - lab number
 const char   BORDER_CHAR   ,   // IN - border character
 const short  BORDER_SPACING,   // IN - border formatting
 const short  LINE_LENGTH   )   // IN - border length

{

/***************************************************************************
* VARIABLES
****************************************************************************/
ostringstream leftBorder;    // ASGN & PROC - variable to format left border
ostringstream out;           // ASGN & OUT - variable to assign output string
string        topBotStr;     // ASGN & OUT - top/bottom character string
string        leftBorderStr; // ASGN & OUT - left border for class heading

//Assigns string of character to a variable
topBotStr = OutputStringOfCharacter(HEADING_COL) + '\n';

//Assigns border and spacing into a variable
leftBorder << left << setw(BORDER_SPACING + 1 ) << BORDER_CHAR;

//Assigns string into a variable
leftBorderStr = leftBorder.str();

// Sets justification left
out << left;

//Top border
out << topBotStr;

//Class Heading titles and info formatted
out << leftBorderStr << setw(TITLE_COL) << "PROGRAMMED BY" << ": "
<< PROGRAMMER
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "ID"            << ": "
<< ID
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "CLASS"         << ": "
<< CLASS
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "SECTION"       << ": "
<< SECTION
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "MODULE"        << ": "
<< MODULE
<< endl;
out << leftBorderStr << setw(TITLE_COL) << AS_TYPE         << ": "
<< AS_NUM
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "PROGRAM NAME"  << ": "
<< AS_NAME
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "PURPOSE"       << ": "
<< PURPOSE
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "DUE DATE"      << ": "
<< DUE_DATE
<< endl;
//Bottom border
out << topBotStr;

//Spacing
out << endl;

//Reset justification
out << right;

//Returns output as a string
return out.str();
}



/*******************************************************************************
* FUNCTION OutputStringOfCharacter
* ------------------------------------------------------------------------------
* Receives character to be output and length that character will fill
* ------------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need a defined value passed in
* CHARACTER : character for the string
* CHAR_SIZE : length of the string
*
* POST-CONDITIONS
* ==> Returns a string of a character
*
*******************************************************************************/

string OutputStringOfCharacter
(const short CHAR_SIZE, // IN - length of string
 const char  CHARACTER) // IN - character for string
{
ostringstream out;

//OUTPUT string of a character
out << setfill(CHARACTER) << setw(CHAR_SIZE) << CHARACTER;

// Resets the setfill back to default
out << setfill(' ');

return out.str();
}




/******************************************************************************
* FUNCTION EndOfProgramBanner
*******************************************************************************/

string EndOfProgramBanner
(const short  HEADING_COL   ,   // IN - asterisk string length
 const char   BORDER_CHAR   ,   // IN - border character
 const short  BORDER_SPACING,   // IN - border formatting
 const short  LINE_LENGTH )

{
/***************************************************************************
* CONSTANTS
****************************************************************************/
 const string END_STATEMENT = "E N D   O F   P R O G R A M";

/***************************************************************************
* VARIABLES
****************************************************************************/
ostringstream leftBorder;    // ASGN & PROC - variable to format left border
ostringstream out;           // ASGN & OUT - variable to assign output string
string        topBotStr;     // ASGN & OUT - top/bottom character string
string        leftBorderStr; // ASGN & OUT - left border for class heading

ostringstream         centerPadding;
ostringstream         leftCenterPadding;
ostringstream         rightCenterPadding;
string                leftCenterPaddingStr;
string                rightCenterPaddingStr;

//Assigns string of character to a variable
topBotStr = OutputStringOfCharacter(HEADING_COL) + '\n';

//Assigns border and spacing into a variable
leftBorder         << left << setw(BORDER_SPACING + 1 ) << BORDER_CHAR;

leftCenterPadding  << left << setw( ((HEADING_COL - END_STATEMENT.length()) / 2) - 2 ) << " ";

rightCenterPadding << left << setw( ((HEADING_COL - END_STATEMENT.length()) / 2))      << " ";


//Assigns string into a variable
leftBorderStr = leftBorder.str();

leftCenterPaddingStr  = leftCenterPadding.str();

rightCenterPaddingStr = rightCenterPadding.str();

// Sets justification left
out << left;

// OUTPUTS  end of program banner

//Top border
out << endl << endl << topBotStr;

//end of program statement
out << BORDER_CHAR << setfill(' ') << setw(HEADING_COL -1) << right << BORDER_CHAR;
out << endl << leftBorderStr << leftCenterPaddingStr << END_STATEMENT;
out << rightCenterPaddingStr << leftBorderStr << endl;
out << BORDER_CHAR << setfill(' ') << setw(HEADING_COL -1) << right << BORDER_CHAR;
out << endl;


//Bottom border
out << topBotStr;

//Spacing
out << endl;

//Reset justification
out << right;

//Returns output as a string
return out.str();
}


/******************************************************************************
* FUNCTION PrintMainMenu
*******************************************************************************/

string PrintMainMenu()

{
	/***************************************************************************
	* CONSTANTS
	****************************************************************************/
 	const string VERTICAL_BORDER     = "\xE2\x94\x80";
 	const string HORIZONTAL_BORDER   = "\xE2\x94\x82";
 	const string TOP_LEFT_BORDER     = "\xE2\x94\x8C";
 	const string TOP_RIGHT_BORDER    = "\xE2\x94\x90";
 	const string BOTTOM_LEFT_BORDER  = "\xE2\x94\x94";
 	const string BOTTOM_RIGHT_BORDER = "\xE2\x94\x98";
 	const string COMPANY_NAME        = "Serendipity Booksellers";
 	const string TITLE               = "Main Menu";
 	const string SELECTION_ONE       = "1. Cashier Module";
 	const string SELECTION_TWO       = "2. Inventory Database Module";
 	const string SELECTION_THREE     = "3. Report Module";
 	const string SELECTION_FOUR      = "4. Exit";
	const string INPUT_PROMPT        = "Enter Your Choice: ";
 	const string INPUT_PROMPT_RANGE  = "Please enter a number in the range 1 - 4.";
	/***************************************************************************
	* VARIABLES
	****************************************************************************/
	ostringstream out;           // ASGN & OUT - variable to assign output string
	string        topBotStr;     // ASGN & OUT - top/bottom border string

	// Inserts many border characters into string

	for (int i = 0; i < 61; i++)
	{
		topBotStr += VERTICAL_BORDER;
	}


	// Sets justification left
	out << left;


	// Top border output
	out << endl << endl << TOP_LEFT_BORDER << topBotStr << TOP_RIGHT_BORDER << endl;

	// Menu titles and selection info

	out << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(20) << " "   << COMPANY_NAME       << setfill(' ') << setw(21) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(28) << " "   << TITLE              << setfill(' ') << setw(27) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_ONE      << setfill(' ') << setw(30) << right << HORIZONTAL_BORDER
	 	 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_TWO      << setfill(' ') << setw(19) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_THREE    << setfill(' ') << setw(31) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_FOUR     << setfill(' ') << setw(40) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT       << setfill(' ') << setw(28) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT_RANGE << setfill(' ') << setw(6)  << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl;


	// Bottom border
	out << BOTTOM_LEFT_BORDER << topBotStr << BOTTOM_RIGHT_BORDER;

	// Spacing
	out << endl;

	// Reset justification
	out << right;

	// Returns output as a string
	return out.str();
}







/******************************************************************************
* FUNCTION PrintInvMenu
*******************************************************************************/

string PrintInvMenu()

{
	/***************************************************************************
	* CONSTANTS
	****************************************************************************/
 	const string VERTICAL_BORDER     = "\xE2\x94\x80";
 	const string HORIZONTAL_BORDER   = "\xE2\x94\x82";
 	const string TOP_LEFT_BORDER     = "\xE2\x94\x8C";
 	const string TOP_RIGHT_BORDER    = "\xE2\x94\x90";
 	const string BOTTOM_LEFT_BORDER  = "\xE2\x94\x94";
 	const string BOTTOM_RIGHT_BORDER = "\xE2\x94\x98";
 	const string COMPANY_NAME        = "Serendipity Booksellers";
 	const string TITLE               = "Inventory Database";
 	const string SELECTION_ONE       = "1. Look Up a Book";
 	const string SELECTION_TWO       = "2. Add a Book";
 	const string SELECTION_THREE     = "3. Edit a Book's Record";
 	const string SELECTION_FOUR      = "4. Delete a Book";
	const string SELECTION_FIVE      = "5. Return to the Main Menu";
	const string INPUT_PROMPT        = "Enter Your Choice: ";
 	const string INPUT_PROMPT_RANGE  = "Please enter a number in the range 1 - 5.";
	/***************************************************************************
	* VARIABLES
	****************************************************************************/
	ostringstream out;           // ASGN & OUT - variable to assign output string
	string        topBotStr;     // ASGN & OUT - top/bottom border string

	// Inserts many border characters into string

	for (int i = 0; i < 61; i++)
	{
		topBotStr += VERTICAL_BORDER;
	}


	// Sets justification left
	out << left;


	// Top border output
	out << endl << endl << TOP_LEFT_BORDER << topBotStr << TOP_RIGHT_BORDER << endl;

	// Menu titles and selection info

	out << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(20) << " "   << COMPANY_NAME       << setfill(' ') << setw(21) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(23) << " "   << TITLE              << setfill(' ') << setw(23) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_ONE      << setfill(' ') << setw(30) << right << HORIZONTAL_BORDER
	 	 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_TWO      << setfill(' ') << setw(34) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_THREE    << setfill(' ') << setw(24) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_FOUR     << setfill(' ') << setw(31) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_FIVE     << setfill(' ') << setw(21) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT       << setfill(' ') << setw(28) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT_RANGE << setfill(' ') << setw(6)  << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl;


	// Bottom border
	out << BOTTOM_LEFT_BORDER << topBotStr << BOTTOM_RIGHT_BORDER;

	// Spacing
	out << endl;

	// Reset justification
	out << right;

	// Returns output as a string
	return out.str();
}



/******************************************************************************
* FUNCTION PrintReportsMenu
*******************************************************************************/

string PrintReportsMenu()

{
	/***************************************************************************
	* CONSTANTS
	****************************************************************************/
 	const string VERTICAL_BORDER     = "\xE2\x94\x80";
 	const string HORIZONTAL_BORDER   = "\xE2\x94\x82";
 	const string TOP_LEFT_BORDER     = "\xE2\x94\x8C";
 	const string TOP_RIGHT_BORDER    = "\xE2\x94\x90";
 	const string BOTTOM_LEFT_BORDER  = "\xE2\x94\x94";
 	const string BOTTOM_RIGHT_BORDER = "\xE2\x94\x98";
 	const string COMPANY_NAME        = "Serendipity Booksellers";
 	const string TITLE               = "Reports";
 	const string SELECTION_ONE       = "1. Inventory Listing";
 	const string SELECTION_TWO       = "2. Inventory Wholesale Value";
 	const string SELECTION_THREE     = "3. Inventory Retail Value";
 	const string SELECTION_FOUR      = "4. Listing by Quanitity";
	const string SELECTION_FIVE      = "5. Listing by Cost";
	const string SELECTION_SIX       = "6. Listing by Age";
	const string SELECTION_SEVEN     = "7. Return to Main Menu";
	const string INPUT_PROMPT        = "Enter Your Choice: ";
 	const string INPUT_PROMPT_RANGE  = "Please enter a number in the range 1 - 7.";
	/***************************************************************************
	* VARIABLES
	****************************************************************************/
	ostringstream out;           // ASGN & OUT - variable to assign output string
	string        topBotStr;     // ASGN & OUT - top/bottom border string

	// Inserts many border characters into string

	for (int i = 0; i < 61; i++)
	{
		topBotStr += VERTICAL_BORDER;
	}


	// Sets justification left
	out << left;


	// Top border output
	out << endl << endl << TOP_LEFT_BORDER << topBotStr << TOP_RIGHT_BORDER << endl;

	// Menu titles and selection info

	out << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(20) << " "   << COMPANY_NAME       << setfill(' ') << setw(21) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(29) << " "   << TITLE              << setfill(' ') << setw(28) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_ONE      << setfill(' ') << setw(27) << right << HORIZONTAL_BORDER
	 	 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_TWO      << setfill(' ') << setw(19) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_THREE    << setfill(' ') << setw(22) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " " << "\x1b[2m" << "\033[90m" << SELECTION_FOUR << "\x1b[0m" << setfill(' ') << setw(24) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " " << "\x1b[2m" << "\033[90m" << SELECTION_FIVE << "\x1b[0m" << setfill(' ') << setw(29) << right << HORIZONTAL_BORDER
		 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " " << "\x1b[2m" << "\033[90m" << SELECTION_SIX << "\x1b[0m" << setfill(' ') << setw(30) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " " << SELECTION_SEVEN    << setfill(' ') << setw(25) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT       << setfill(' ') << setw(28) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT_RANGE << setfill(' ') << setw(6)  << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl;


	// Bottom border
	out << BOTTOM_LEFT_BORDER << topBotStr << BOTTOM_RIGHT_BORDER;

	// Spacing
	out << endl;

	// Reset justification
	out << right;

	// Returns output as a string
	return out.str();
}










string PrintLookUpBookMenu()

{
	/***************************************************************************
	* CONSTANTS
	****************************************************************************/
 	const string VERTICAL_BORDER     = "\xE2\x94\x80";
 	const string HORIZONTAL_BORDER   = "\xE2\x94\x82";
 	const string TOP_LEFT_BORDER     = "\xE2\x94\x8C";
 	const string TOP_RIGHT_BORDER    = "\xE2\x94\x90";
 	const string BOTTOM_LEFT_BORDER  = "\xE2\x94\x94";
 	const string BOTTOM_RIGHT_BORDER = "\xE2\x94\x98";
 	const string COMPANY_NAME        = "Serendipity Booksellers";
 	const string TITLE               = "Look Up a Book";
	const string INPUT_PROMPT        = "Search title or ISBN: ";
	const string INPUT_PROMPT_RANGE  = "Press ENTER to exit";
	/***************************************************************************
	* VARIABLES
	****************************************************************************/
	ostringstream out;           // ASGN & OUT - variable to assign output string
	string        topBotStr;     // ASGN & OUT - top/bottom border string

	// Inserts many border characters into string

	for (int i = 0; i < 61; i++)
	{
		topBotStr += VERTICAL_BORDER;
	}


	// Sets justification left
	out << left;


	// Top border output
	out << endl << endl << TOP_LEFT_BORDER << topBotStr << TOP_RIGHT_BORDER << endl;

	// Menu titles and selection info

	out << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(20) << " "   << COMPANY_NAME       << setfill(' ') << setw(21) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(25) << " "   << TITLE              << setfill(' ') << setw(25) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(10) << " "   << INPUT_PROMPT       << setfill(' ') << setw(32) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(20) << " "   << INPUT_PROMPT_RANGE << setfill(' ') << setw(25)  << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl;


	// Bottom border
	out << BOTTOM_LEFT_BORDER << topBotStr << BOTTOM_RIGHT_BORDER;

	// Spacing
	out << endl;

	// Reset justification
	out << right;

	// Returns output as a string
	return out.str();
}
