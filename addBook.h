/*Program header*/

#ifndef ADDBOOK_H
#define ADDBOOK_H

void addBook (bool &keepInvMenuActive, bool &keepAddBookMenuActive);

//bookType//

//Setters//
bookType::void setTitle(string t)
{title = t;}
bookType::void setIsbn(string i)
{isbn = i;}
bookType::void setAuthor(string a)
{author = a;}
bookType::void setPublisher(string p)
{publisher = p;}
bookType::void setDate(string d)
{date = d;}
bookType::void setQty(unsigned int q)
{qty = q;}
bookType::void setWholesale(unsigned int w)
{wholesale = w;}
bookType::void setRetail(unsigned int r)
{retail = r;}

bookType::string getTitle()
{return title;}
bookType::string getIsbn()
{return isbn;}
bookType::string getAuthor()
{return author;}
bookType::string getPublisher()
{return publisher;}
bookType::string getDate()
{return date;}
bookType::unsigned int getQty()
{return qty;}
bookType::unsigned int getWholesale()
{return wholesale;}
bookType::unsigned int getRetail()
{return retail;}

bookType::bookType(string t = "", string i = "", string a = "", string p = "", string d = "", unsigned int q = 0, unsigned int w = 0, unsigned int r = 0)
{
	cout << "Calling default constructor" << endl;
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
	cout << "Destroying bookType instance" << endl;
}
#endif
