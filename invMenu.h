/**
 * @file invMenu.h
 * @brief Function declarations for the bookstore inventory menu system.
 *
 * These functions operate on a vector of bookType objects and use the static
 * field bookType::bookCount to track the total number of books in the
 * inventory. The maximum number of books allowed is 20.
 */

#ifndef INVMENU_H
#define INVMENU_H

#include <string>
#include <vector>
#include "bookType.h"

/**
 * @brief Display and manage the main inventory menu.
 *
 * This menu allows the user to add, edit, delete, and search for books.
 *
 * @param books Reference to the inventory vector.
 *
 * @pre `bookType::bookCount` accurately reflects the number of active books.
 * @post The contents of `books` may be modified depending on user input.
 */
void invMenu(std::vector<bookType>& books);

/**
 * @brief Search the inventory for a book by title or ISBN number.
 *
 * Prompts the user to search by either title or ISBN. Scans the vector
 * and returns the index of the matching book.
 *
 * @param books Constant reference to the inventory vector.
 * @return The index of the matching book, or -1 if not found.
 *
 * @pre `bookType::bookCount` corresponds to the actual number of books.
 * @post No modification to `books`.
 */
int lookUpBook(const std::vector<bookType>& books);

/**
 * @brief Add a new book to the inventory (maximum of 20 books).
 *
 * Collects book information from the user and appends a new entry to the vector.
 * The addition is only allowed if `bookType::bookCount < 20`.
 *
 * @param books Reference to the inventory vector.
 *
 * @pre `bookType::bookCount < 20`.
 *      If `bookCount == 20`, the function not run.
 * @post
 *      - If `bookType::bookCount < 20`, a new book is added and bookCount is incremented.
 *      - If `bookType::bookCount == 20`, no change is made.
 */
void addBook(std::vector<bookType>& books);

/**
 * @brief Edit an existing book in the inventory.
 *
 * Uses lookUpBook() to locate a book by title or ISBN, then allows modifying it.
 *
 * @param books Reference to the inventory vector.
 *
 * @pre `bookType::bookCount > 0` (cannot edit an empty inventory).
 * @post Only the selected book may be modified.
 */
void editBook(std::vector<bookType>& books);

/**
 * @brief Delete a book from the inventory.
 *
 * Uses lookUpBook() to locate a book by title or ISBN, and removes it if found.
 *
 * @param books Reference to the inventory vector.
 *
 * @pre `bookType::bookCount > 0` (cannot delete from an empty inventory).
 * @post
 *      - If the book exists, it is erased from the vector and `bookType::bookCount` is decremented.
 *      - If not found, no modification is made.
 */
void deleteBook(std::vector<bookType>& books);

#endif // INVMENU_H

