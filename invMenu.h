/*Program header*/

#ifndef INVMENU_H
#define INVMENU_H

void invMenu(bool &keepInvMenuActive);

void lookUpBook(bool &keepInvMenuActive, bool &keeplookUpBookMenuActive);

void addBook(bool &keepInvMenuActive, bool &keepAddBookMenuActive);

void editBook(bool &keepInvMenuActive, bool &keepeditBookMenuActive);

void deleteBook(bool &keepInvMenuActive, bool &keepdeleteBookMenuActive);

class bookType
{
	private:

		//Private Variables//
		string title;
		string isbn;
		string author;
		string publisher;
		string date; // mm/dd/yy
		unsigned int qty;
		unsigned int wholesale;
		unsigned int retail;

	public:

		//Setters//
		void setTitle(string t);
		void setIsbn(string i);
		void setAuthor(string a);
		void setPublisher(string p);
		void setDate(string d);
		void setQty(unsigned int q);
		void setWholesale(unsigned int w);
		void setRetail(unsigned int r);

		//Accessors//
		string getTitle();
		string getIsbn();
		string getAuthor();
		string getPublisher();
		string getDate();
		unsigned int getQty();
		unsigned int getWholesale();
		unsigned int getRetail();

		//Constructors//
		bookType(string n, string i, string a, string p, string d, unsigned int q, unsigned int w, unsigned int r);

		//Destructors//
		~bookType();

};

#endif
