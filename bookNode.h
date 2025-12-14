#ifndef BOOKNODE_H
#define BOOKNODE_H

#include "bookType.h"

/**
 * @struct bookNode
 * @brief Node structure for the inventory linked list.
 *
 * Each node stores a pointer to a dynamically allocated bookType
 * object and a pointer to the next node in the list.
 *
 * @invariant
 * - book points to a valid bookType object or nullptr only during teardown.
 * - next is either nullptr or points to another valid bookNode.
 */
struct bookNode
{
    bookType* book;   ///< Pointer to the book data stored in this node
    bookNode* next;   ///< Pointer to the next node in the list
};

/**
 * @brief Deletes a single node from the linked list.
 *
 * Removes the node containing the specified book from the list,
 * updates head and tail pointers as necessary, and deallocates
 * all associated dynamic memory.
 *
 * @param[in,out] head Reference to the head pointer of the list
 * @param[in,out] tail Reference to the tail pointer of the list
 * @param[in,out] nodeToDelete Pointer to the bookType to be removed
 *
 * @pre
 * - head and tail are either both nullptr (empty list) or both valid.
 * - nodeToDelete points to a bookType that exists in the list.
 *
 * @post
 * - The node containing nodeToDelete is removed from the list.
 * - Memory for both the bookType and its bookNode is deallocated.
 * - head and tail are updated if the deleted node was at either end.
 * - The list remains properly linked.
 */
void deleteNode(bookNode*& head, bookNode*& tail, bookType*& nodeToDelete);

/**
 * @brief Deallocates all nodes in the linked list.
 *
 * Traverses the list, deleting each bookNode and its associated
 * bookType object, leaving the list empty.
 *
 * @param[in,out] head Reference to the head pointer of the list
 * @param[in,out] tail Reference to the tail pointer of the list
 *
 * @pre
 * - head and tail are either both nullptr or both valid.
 *
 * @post
 * - All dynamically allocated nodes and books are deleted.
 * - head and tail are set to nullptr.
 */
void destroyList(bookNode*& head, bookNode*& tail);

/**
 * @brief Inserts a node into the list while preserving sorted order.
 *
 * Inserts the given node into the linked list such that the list
 * remains ordered according to bookType's comparison operator
 * (typically by title).
 *
 * @param[in,out] head Reference to the head pointer of the list
 * @param[in,out] tail Reference to the tail pointer of the list
 * @param[in,out] nodeToAdd Pointer to the node to insert
 *
 * @pre
 * - nodeToAdd is a valid bookNode.
 * - nodeToAdd->next is nullptr.
 * - The existing list (if any) is already sorted.
 *
 * @post
 * - nodeToAdd is inserted into the list in sorted position.
 * - head and/or tail are updated if insertion occurs at either end.
 * - The list remains sorted after insertion.
 */
void insertOrdered(bookNode*& head, bookNode*& tail, bookNode*& nodeToAdd);

#endif
