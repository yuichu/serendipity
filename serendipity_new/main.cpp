// ----------------------------------------------------------------------
// File name: main.cpp, BookData.h, InventoryBook.h, SoldBook.h,		-
//				linkedList.h, orderedLinkedList.h						-
// Project name: Serendipity											-
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 04/23/2018											-
// Date of Last Modification: 05/03/2018								-
// ----------------------------------------------------------------------
// Purpose: Serendipity Bookstore's POS system which allows user to add,-
//			modify, and delete a library of books						-
// ----------------------------------------------------------------------
// -							DATA DICTIONARY							-
// - CONSTANTS															-
// -																	-
// - NAME					DATA TYPE				VALUE				-
// - --------------------   ----------				--------			-
// - BookData				class
// - InventoryBook			class
// - SoldBook				class
// -																	-
// - VARIABLES															-
// -																	-
// - NAME					DATA TYPE				INITIAL VALUE		-
// - --------------------   ----------				-------------		-
// - choice					char					null
// - bookList				InventoryBook
// - *book1					InventoryBook
// - *book2					InventoryBook
// - *book3					InventoryBook
// - *book4					InventoryBook
// - *book5					InventoryBook
// ----------------------------------------------------------------------

#include "BookData.h"
#include "InventoryBook.h"
#include "SoldBook.h"
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <limits>
#include <cmath>
#include <ctime>

const float SALES_TAX = 0.06;

// Main Menu Functions
int cashier();
int invMenu(orderedLinkedList<InventoryBook> titleList, orderedLinkedList<InventoryBook> qtyList, orderedLinkedList<InventoryBook> wholesaleList, orderedLinkedList<InventoryBook> dateList);
int reports(orderedLinkedList<InventoryBook> titleList, orderedLinkedList<InventoryBook> qtyList, orderedLinkedList<InventoryBook> wholesaleList, orderedLinkedList<InventoryBook> dateList);
// Inventory Menu Functions
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
// Reports Menu Functions
void repListing(orderedLinkedList<InventoryBook> titleList);
void repWholesale(orderedLinkedList<InventoryBook> titleList);
void repRetail(orderedLinkedList<InventoryBook> titleList);
void repQty(orderedLinkedList<InventoryBook> qtyList);
void repCost(orderedLinkedList<InventoryBook> wholesaleList);
void repAge(orderedLinkedList<InventoryBook> dateList);

