#ifndef BOOKNODE_H
#define BOOKNODE_H

#include "bookType.h"

struct bookNode
{
	bookType* book;
	bookNode* next;

	bookNode(bookNode* n = nullptr) : next(n)//Node constructor. They do exist!
	{}
};

void deleteNode(bookNode*& head, bookNode*& tail, bookType*& nodeToDelete);

void destroyList(bookNode*& head, bookNode*& tail);

void insertOrdered(bookNode*& head, bookNode*& tail, bookNode*& nodeToAdd);

#endif
