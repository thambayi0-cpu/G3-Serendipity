/*Program header*/

#ifndef BOOKTYPE_H
#define BOOKTYPE_H

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
		float wholesale;
		float retail;

	public:

		static unsigned int bookCount;

		//Setters//

		void bookFill(const bookType& other); //Copies the contents of one book to another
		void bookEmpty(); //Resets the variables of a book to default values

		void setTitle(std::string t);
		void setIsbn(std::string i);
		void setAuthor(std::string a);
		void setPublisher(std::string p);
		void setDate(std::string d);
		void setQty(unsigned int q);
		void setWholesale(float w);
		void setRetail(float r);

		//Accessors//

		std::string getTitle() const;
		std::string getIsbn() const;
		std::string getAuthor() const;
		std::string getPublisher() const;
		std::string getDate() const;
		unsigned int getQty() const;
		float getWholesale() const;
		float getRetail() const;

		//Constructors//
		bookType(std::string t = "EMPTY", std::string i = "EMPTY", std::string a = "EMPTY", std::string p = "EMPTY", std::string d = "EMPTY", unsigned int q = 0, float w = 0.0, float r = 0.0);

		//Destructors//
		~bookType();

};

#endif