int main()
{
	char choice = '\0';
	orderedLinkedList<InventoryBook> titleList;
	orderedLinkedList<InventoryBook> qtyList;
	orderedLinkedList<InventoryBook> wholesaleList;
	orderedLinkedList<InventoryBook> dateList;
	// initialize lists
	titleList.initializeList();
	qtyList.initializeList();
	wholesaleList.initializeList();
	dateList.initializeList();

	// create books
	InventoryBook *book1 = new InventoryBook ("Star Wars", "0345260791", "George Lucas", "Del Rey", "10/18/2017", 5, 59.95, 100.00, 0);
	InventoryBook *book2 = new InventoryBook ("The Empire Strikes Back (Star Wars)", "034529209X", "George Lucas", "Ballantine", "04/01/2017", 2, 179.58, 185.00, 0);
	InventoryBook *book3 = new InventoryBook ("Splinter of the Mind's Eye (Star Wars)", "0345320239", "George Lucas", "Del Rey", "11/08/2017", 3, 24, 26.50, 0);
	InventoryBook *book4 = new InventoryBook ("Return of the Jedi (Star Wars)", "0345307674", "George Lucas", "Del Rey", "10/09/2017", 4, 2.94, 6.50, 0);
	InventoryBook *book5 = new InventoryBook ("Heir to the Empire (Star Wars: The Thrawn Trilogy, Vol. 1)", "0553296124", "Timothy Zahn", "Bantam", "11/01/2017", 10, 25.38, 27.00, 0);
	InventoryBook *book6 = new InventoryBook("Dark Force Rising (Star Wars: The Thrawn Trilogy, Vol. 2", "0553560719", "Timothy Zahn", "Bantam", "11/08/2017", 10, 25.38, 27.00, 0);
	InventoryBook *book7 = new InventoryBook("The Last Command (Star Wars: The Thrawn Trilogy)", "0553564927", "Timothy Zahn", "Bantam", "11/02/2017", 10, 14.30, 17, 0);
	InventoryBook *book8 = new InventoryBook("Specter of the Past (Star Wars: The Hand of Thrawn #1)", "0553298046", "Timothy Zahn", "Bantam", "11/08/2017", 5, 13.66, 15, 0);
	InventoryBook *book9 = new InventoryBook("Vision of the Future (Star Wars: The Hand of Thrawn, Book 2)", "0553578790", "Timothy Zahn", "Bantam", "11/06/2017", 5, 10.85, 15, 0);
	InventoryBook *book10 = new InventoryBook("Battlestar Galactica", "185286088X", "Glen A.;Thurston, Robert Larson", "Titan Books", "11/08/2015", 5, 102.04, 150.00, 0);
	InventoryBook *book11 = new InventoryBook("New Battlestar Galactica Volume 1 (Battlestar Galactica (Dynamite)) (v. 1)", "1933305339", "Diamond Comic Distributors Inc.", "Dynamite Entertainment", "11/08/2017", 5, 29.95, 35.00, 0);
	InventoryBook *book12 = new InventoryBook("New Battlestar Galactica Volume II Hardcover (Battlestar Galactica (Dynamite))", "1933305533", "Greg Pak", "Dynamite Entertainment", "11/03/2017", 5, 34.95, 37.00, 0);
	InventoryBook *book13 = new InventoryBook("The Hobbit", "0618968636", "J.R.R. Tolkien", "Houghton Mifflin Harcourt", "11/10/2017", 1, 17.61, 20.00, 0);
	InventoryBook *book14 = new InventoryBook("The Lord of the Rings: 50th Anniversary, One Vol. Edition", "0618645616", "J.R.R. Tolkien", "Houghton Mifflin Harcourt", "11/10/2016", 4, 29.89, 32.00, 0);
	InventoryBook *book15 = new InventoryBook("The Two Towers", "0395489334", "J.R.R. Tolkien", "Houghton Mifflin Harcourt", "11/10/2017", 4, 17.89, 19.00, 0);
	InventoryBook *book16 = new InventoryBook("The Return of the King", "039548930X", "J.R.R. Tolkien", "Houghton Mifflin Harcourt", "11/10/2017", 6, 16.89, 19.00, 0);
	InventoryBook *book17 = new InventoryBook("The Fellowship of the Ring", "0395489318", "J.R.R. Tolkien", "Houghton Mifflin Harcourt", "11/10/2017", 7, 18.70, 20.00, 0);
	InventoryBook *book18 = new InventoryBook("C++ Programming: From Problem Analysis to Program Design 7th Edition", "1285852745", "D.S. Malik", "Course Technology", "11/16/2015", 3, 85.67, 100.00, 0);
	InventoryBook *book19 = new InventoryBook("Digital Computer Electronics", "0074622358", "Malvino", "Mc Graw Hill India", "11/16/2017", 10, 44.56, 50.00, 0);
	InventoryBook *book20 = new InventoryBook("Assembly Language for x86 Processors (7th Edition)", "0133769402", "Irvin, K.R.", "Pearson", "11/16/2017", 10, 178.22, 200, 0);

	// insert books into the title list
	(*book1).setSortCode(0);
	titleList.insert(*book1);
	(*book2).setSortCode(0);
	titleList.insert(*book2);
	(*book3).setSortCode(0);
	titleList.insert(*book3);
	(*book4).setSortCode(0);
	titleList.insert(*book4);
	(*book5).setSortCode(0);
	titleList.insert(*book5);
	(*book6).setSortCode(0);
	titleList.insert(*book6);
	(*book7).setSortCode(0);
	titleList.insert(*book7);
	(*book8).setSortCode(0);
	titleList.insert(*book8);
	(*book9).setSortCode(0);
	titleList.insert(*book9);
	(*book10).setSortCode(0);
	titleList.insert(*book10);
	(*book11).setSortCode(0);
	titleList.insert(*book11);
	(*book12).setSortCode(0);
	titleList.insert(*book12);
	(*book13).setSortCode(0);
	titleList.insert(*book13);
	(*book14).setSortCode(0);
	titleList.insert(*book14);
	(*book15).setSortCode(0);
	titleList.insert(*book15);
	(*book16).setSortCode(0);
	titleList.insert(*book16);
	(*book17).setSortCode(0);
	titleList.insert(*book17);
	(*book18).setSortCode(0);
	titleList.insert(*book18);
	(*book19).setSortCode(0);
	titleList.insert(*book19);
	(*book20).setSortCode(0);
	titleList.insert(*book20);
	// insert books into qty list
	(*book1).setSortCode(1);
	qtyList.insert(*book1);
	(*book2).setSortCode(1);
	qtyList.insert(*book2);
	(*book3).setSortCode(1);
	qtyList.insert(*book3);
	(*book4).setSortCode(1);
	qtyList.insert(*book4);
	(*book5).setSortCode(1);
	qtyList.insert(*book5);
	(*book6).setSortCode(1);
	qtyList.insert(*book6);
	(*book7).setSortCode(1);
	qtyList.insert(*book7);
	(*book8).setSortCode(1);
	qtyList.insert(*book8);
	(*book9).setSortCode(1);
	qtyList.insert(*book9);
	(*book10).setSortCode(1);
	qtyList.insert(*book10);
	(*book11).setSortCode(1);
	qtyList.insert(*book11);
	(*book12).setSortCode(1);
	qtyList.insert(*book12);
	(*book13).setSortCode(1);
	qtyList.insert(*book13);
	(*book14).setSortCode(1);
	qtyList.insert(*book14);
	(*book15).setSortCode(1);
	qtyList.insert(*book15);
	(*book16).setSortCode(1);
	qtyList.insert(*book16);
	(*book17).setSortCode(1);
	qtyList.insert(*book17);
	(*book18).setSortCode(1);
	qtyList.insert(*book18);
	(*book19).setSortCode(1);
	qtyList.insert(*book19);
	(*book20).setSortCode(1);
	qtyList.insert(*book20);
	// insert books into wholesale list
	(*book1).setSortCode(2);
	wholesaleList.insert(*book1);
	(*book2).setSortCode(2);
	wholesaleList.insert(*book2);
	(*book3).setSortCode(2);
	wholesaleList.insert(*book3);
	(*book4).setSortCode(2);
	wholesaleList.insert(*book4);
	(*book5).setSortCode(2);
	wholesaleList.insert(*book5);
	(*book6).setSortCode(2);
	wholesaleList.insert(*book6);
	(*book7).setSortCode(2);
	wholesaleList.insert(*book7);
	(*book8).setSortCode(2);
	wholesaleList.insert(*book8);
	(*book9).setSortCode(2);
	wholesaleList.insert(*book9);
	(*book10).setSortCode(2);
	wholesaleList.insert(*book10);
	(*book11).setSortCode(2);
	wholesaleList.insert(*book11);
	(*book12).setSortCode(2);
	wholesaleList.insert(*book12);
	(*book13).setSortCode(2);
	wholesaleList.insert(*book13);
	(*book14).setSortCode(2);
	wholesaleList.insert(*book14);
	(*book15).setSortCode(2);
	wholesaleList.insert(*book15);
	(*book16).setSortCode(2);
	wholesaleList.insert(*book16);
	(*book17).setSortCode(2);
	wholesaleList.insert(*book17);
	(*book18).setSortCode(2);
	wholesaleList.insert(*book18);
	(*book19).setSortCode(2);
	wholesaleList.insert(*book19);
	(*book20).setSortCode(2);
	wholesaleList.insert(*book20);
	// insert books into date list
	(*book1).setSortCode(3);
	dateList.insert(*book1);
	(*book2).setSortCode(3);
	dateList.insert(*book2);
	(*book3).setSortCode(3);
	dateList.insert(*book3);
	(*book4).setSortCode(3);
	dateList.insert(*book4);
	(*book5).setSortCode(3);
	dateList.insert(*book5);
	(*book6).setSortCode(3);
	dateList.insert(*book6);
	(*book7).setSortCode(3);
	dateList.insert(*book7);
	(*book8).setSortCode(3);
	dateList.insert(*book8);
	(*book9).setSortCode(3);
	dateList.insert(*book9);
	(*book10).setSortCode(3);
	dateList.insert(*book10);
	(*book11).setSortCode(3);
	dateList.insert(*book11);
	(*book12).setSortCode(3);
	dateList.insert(*book12);
	(*book13).setSortCode(3);
	dateList.insert(*book13);
	(*book14).setSortCode(3);
	dateList.insert(*book14);
	(*book15).setSortCode(3);
	dateList.insert(*book15);
	(*book16).setSortCode(3);
	dateList.insert(*book16);
	(*book17).setSortCode(3);
	dateList.insert(*book17);
	(*book18).setSortCode(3);
	dateList.insert(*book18);
	(*book19).setSortCode(3);
	dateList.insert(*book19);
	(*book20).setSortCode(3);
	dateList.insert(*book20);

	do
	{
		system("cls");

		// Display Menu
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(44) << "MAIN MENU" << setw(34) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << left << fixed;
		cout << setw(2) << '*' << setw(6) << "<1>" << setw(70) << "Cashier Menu" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<2>" << setw(70) << "Inventory Database Menu" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<3>" << setw(70) << "Report Menu" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<4>" << setw(70) << "Exit" << '*' << '\n';
		cout << right;
		cout << '*' << setw(78) << '*' << '\n';
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

		// Get User Choice
		cout << setw(23) <<  "Enter Your Choice: ";
		cin >> choice;
		if(cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = '0';
		}	// end input fail

		// Navigate Choice Function
		switch(choice)
		{
		case '1':
			cashier();
			break;
		case '2':
			invMenu(titleList, qtyList, wholesaleList, dateList);
			break;
		case '3':
			reports(titleList, qtyList, wholesaleList, dateList);
			break;
		case '4':
			break;
		default:
			cout << "Please enter a number in the range 1 - 4.\n\n";
			system("pause");
		}	// end switch

	} while(choice != '4');	// end do-while Main Menu

	return 0;
}
//													MAIN MENU FUNCTIONS
//----------------------------------------------------------------------
// Function: cashier()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
int cashier()
{
	cout << "Cashier Menu WIP." << "\n\n";
	system("pause");
	return 0;
}

