/**
 * @file invMenu.h
 * @brief Function declarations for the bookstore inventory menu system.
 *
 * This module provides functions to manage the inventory of books
 * stored as a singly linked list of bookNode objects. Each node
 * contains a dynamically allocated bookType object.
 *
 * The static member bookType::bookCount tracks the total number
 * of books currently in the inventory.
 */

#ifndef INVMENU_H
#define INVMENU_H

#include <string>
#include "bookType.h"
#include "bookNode.h"

/**
 * @brief Display and manage the main inventory menu.
 *
 * Presents options to add, edit, delete, and search for books
 * in the inventory linked list.
 *
 * @param head Reference to the head pointer of the book linked list.
 * @param tail Reference to the tail pointer of the book linked list.
 *
 * @pre head and tail are either both nullptr (empty list)
 *      or both point to valid nodes in the same linked list.
 * @post The linked list may be modified depending on user actions.
 */
void invMenu(bookNode*& head, bookNode*& tail);

/**
 * @brief Search the inventory for a book by title or ISBN.
 *
 * Traverses the linked list and compares each book's title
 * or ISBN against user input.
 *
 * @param head Pointer to the first node in the linked list.
 * @return Pointer to the matching bookType object, or nullptr if not found.
 *
 * @pre head is either nullptr or points to a valid linked list.
 * @post The linked list and all book data remain unchanged.
 */
bookType* lookUpBook(const bookNode* head);

/**
 * @brief Add a new book to the inventory.
 *
 * Collects book information from the user, dynamically allocates
 * a new bookType and bookNode, and inserts the node into the
 * linked list in sorted order.
 *
 * @param head Reference to the head pointer of the linked list.
 * @param tail Reference to the tail pointer of the linked list.
 *
 * @pre head and tail are valid references to the linked list.
 * @post
 *      - A new node is added to the list.
 *      - bookType::bookCount is incremented by one.
 */
void addBook(bookNode*& head, bookNode*& tail);

/**
 * @brief Edit an existing book in the inventory.
 *
 * Uses lookUpBook() to locate a book, allows the user to modify
 * its contents, and reinserts the corresponding node to maintain
 * list order.
 *
 * @param head Reference to the head pointer of the linked list.
 * @param tail Reference to the tail pointer of the linked list.
 *
 * @pre bookType::bookCount > 0.
 * @post Only the selected book's data may be modified; the list
 *       remains properly linked and ordered.
 */
void editBook(bookNode*& head, bookNode*& tail);

/**
 * @brief Delete a book from the inventory.
 *
 * Locates a book using lookUpBook(), removes the corresponding
 * node from the linked list, and deallocates all associated memory.
 *
 * @param head Reference to the head pointer of the linked list.
 * @param tail Reference to the tail pointer of the linked list.
 *
 * @pre bookType::bookCount > 0.
 * @post
 *      - The selected node and its bookType object are deleted.
 *      - bookType::bookCount is decremented by one.
 *      - head and/or tail may be updated.
 */
void deleteBook(bookNode*& head, bookNode*& tail);

/**
 * @brief Convert a string to lowercase.
 *
 * Used primarily for case-insensitive comparisons in lookUpBook().
 *
 * @param s The string to convert.
 * @return A lowercase copy of the input string.
 *
 * @pre None.
 * @post The original string remains unchanged.
 */
std::string toLower(std::string s);

#endif // INVMENU_H
