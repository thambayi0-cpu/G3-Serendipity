/***************************************************************************
* PROGRAMMED BY : Ahmer Yasin & Thokozile Hambayi
* ID            : A00349012   & 127485
* CLASS         : CS1B
* SECTION       : TTh 1:30pm
* MODULE        : 2
* GROUP PROJECT : 2
* PROGRAM NAME  : Menus (Navigation & Stubs)
* PURPOSE       : Bookstore POS
* DUE DATE      : 09/23/2025
****************************************************************************/

#include "bookType.h"

using namespace std;

//bookType//

unsigned int bookType::bookCount = 0;

//Setters//

void bookType::bookFill(const bookType& other)
{
	title = other.getTitle();
	isbn = other.getIsbn();
	author = other.getAuthor();
	publisher = other.getPublisher();
	date = other.getDate();
	qty = other.getQty();
	wholesale = other.getWholesale();
	retail = other.getRetail();
}

void bookType::bookEmpty()
{
	title = "EMPTY";
	isbn = "EMPTY";
	author = "EMPTY";
	publisher = "EMPTY";
	date = "EMPTY";
	qty = 0;
	wholesale = 0.0;
	retail = 0.0;
}

void bookType::setTitle(string t)
{title = t;}
void bookType::setIsbn(string i)
{isbn = i;}
void bookType::setAuthor(string a)
{author = a;}
void bookType::setPublisher(string p)
{publisher = p;}
void bookType::setDate(string d)
{date = d;}
void bookType::setQty(unsigned int q)
{
	if (q < 0 || q > 100)
		q = 100;
	qty = q;
}
void bookType::setWholesale(float w)
{
	if (w < 0 || w > 999.99)
		w = 999.99;
	wholesale = w;
}
void bookType::setRetail(float r)
{
	if (r < 0 || r > 999.99)
		r = 999.99;
	retail = r;
}

string bookType::getTitle() const
{return title;}
string bookType::getIsbn() const
{return isbn;}
string bookType::getAuthor() const
{return author;}
string bookType::getPublisher() const
{return publisher;}
string bookType::getDate() const
{return date;}
unsigned int bookType::getQty() const
{return qty;}
float bookType::getWholesale() const
{return wholesale;}
float bookType::getRetail() const
{return retail;}

bookType::bookType(string t, string i, string a, string p, string d, unsigned int q, float w, float r)
{
	//cout << "Calling default constructor" << endl;
	title = t;
	isbn = i;
	author = a;
	publisher = p;
	date = d;
	qty = q;
	wholesale = w;
	retail = r;
}

bookType::~bookType()
{
	//cout << "Destroying bookType instance" << endl;
}