//----------------------------------------------------------------------
// Function: invMenu()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
int invMenu(orderedLinkedList<InventoryBook> titleList, orderedLinkedList<InventoryBook> qtyList, orderedLinkedList<InventoryBook> wholesaleList, orderedLinkedList<InventoryBook> dateList)
{
	char choice = '\0';

	do
	{
		system("cls");

		// Display Menu
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(45) << "INVENTORY MENU" << setw(33) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << left << fixed;
		cout << setw(2) << '*' << setw(6) << "<1>" << setw(70) << "Look Up a Book" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<2>" << setw(70) << "Add a Book" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<3>" << setw(70) << "Edit a Book's Record" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<4>" << setw(70) << "Delete a Book" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<5>" << setw(70) << "Return to the Main Menu" << '*' << '\n';
		cout << right;
		cout << '*' << setw(78) << '*' << '\n';
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

		// Get user choice for menu
		cout << setw(23) <<  "Enter Your Choice: ";
		cin >> choice;

		if(cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = '0';
		}

		switch(choice)
		{
		case '1':
			lookUpBook();
			break;
		case '2':
			addBook();
			break;
		case '3':
			editBook();
			break;
		case '4':
			deleteBook();
			break;
		case '5':
			break;
		default:
			cout << "Please enter a number in the range 1 - 5.\n\n";
			system("pause");
		}

	} while (choice != '5');

	return 0;
}

