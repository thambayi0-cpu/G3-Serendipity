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

#endif
