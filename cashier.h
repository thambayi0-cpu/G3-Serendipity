#ifndef CASHIER_H
#define CASHIER_H

#include "bookNode.h"

/**
 * @file cashier.h
 * @brief Interface for the cashier (sales transaction) module.
 */

/**
 * @brief Handles customer purchase transactions.
 *
 * Allows the user to select one or more books from the inventory,
 * specify purchase quantities, and generates a receipt for the
 * transaction. Inventory quantities are updated accordingly.
 *
 * This function operates directly on the inventory linked list
 * and does not assume indexed or random access.
 *
 * @param[in,out] head Reference to the head of the inventory list
 * @param[in,out] tail Reference to the tail of the inventory list
 *
 * @pre
 * - head and tail are either both nullptr (empty inventory) or both valid.
 * - The linked list is properly linked and ordered.
 *
 * @post
 * - Inventory quantities are reduced based on completed purchases.
 * - No structural changes are made to the list itself.
 * - head and tail remain valid.
 *
 * @note
 * - This function does not allocate or deallocate inventory objects.
 * - Selected books are tracked using existing book pointers
 *   stored in temporary containers (e.g., vectors).
 * - Behavior depends on user input; transactions may be canceled.
 */
void cashier(bookNode*& head, bookNode*& tail);

#endif

