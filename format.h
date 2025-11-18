
#ifndef FORMAT_H
#define FORMAT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include "bookType.h"


using namespace std;


const int TOTAL_WIDTH = 81;

void printDash(); //Prints +-----+

void printBorder(); //Prints |     |

void printTopDash();

void printBottomDash();

void printMidDash();

void printAddBookMenu(const bookType& emptyBook);

void printEditBookMenu(const bookType& emptyBook);

/******************************************************************************
* FUNCTION OutputClassHeading
* -----------------------------------------------------------------------------
* Receives the size to format titles programmer's name, the class for the
* assignment, the section day and time for the class, assignment type
* (assignment or lab) assignment name and assignment number.
*
* ==> returns nothing - This will output the class heading for the assignment.
*******************************************************************************/
string OutputClassHeading
 (const short  HEADING_COL    = 76,							                            // IN - asterisk string length
  const int    TITLE_COL      = 14,								                         // IN - setw for header titles
  const string PROGRAMMER     = "Ahmer Yasin & Thokozile Hambayi",                // IN - name of programmer
  const string ID             = "A00349012   & 127485",                           // IN - Student IDs
  const string CLASS          = "CS1B",                                           // IN - class title
  const string SECTION        = "TTh 1:30pm",              	                      // IN - day and time of class
  const string MODULE         = "2",                                              // IN - module number
  const string PURPOSE        = "Bookstore POS",                                  // IN - lab description
  const string DUE_DATE       = "09/23/2025",                                     // IN - due date
  const string AS_TYPE        = "GROUP PROJECT",                   	     	       // IN - assignment type
  const string AS_NAME        = "Menus (Navigation & Stubs)",                     // IN - assignment name
  const short  AS_NUM         = 2,                        		                   // IN - assignment number
  const char   BORDER_CHAR    = '*',                   			                   // IN - border character
  const short  BORDER_SPACING = 1,                 			                      // IN - border formatting
  const short  LINE_LENGTH    = 76);                  			                   // IN - border length


/******************************************************************************
* FUNCTION OutputStringOfCharacter
* -----------------------------------------------------------------------------
* Receives a character for setfill() and length for the setw().
*
* ==> returns nothing - This will output the string of a character
******************************************************************************/
string OutputStringOfCharacter
(const short CHAR_SIZE,        // IN - character string size
 const char  CHARACTER = '*'); // IN - character for string


string EndOfProgramBanner
(const short  HEADING_COL    = 76,   // IN - asterisk string length
 const char   BORDER_CHAR    = '*',  // IN - border character
 const short  BORDER_SPACING = 1,    // IN - border formatting
 const short  LINE_LENGTH    = 76);  // IN - border length

string PrintMainMenu();

string PrintInvMenu();

string PrintReportsMenu();

string PrintLookUpBookMenu();


#endif
