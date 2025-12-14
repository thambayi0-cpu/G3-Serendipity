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
#include "cashier.h"
#include "invMenu.h"
#include "reports.h"
#include "bookType.h"
#include "bookNode.h"

int main()
{
	// Constants
	const string INPUT_PROMPT     = "Enter Your Choice: ";
	const string INPUT_PRINT      = "You selected item ";
	const short  INPUT_PRINT_FILL = 44;
	const string INVALID_INPUT    = "Invalid input. Enter a number range 1 - 4.";
	const string CLEAR_SCREEN     = "\x1b[H\x1b[2J";
	const string RESET            = "\x1b[0m";
	const string RED              = "\x1b[31m";
	const string GREEN            = "\x1b[32m";



	// Variables
	string         headingString;              // OUT  - class heading
	string         endOfProgramString;         // OUT  - end of program statement
	string         printMainMenuString;			 // OUT  - mainmenu print
	string         printInvMenuString;         // OUT  - invMenu print
	char           choice;                     // PROC - choice switch selection
	string			choiceString;               // IN   - input
	bool           invalidInputBool;           // IN   - error check bool
	bool				keepActive;                 // PROC - bool for do while main menu

	short          inputPrintHeight;           // FORM - cursor position
	short          inputPrintRow;              // FORM - cursor position
   short          inputPromptHeight;          // FORM - cursor position
	short          inputPromptRow;             // FORM - cursor position

	ostringstream  inputPrompt;                // PROC - cursor position and prompt stores inputPromptStr
	string         inputPromptStr;				 // OUT  - input prompt

	ostringstream  inputPrint;                 // PROC - cursor position and input selection print stores in inputPrintStr
	string         inputPrintStr;              // OUT  - input selection print

	ostringstream  invalidInput;               // PROC - cursor position and error message stores in invalidInputStr
	string			invalidInputStr;            // OUT  - error message

	ostringstream  pressEnter;                 // PROC - cursor position and press enter prompt stores in pressEnterStr
	string         pressEnterStr;              // OUT  - press enter prompt

	ostringstream  goodByeMessage;				 // PROC - cursor position and good bye message stores in goodByeMessageStr
	string         goodByeMessageStr;			 // OUT  - good bye message

	bookNode *head = nullptr; // Head of the linked list
	bookNode *tail = nullptr; // Tail of the linked list
	bool calledBack = false;

	// INITIALIZATIONS
	headingString         = OutputClassHeading();
	endOfProgramString    = EndOfProgramBanner();
	printMainMenuString   = PrintMainMenu();
	printInvMenuString    = PrintInvMenu();

	keepActive            = true;

	inputPrintHeight      = 19;
	inputPrintRow         = 27;
   inputPromptHeight     = 19;
	inputPromptRow        = 25;

	inputPrompt           << "\x1b[" << inputPromptRow << ";" << inputPromptHeight << "H" << setfill(' ') << setw(INPUT_PROMPT.length())
							    << "\x1b[" << inputPromptRow << ";" << inputPromptHeight << "H" << INPUT_PROMPT;
	inputPromptStr        = inputPrompt.str();


	inputPrint            << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							    << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INPUT_PRINT;
	inputPrintStr         = inputPrint.str();


	invalidInput          << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							    << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INVALID_INPUT;
	invalidInputStr       = invalidInput.str();


	pressEnter            << "\x1b[31;14H" << "\x1b[5m" << "\x1b[1m" << "\x1b[37m" << "\x1b[44m" << "    Press  E N T E R  to continue    " << RESET;
	pressEnterStr         = pressEnter.str();

	goodByeMessage        << "\x1b[31;14H" << setfill(' ') << setw(36)   << " "
		  					    << "\x1b[31;14H" << "\x1b[30m" << "\x1b[43m" << setfill(' ') << setw(37) << " "
	     					    << "\x1b[32;14H" << "\x1b[30m" << "\x1b[43m" << "     S e e  y o u  l a t e r  : )    "
	     					 	 << "\x1b[33;14H" << "\x1b[30m" << "\x1b[43m" << setfill(' ') << setw(37) << "  " << RESET;
	goodByeMessageStr     = goodByeMessage.str();




	// Clear Screen
	cout << CLEAR_SCREEN;


	// OUTPUT HEADING - Class heading output
	cout << headingString;


	// INPUT - Main Menu Display
	cout << printMainMenuString;


	// INPUT - Main Menu Input Prompt for "Choice"
	while (keepActive)
	{

		// INPUT - Menu Prompt
		invalidInputBool = true;
		choice = 0;

		if (calledBack)
			cout << CLEAR_SCREEN << headingString << printMainMenuString;

		do
		{
			// Input
			cout << inputPromptStr;
			getline(cin, choiceString);

			// Clear enter from input buffer
			while (!choiceString.empty()        &&
				   ( choiceString.back() == '\r' ||
					  choiceString.back() == '\n' ||
					  choiceString.back() == '\t' ||
					  choiceString.back() == ' '  ))
			{
				choiceString.pop_back();
			}

			// Error checking
			if(choiceString.size() == 1 && choiceString[0] >= '1' && choiceString[0] <= '4')
			{
				choice = choiceString[0];
				invalidInputBool = false;
				if (calledBack)
					calledBack = false;
			}
			else
			{
				if (!calledBack)
					cout << CLEAR_SCREEN << headingString << printMainMenuString << inputPromptStr << RED << invalidInputStr << RESET;
				else
					calledBack = false;
			}

		} while (invalidInputBool);






		// Selection statment for menu options
		switch (choice)
		{
			// Cashier
			case '1':
				if (bookType::bookCount == 0)
				{
					cout << CLEAR_SCREEN << headingString << printMainMenuString << inputPromptStr
					<< RED << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ')
					<< setw(INPUT_PRINT_FILL) << " " << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight << "H"
					<< "Inventory empty." << RESET;
				}
				else
				{
					cout << GREEN << inputPrintStr << choice << "." << RESET;
					//cout << pressEnterStr;
					//cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cashier(head, tail);
					calledBack = true;
				}

				break;

			// Inventory Menu
			case '2':
				cout << GREEN << inputPrintStr << choice << "." << RESET;

				//cout << pressEnterStr;
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');

				invMenu(head, tail);
				calledBack = true;
				break;

			// Reports Menu
			case '3':
				cout << GREEN << inputPrintStr << choice << "." << RESET;

				//cout << pressEnterStr;
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');

				reports(head, tail);
				calledBack = true;
				break;

			// Exit
			case '4':
				cout << GREEN << inputPrintStr << choice << "." << RESET;

				//cout << pressEnterStr;
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepActive = false;
				break;

			// Invaild Input
			default:
				cout << RED << invalidInputStr << RESET;
				break;
		}

	}

	destroyList(head, tail);

	// OUTPUT - Good bye message
	cout << goodByeMessageStr;


	// OUTPUT - End of Program Banner
	cout << endl << endl << endl << endl << endOfProgramString  << endl << endl;
	return 0;
}

