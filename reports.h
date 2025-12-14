#ifndef REPORTS_H
#define REPORTS_H

#include "bookNode.h"

/**
 * @brief Displays the reports menu and dispatches the selected report.
 *
 * This function serves as the main entry point for all inventory reports.
 * It presents the user with a menu of available report options and calls
 * the corresponding report function based on user input.
 *
 * @pre head and tail point to the first and last nodes of a valid linked list
 *      or are both nullptr if the list is empty.
 * @post The inventory linked list is not modified.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void reports(bookNode*& head, bookNode*& tail);


/**
 * @brief Displays a full listing of all books in the inventory.
 *
 * Traverses the linked list from head to tail and displays complete
 * information for each book, including title, ISBN, author, publisher,
 * date added, wholesale price, retail price, and quantity.
 * This function assumes the inventory list is non-empty.
 * Access is restricted by the main menu when the list is empty
 *
 * @pre head and tail are non-null and refer to a valid list.
 * @post The inventory linked list remains unchanged.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void repListing(bookNode*& head, bookNode*& tail);


/**
 * @brief Displays a wholesale value report for all books.
 *
 * Traverses the linked list and displays each book's title, ISBN,
 * quantity on hand, and wholesale price. At the end of the report,
 * the total wholesale value of the inventory is displayed.
 * This function is only callable when the inventory list
 * contains at least one node.
 *
 * @pre head and tail are non-null and refer to a valid list.
 * @post The inventory linked list remains unchanged.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void repWholesale(bookNode*& head, bookNode*& tail);


/**
 * @brief Displays a retail value report for all books.
 *
 * Traverses the linked list and displays each book's title, ISBN,
 * quantity on hand, and retail price. At the end of the report,
 * the total retail value of the inventory is displayed.
 * This function is only callable when the inventory list
 * contains at least one node.
 *
 * @pre head and tail are non-null and refer to a valid list.
 * @post The inventory linked list remains unchanged.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void repRetail(bookNode*& head, bookNode*& tail);


/**
 * @brief Lists books sorted by quantity on hand.
 *
 * This report is optional and may not be implemented. If implemented,
 * the linked list will be reordered based on the quantity of each book
 * before displaying the inventory.
 * This function is only callable when the inventory list
 * contains at least one node.
 *
 * @pre head and tail are non-null and refer to a valid list.
 * @post If implemented, the linked list is reordered according to book quantity.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void repQty(bookNode*& head, bookNode*& tail);


/**
 * @brief Lists books sorted by wholesale cost.
 *
 * This report is optional and may not be implemented. If implemented,
 * the linked list will be reordered based on the wholesale cost of each book
 * before displaying the inventory.
 * This function is only callable when the inventory list
 * contains at least one node.
 *
 * @pre head and tail are non-null and refer to a valid list.
 * @post If implemented, the linked list is reordered according to wholesale cost.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void repCost(bookNode*& head, bookNode*& tail);


/**
 * @brief Lists books sorted by age in inventory.
 *
 * This report is optional and may not be implemented. If implemented,
 * the linked list will be reordered based on the age of each book
 * in the inventory before displaying the results.
 * This function is only callable when the inventory list
 * contains at least one node.
 *
 * @pre head and tail are non-null and refer to a valid list.
 * @post If implemented, the linked list is reordered according to book age.
 *
 * @param head Reference to the pointer to the first node in the linked list.
 * @param tail Reference to the pointer to the last node in the linked list.
 */
void repAge(bookNode*& head, bookNode*& tail);


#endif

