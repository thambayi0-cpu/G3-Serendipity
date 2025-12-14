/*Program header*/

#ifndef REPORTS_H
#define REPORTS_H

#include "bookNode.h"

void reports(bookNode*& head, bookNode*& tail); //Display reports menu

void repListing(bookNode*& head, bookNode*& tail); //List all books, including title, ISBN, author, publisher, date added, wholesale price, retail price, & quantity

void repWholesale(bookNode*& head, bookNode*& tail); //List all books, including only title, ISBN, qty, & wholesale cost. End w/ total wholesale value

void repRetail(bookNode*& head, bookNode*& tail); //List all books, including only title, ISBN, qty, & retail cost. End w/ total retail value

void repQty(bookNode*& head, bookNode*& tail); //List by quantity (not required)

void repCost(bookNode*& head, bookNode*& tail); //List by cost (again, not required) presumably wholesale

void repAge(bookNode*& head, bookNode*& tail); //List books by age (again, not required)

#endif
