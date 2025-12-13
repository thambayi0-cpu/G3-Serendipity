
#include "bookNode.h"

void deleteNode(bookNode*& head, bookNode*& tail, bookType*& nodeToDelete)
{
	bookNode* current = head;
	bookNode* prev = nullptr;

	while (current != nullptr && current->book != nodeToDelete)
	{
		prev = current;
		current = current->next;
	}
   if (current == head)
   {
		if (bookType::bookCount == 1)
			head = tail = nullptr;
		else
			head = head->next;

		delete current->book;
		delete current;
   }
   else if (current == tail)
   {
		prev->next = nullptr;
		tail = prev;
		delete current->book;
		delete current;
   }
   else
   {
		prev->next = current->next;
		delete current->book;
		delete current;
   }
   current = nullptr;
   bookType::bookCount--;
}

void destroyList(bookNode*& head, bookNode*& tail)
{
	bookNode *current = head;

	bookNode *previous = nullptr;

	while (current != nullptr)
	{
		previous = current;

		current = current->next;

		delete previous->book;

		delete previous;

		bookType::bookCount--;
	}

	head = nullptr;

	tail = nullptr;

	return;
}

void insertOrdered(bookNode*& head, bookNode*& tail, bookNode*& nodeToAdd)
{
	bookNode* current;
	bookNode* prev;

	if (head == nullptr)
	{
		head = tail = nodeToAdd;
		return;
	}

	while (current != nullptr && *(current->book) < *(nodeToAdd->book))
	{
		prev = current;
		current = current->next;
	}
	if (current == head)
	{
		nodeToAdd->next = head;
		head = nodeToAdd;
	}
	else if (current == nullptr)
	{
		tail->next = nodeToAdd;
		tail = nodeToAdd;
	}
	else
	{
		prev->next = nodeToAdd;
		nodeToAdd->next = current;
	}

	return;
}
