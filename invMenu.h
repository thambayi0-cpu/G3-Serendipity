/*Program header*/

#ifndef INVMENU_H
#define INVMENU_H

#include <string>
#include <vector>
#include "bookType.h"

void invMenu(std::vector<bookType>& books);

int lookUpBook(const std::vector<bookType>& books);

void addBook(std::vector<bookType>& books);

void editBook(std::vector<bookType>& books);

void deleteBook(std::vector<bookType>& books);


#endif
