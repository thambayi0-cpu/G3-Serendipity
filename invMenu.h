/*Program header*/

#ifndef INVMENU_H
#define INVMENU_H

#include <string>
#include <vector>

class bookType
{
	private:

		//Private Variables//

		std::string title;
		std::string isbn;
		std::string author;
		std::string publisher;
		std::string date; // mm/dd/yy
		unsigned int qty;
		unsigned int wholesale;
		unsigned int retail;

	public:

		static unsigned int bookCount;

		//Setters//
		void bookAdd();

		void setTitle(std::string t);
		void setIsbn(std::string i);
		void setAuthor(std::string a);
		void setPublisher(std::string p);
		void setDate(std::string d);
		void setQty(unsigned int q);
		void setWholesale(unsigned int w);
		void setRetail(unsigned int r);

		//Accessors//
		unsigned int getBookCount();

		std::string getTitle();
		std::string getIsbn();
		std::string getAuthor();
		std::string getPublisher();
		std::string getDate();
		unsigned int getQty();
		unsigned int getWholesale();
		unsigned int getRetail();

		//Constructors//
		bookType(std::string t = "EMPTY", std::string i = "EMPTY", std::string a = "EMPTY", std::string p = "EMPTY", std::string d = "EMPTY", unsigned int q = 0, unsigned int w = 0, unsigned int r = 0);

		//Destructors//
		~bookType();

};

void invMenu(bool &keepInvMenuActive);

void lookUpBook(bool &keepInvMenuActive, bool &keeplookUpBookMenuActive);

void addBook(bool &keepInvMenuActive, bool &keepAddBookMenuActive, std::vector<bookType>& books);

void editBook(bool &keepInvMenuActive, bool &keepeditBookMenuActive);

void deleteBook(bool &keepInvMenuActive, bool &keepdeleteBookMenuActive);


#endif
