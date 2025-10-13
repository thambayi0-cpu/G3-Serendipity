run-test: mainmenu.o format.o cashier.o invMenu.o reports.o lookUpBook.o addBook.o editBook.o deleteBook.o repListing.o repWholesale.o repRetail.o repQty.o repCost.o repAge.o
	g++ -std=c++20 -Wall -Werror -o run-test mainmenu.o format.o cashier.o invMenu.o reports.o lookUpBook.o addBook.o editBook.o deleteBook.o repListing.o repWholesale.o repRetail.o repQty.o repCost.o repAge.o

mainmenu.o: mainmenu.cpp format.h
	g++ -std=c++20 -Wall -Werror -c mainmenu.cpp

format.o: format.cpp format.h
	g++ -std=c++20 -Wall -Werror -c format.cpp

cashier.o: cashier.cpp cashier.h
	g++ -std=c++20 -Wall -Werror -c cashier.cpp

invMenu.o: invMenu.cpp invMenu.h
	g++ -std=c++20 -Wall -Werror -c invMenu.cpp

reports.o: reports.cpp reports.h
	g++ -std=c++20 -Wall -Werror -c reports.cpp

lookUpBook.o: lookUpBook.cpp lookUpBook.h
	g++ -std=c++20 -Wall -Werror -c lookUpBook.cpp

addBook.o: addBook.cpp invMenu.h
	g++ -std=c++20 -Wall -Werror -c addBook.cpp

editBook.o: editBook.cpp editBook.h
	g++ -std=c++20 -Wall -Werror -c editBook.cpp

deleteBook.o: deleteBook.cpp deleteBook.h
	g++ -std=c++20 -Wall -Werror -c deleteBook.cpp

repListing.o: repListing.cpp repListing.h
	g++ -std=c++20 -Wall -Werror -c repListing.cpp

repWholesale.o: repWholesale.cpp repWholesale.h
	g++ -std=c++20 -Wall -Werror -c repWholesale.cpp

repRetail.o: repRetail.cpp repRetail.h
	g++ -std=c++20 -Wall -Werror -c repRetail.cpp

repQty.o: repQty.cpp repQty.h
	g++ -std=c++20 -Wall -Werror -c repQty.cpp

repCost.o: repCost.cpp repCost.h
	g++ -std=c++20 -Wall -Werror -c repCost.cpp

repAge.o: repAge.cpp repAge.h
	g++ -std=c++20 -Wall -Werror -c repAge.cpp









clean:
	-rm *.o run-test
