/*Program header*/

#ifndef INVMENU_H
#define INVMENU_H

#include <string>
#include <vector>
#include "bookType.h"

void invMenu(bool &keepInvMenuActive, std::vector<bookType>& books);

void lookUpBook(bool &keepInvMenuActive, bool &keeplookUpBookMenuActive, std::vector<bookType>& books);

void addBook(bool &keepInvMenuActive, bool &keepAddBookMenuActive, std::vector<bookType>& books);

void editBook(bool &keepInvMenuActive, bool &keepeditBookMenuActive);

void deleteBook(bool &keepInvMenuActive, bool &keepdeleteBookMenuActive);


#endif