//----------------------------------------------------------------------
// Function: reports()
// Navigate through Reports Menu
// Receives: orderedLinkedList<InventoryBook> bookList
// Returns: 0
//----------------------------------------------------------------------
int reports(orderedLinkedList<InventoryBook> titleList, orderedLinkedList<InventoryBook> qtyList, orderedLinkedList<InventoryBook> wholesaleList, orderedLinkedList<InventoryBook> dateList)
{
	char choice = '\0';

	do
	{
		system("cls");

		// Display Reports Menu
		cout << right << setw(60) << "Serendipity Booksellers\n"
				<< setw(53) << "Reports\n\n";
		cout << setw(56) << "1.  Inventory Listing\n"
				<< setw(64) << "2.  Inventory Wholesale Value\n"
				<< setw(61) << "3.  Inventory Retail Value\n"
				<< setw(58) << "4.  Listing by Quantity\n"
				<< setw(54) << "5.  Listing by Cost\n"
				<< setw(53) << "6.  Listing by Age\n"
				<< setw(63) << "7.  Return to the Main Menu\n\n";

		// Get User Choice
		cout << setw(54) <<  "Enter Your Choice: ";
		cin >> choice;
		if(cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = '0';
		}	// end input fail

		// Navigate Choice Function
		switch(choice)
		{
		case '1':
			repListing(titleList);
			break;
		case '2':
			repWholesale(titleList);
			break;
		case '3':
			repRetail(titleList);
			break;
		case '4':
			repQty(qtyList);
			break;
		case '5':
			repCost(wholesaleList);
			break;
		case '6':
			repAge(dateList);
			break;
		case '7':
			break;
		default:
			cout << setw(78) << "Please enter a number in the range 1 - 7.\n\n";
			system("pause");
		}	// end switch

	} while(choice != '7');	// end do-while reports menu

	return 0;
}

