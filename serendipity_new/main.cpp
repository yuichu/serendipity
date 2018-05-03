// ----------------------------------------------------------------------
// File name: main.cpp, BookData.h, BookData.cpp
// Project name: Serendipity
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 04/23/2018
// Date of Last Modification: 04/25/2018
// ----------------------------------------------------------------------
// Purpose: 
// ----------------------------------------------------------------------
// Algorithm:															-
// Step 1: 
// Step 2: 
// Step 3: 
// Step 4: 
// Step 5: 
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
#include <cstdlib>
#include <limits>
#include <cmath>
#include <ctime>

const float SALES_TAX = 0.06;

// Main Menu Functions
int cashier();
int invMenu();
int reports(orderedLinkedList<InventoryBook> bookList);
// Inventory Menu Functions
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
// Reports Menu Functions
void repListing(orderedLinkedList<InventoryBook> bookList);
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

int main()
{
	char choice = '\0';
	orderedLinkedList<InventoryBook> bookList; //create linked list
	bookList.initializeList(); // initialize list

	// create books
	InventoryBook *book1 = new InventoryBook ("Star Wars", "0345260791", "George Lucas", "Del Rey", "10/18/2017", 5, 59.95, 100.00);
	InventoryBook *book2 = new InventoryBook ("The Empire Strikes Back (Star Wars)", "034529209X", "George Lucas", "Ballantine", "04/01/2017", 2, 179.58, 185.00);
	InventoryBook *book3 = new InventoryBook ("Splinter of the Mind's Eye (Star Wars)", "0345320239", "George Lucas", "Del Rey", "11/08/2017", 3, 24, 26.50);
	InventoryBook *book4 = new InventoryBook ("Return of the Jedi (Star Wars)", "0345307674", "George Lucas", "Del Rey", "10/09/2017", 4, 2.94, 6.50);
	InventoryBook *book5 = new InventoryBook ("Heir to the Empire (Star Wars: The Thrawn Trilogy, Vol. 1)", "0553296124", "Timothy Zahn", "Bantam", "11/01/2017", 10, 25.38, 27.00);

	// insert books into the linked list
	bookList.insert(*book1);
	bookList.insert(*book2);
	bookList.insert(*book3);
	bookList.insert(*book4);
	bookList.insert(*book5);

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
			invMenu();
			break;
		case '3':
			reports(bookList);
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
int invMenu()
{
	cout << "Inventory Menu WIP." << "\n\n";
	system("pause");
	return 0;
}

//----------------------------------------------------------------------
// Function: reports()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
int reports(orderedLinkedList<InventoryBook> bookList)
{
	char choice = '\0';

	do
	{
		system("cls");

		// Display Reports Menu
		cout << setw(60) << "Serendipity Booksellers\n"
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
			repListing(bookList);
			break;
		case '2':
			repWholesale();
			break;
		case '3':
			repRetail();
			break;
		case '4':
			repQty();
			break;
		case '5':
			repCost();
			break;
		case '6':
			repAge();
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
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repListing(orderedLinkedList<InventoryBook> bookList)
{
	// page setting
	int currentPage = 1;
//	double totalPage = ceil(double(bookCount)/10);
	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);
	// iterator
	linkedListIterator<InventoryBook> myIterator;

	system("cls");

	cout << setw(60) << "SERENDIPITY BOOKSELLERS" << "\n";
	cout << setw(55) << "REPORT LISTING" << "\n";
	cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
			<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
			<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
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

	for (myIterator = bookList.begin(); myIterator != bookList.end(); ++myIterator)
	{
		cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
				<< setw(1) << ' '
				<< setw(10) << (*myIterator).getIsbn()
				<< setw(1) << ' '
				<< right << setw(7) << (*myIterator).getQty()
				<< setw(1) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getWholesale() << setfill(' ') << setprecision(0)
				<< setw(1) << ' '
				<< left << setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << (*myIterator).getRetail() << setfill(' ') << setprecision(0);
		cout << "\n\n";
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
void repWholesale()
{
	cout << "Reports Wholesale Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repRetail()
{
	cout << "Reports Retail Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repQty()
{
	cout << "Reports Quantity Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repCost()
{
	cout << "Reports Cost Menu WIP." << "\n\n";
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void repAge()
{
	cout << "Reports Age Menu WIP." << "\n\n";
	system("pause");
	return;
}
