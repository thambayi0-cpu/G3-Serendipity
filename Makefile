run-test: mainmenu.o format.o cashier.o invMenu.o reports.o lookUpBook.o addBook.o editBook.o deleteBook.o repListing.o repWholesale.o repRetail.o repQty.o repCost.o repAge.o bookType.o
	g++ -std=c++20 -Wall -Werror -o run-test mainmenu.o format.o cashier.o invMenu.o reports.o lookUpBook.o addBook.o editBook.o deleteBook.o repListing.o repWholesale.o repRetail.o repQty.o repCost.o repAge.o bookType.o

bookType.o: bookType.cpp
	g++ -std=c++20 -Wall -Werror -c bookType.cpp

mainmenu.o: mainmenu.cpp
	g++ -std=c++20 -Wall -Werror -c mainmenu.cpp

format.o: format.cpp
	g++ -std=c++20 -Wall -Werror -c format.cpp

cashier.o: cashier.cpp
	g++ -std=c++20 -Wall -Werror -c cashier.cpp

invMenu.o: invMenu.cpp
	g++ -std=c++20 -Wall -Werror -c invMenu.cpp

reports.o: reports.cpp
	g++ -std=c++20 -Wall -Werror -c reports.cpp

lookUpBook.o: lookUpBook.cpp
	g++ -std=c++20 -Wall -Werror -c lookUpBook.cpp

addBook.o: addBook.cpp
	g++ -std=c++20 -Wall -Werror -c addBook.cpp

editBook.o: editBook.cpp
	g++ -std=c++20 -Wall -Werror -c editBook.cpp

deleteBook.o: deleteBook.cpp
	g++ -std=c++20 -Wall -Werror -c deleteBook.cpp

repListing.o: repListing.cpp
	g++ -std=c++20 -Wall -Werror -c repListing.cpp

repWholesale.o: repWholesale.cpp
	g++ -std=c++20 -Wall -Werror -c repWholesale.cpp

repRetail.o: repRetail.cpp
	g++ -std=c++20 -Wall -Werror -c repRetail.cpp

repQty.o: repQty.cpp
	g++ -std=c++20 -Wall -Werror -c repQty.cpp

repCost.o: repCost.cpp
	g++ -std=c++20 -Wall -Werror -c repCost.cpp

repAge.o: repAge.cpp
	g++ -std=c++20 -Wall -Werror -c repAge.cpp









clean:
	-rm *.o run-test