//													INV MENU FUNCTIONS
//----------------------------------------------------------------------
// Function: lookUpBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void lookUpBook()
{
	cout << "Look Up Book Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: addBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void addBook()
{
	cout << "Add Book Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: editBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void editBook()
{
	cout << "Edit Book Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: deleteBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void deleteBook()
{
	cout << "Delete Book Menu WIP." << "\n\n";
	system("pause");
	return;
}

//												REPORTS MENU FUNCTIONS
//----------------------------------------------------------------------
// Function: repListing()
// Display Inventory
// Receives: orderedLinkedList<InventoryBook> bookList
// Returns: none
//----------------------------------------------------------------------
void repListing(orderedLinkedList<InventoryBook> titleList)
{
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	system("cls");

	// Display Title
	cout << setw(60) << "SERENDIPITY BOOKSELLERS" << "\n";
	cout << setw(55) << "REPORT LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
			<< " " << setfill('0') << setw(2) << now->tm_hour
			<< setw(1) << ':' << setw(2) << now->tm_min << setw(1)
			<< ':' << setw(2) << now->tm_sec << setfill(' ')
			<< "     PAGE: " << currentPage << " of " << "NAN"
			<< "     DATABASE SIZE: " << "NAN"
			<< "     CURRENT BOOK COUNT: " << "NAN"
			<< "\n\n";

	cout << left << setw(37) << "TITLE"
			<< setw(1) << ' '
			<< setw(10) << "ISBN"
			<< setw(1) << ' '
			<< setw(7) << "QTY O/H"
			<< setw(1) << ' '
			<< setw(14) << "WHOLESALE COST"
			<< setw(1) << ' '
			<< setw(14) << "RETAIL COST"
			<< '\n';

	cout << setfill('-') << setw(37) << '-'
			<< setfill(' ') << setw(1) << ' '
			<< setfill('-') << setw(10) << '-'
			<< setfill(' ') << setw(1) << ' '
			<< setfill('-') << setw(7) << '-'
			<< setfill(' ') << setw(1) << ' '
			<< setfill('-') << setw(14) << '-'
			<< setfill(' ') << setw(1) << ' '
			<< setfill('-') << setw(14) << '-'
			<< setfill(' ') << '\n';

	// Iterate and display books
	for (myIterator = titleList.begin(); myIterator != titleList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(1) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(1) << ' '
				<< right << setw(7) << (*myIterator).getQty()
				<< setw(1) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getWholesale() << setfill(' ') << setprecision(0)
				<< setw(1) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getRetail() << setfill(' ') << setprecision(0) << right;
		cout << "\n\n";
	}	// end iterator loop

	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: repWholesale()
// Display inventory with wholesale price
// Receives: orderedLinkedList<InventoryBook> bookList
// Returns:
//----------------------------------------------------------------------
void repWholesale(orderedLinkedList<InventoryBook> titleList)
{
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	double subtotal = 0.00;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	system("cls");

	// display wholesale listing title
	cout << fixed << right;
	cout << setw(50) << "SERENDIPITY  BOOKSELLERS" << "\n";
	cout << setw(50) << "REPORT WHOLESALE LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
			<< " " << setfill('0') << setw(2) << now->tm_hour
			<< setw(1) << ':' << setw(2) << now->tm_min << setw(1)
			<< ':' << setw(2) << now->tm_sec << setfill(' ')
			<< "     PAGE: " << currentPage << " of " << "NAN"
			<< "     DATABASE SIZE: " << "NAN"
			<< "     CURRENT BOOK COUNT: " << "NAN"
			<< "\n\n";

	cout << left << setw(37) << "TITLE"
			<< setw(5) << ' '
			<< setw(10) << "ISBN"
			<< setw(5) << ' '
			<< setw(7) << "QTY O/H"
			<< setw(5) << ' '
			<< setw(14) << "WHOLESALE COST"
			<< '\n';

	cout << setfill('-') << setw(37) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(10) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(7) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(14) << '-'
			<< setfill(' ') << '\n';


	// iterate and display books
	for (myIterator = titleList.begin(); myIterator != titleList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(5) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(5) << ' '
				<< right << setw(7) << (*myIterator).getQty()
				<< setw(5) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getWholesale() << setfill(' ') << setprecision(0);
		cout << "\n\n";

		subtotal += ((*myIterator).getWholesale() * (*myIterator).getQty());	// calculate wholesale total
	}	// end iterator loop

	// total wholesale value
	cout << left << setw(69) << "Total Wholesale Value: "
			<< setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << subtotal << setfill(' ') << setprecision(0)
			<< "\n\n";

	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: repRetail()
//
// Receives: orderedLinkedList<InventoryBook> bookList
// Returns:
//----------------------------------------------------------------------
void repRetail(orderedLinkedList<InventoryBook> titleList)
{
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	double subtotal = 0.00;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	system("cls");

	// display wholesale listing title
	cout << fixed << right;
	cout << setw(54) << "SERENDIPITY  BOOKSELLERS" << "\n";
	cout << setw(52) << "REPORT RETAIL LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
			<< " " << setfill('0') << setw(2) << now->tm_hour
			<< setw(1) << ':' << setw(2) << now->tm_min << setw(1)
			<< ':' << setw(2) << now->tm_sec << setfill(' ')
			<< "     PAGE: " << currentPage << " of " << "NAN"
			<< "     DATABASE SIZE: " << "NAN"
			<< "     CURRENT BOOK COUNT: " << "NAN"
			<< "\n\n";

	cout << left << setw(37) << "TITLE"
			<< setw(5) << ' '
			<< setw(10) << "ISBN"
			<< setw(5) << ' '
			<< setw(7) << "QTY O/H"
			<< setw(5) << ' '
			<< setw(14) << "RETAIL COST"
			<< '\n';

	cout << setfill('-') << setw(37) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(10) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(7) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(14) << '-'
			<< setfill(' ') << '\n';


	// iterate and display books
	for (myIterator = titleList.begin(); myIterator != titleList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(5) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(5) << ' '
				<< right << setw(7) << (*myIterator).getQty()
				<< setw(5) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getRetail() << setfill(' ') << setprecision(0);
		cout << "\n\n";

		subtotal += ((*myIterator).getRetail() * (*myIterator).getQty());	// calculate wholesale total
	}	// end iterator loop

	// total retail value
	cout << left << setw(69) << "Total Retail Value: "
			<< setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << subtotal << setfill(' ') << setprecision(0)
			<< "\n\n";

	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: repQty()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repQty(orderedLinkedList<InventoryBook> qtyList)
{
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	system("cls");

	cout << fixed << right;

	cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
	cout << setw(33) << "REPORT QUANTITY LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
			<< " " << setfill('0') << setw(2) << now->tm_hour
			<< setw(1) << ':' << setw(2) << now->tm_min << setw(1)
			<< ':' << setw(2) << now->tm_sec << setfill(' ')
			<< "     PAGE: " << currentPage << " of " << "NAN"
			<< "     DATABASE SIZE: " << "NAN"
			<< "     CURRENT BOOK COUNT: " << "NAN"
			<< "\n\n";

	cout << left << setw(37) << "TITLE"
			<< setw(5) << ' '
			<< setw(10) << "ISBN"
			<< setw(5) << ' '
			<< setw(7) << "QTY O/H"
			<< '\n';

	cout << setfill('-') << setw(37) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(10) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(7) << '-'
			<< setfill(' ') << '\n';

	// iterate and display books
	for (myIterator = qtyList.begin(); myIterator != qtyList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(5) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(5) << ' '
				<< right << setw(7) << (*myIterator).getQty();
		cout << "\n\n";
	}	// end iterator loop

	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: repCost()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repCost(orderedLinkedList<InventoryBook> wholesaleList)
{
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	double subtotal = 0.00;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	system("cls");

	cout << fixed << right;

	cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
	cout << setw(33) << "REPORT COST LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
			<< " " << setfill('0') << setw(2) << now->tm_hour
			<< setw(1) << ':' << setw(2) << now->tm_min << setw(1)
			<< ':' << setw(2) << now->tm_sec << setfill(' ')
			<< "     PAGE: " << currentPage << " of " << "NAN"
			<< "     DATABASE SIZE: " << "NAN"
			<< "     CURRENT BOOK COUNT: " << "NAN"
			<< "\n\n";

	cout << left << setw(37) << "TITLE"
			<< setw(5) << ' '
			<< setw(10) << "ISBN"
			<< setw(5) << ' '
			<< setw(7) << "QTY O/H"
			<< setw(5) << ' '
			<< setw(14) << "WHOLESALE COST"
			<< '\n';

	cout << setfill('-') << setw(37) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(10) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(7) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(14) << '-'
			<< setfill(' ') << '\n';

	// iterate and display books
	for (myIterator = wholesaleList.begin(); myIterator != wholesaleList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(5) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(5) << ' '
				<< right << setw(7) << (*myIterator).getQty()
				<< setw(5) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getWholesale() << setfill(' ') << setprecision(0);
		cout << "\n\n";

		subtotal += ((*myIterator).getRetail() * (*myIterator).getQty());	// calculate wholesale total
	}	// end iterator loop

	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repAge(orderedLinkedList<InventoryBook> dateList)
{
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	system("cls");

	cout << fixed << right;

	cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
	cout << setw(33) << "ADDED DATE LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
			<< " " << setfill('0') << setw(2) << now->tm_hour
			<< setw(1) << ':' << setw(2) << now->tm_min << setw(1)
			<< ':' << setw(2) << now->tm_sec << setfill(' ')
			<< "     PAGE: " << currentPage << " of " << "NAN"
			<< "     DATABASE SIZE: " << "NAN"
			<< "     CURRENT BOOK COUNT: " << "NAN"
			<< "\n\n";

	cout << left << setw(37) << "TITLE"
			<< setw(5) << ' '
			<< setw(10) << "ISBN"
			<< setw(5) << ' '
			<< setw(7) << "QTY O/H"
			<< setw(5) << ' '
			<< setw(14) << "DATE ADDED"
			<< '\n';

	cout << setfill('-') << setw(37) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(10) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(7) << '-'
			<< setfill(' ') << setw(5) << ' '
			<< setfill('-') << setw(14) << '-'
			<< setfill(' ') << '\n';

	// iterate and display books
	for (myIterator = dateList.begin(); myIterator != dateList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(5) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(5) << ' '
				<< right << setw(7) << (*myIterator).getQty()
				<< setw(5) << ' '
				<< setw(10) << (*myIterator).getDateAdded();
		cout << "\n\n";
	}	// end iterator loop

	system("pause");
	return;
}
