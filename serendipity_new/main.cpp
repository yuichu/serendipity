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
int invMenu(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList);
int reports(orderedLinkedList<InventoryBook> titleList, orderedLinkedList<InventoryBook> qtyList, orderedLinkedList<InventoryBook> wholesaleList, orderedLinkedList<InventoryBook> dateList);
// Inventory Menu Functions
void lookUpBook(orderedLinkedList<InventoryBook> titleList);
void addBook(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList);
void editBook(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList);
void deleteBook(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList);
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
int invMenu(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList)
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
			lookUpBook(titleList);
			break;
		case '2':
			addBook(titleList, qtyList, wholesaleList, dateList);
			break;
		case '3':
			editBook(titleList, qtyList, wholesaleList, dateList);
			break;
		case '4':
			deleteBook(titleList, qtyList, wholesaleList, dateList);
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
// Search book and display book info
// Receives: orderedLinkedList<InventoryBook> titleList
// Returns: none
//----------------------------------------------------------------------
void lookUpBook(orderedLinkedList<InventoryBook> titleList)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundTitle;
	size_t foundIsbn;
	linkedListIterator<InventoryBook> myIterator;	// iterator

	cout << setw(24) << ">>> BOOK LOOK UP <<<" << '\n';

	// get user book term
	cout << setw(13) << "Search: > ";
	getline(cin, userSearch);

	// change search term to ignore case
	for (unsigned int i = 0; i < userSearch.length(); i++)
	{
		if (isupper(userSearch[i]))
		{
			userSearch[i] = tolower(userSearch[i]);
		}
	}

	myIterator = titleList.begin();
	do
	{
		// change target title to ignore case
		target = (*myIterator).getTitle();
		for (unsigned int i = 0; i < target.length(); i++)
		{
			if (isupper(target[i]))
			{
				target[i] = tolower(target[i]);
			}
		}

		// find title from partial search term
		foundTitle = target.find(userSearch);
		if (foundTitle != string::npos)
		{
			cout << "RESULT: > " << (*myIterator).getTitle() << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				cout << '\n';
				(*myIterator).print();
				cout << '\n';
				system("pause");
				break;
			}
		}

		// find ISBN from partial search term
		foundIsbn = ((*myIterator).getIsbn()).find(userSearch);
		if (foundIsbn != string::npos)
		{
			cout << "RESULT: > " << (*myIterator).getIsbn() << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				cout << '\n';
				(*myIterator).print();
				cout << '\n';
				system("pause");
				break;
			}
		}

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

		cout << '\n' << setw(24) << ">>> BOOK LOOK UP <<<" << "\n\n";
		++myIterator;
	} while (myIterator != titleList.end());	// end do-while

	// If user exhausts all book options or no matching title is found
	if(myIterator == titleList.end() || (foundTitle == string::npos && foundIsbn == string::npos))
	{
		cout << setw(13) << "Book Not Found." << '\n';
		system("pause");
	}

	return;
}

//----------------------------------------------------------------------
// Function: addBook()
// Adds new books to the database
// Receives: orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList
// Returns: none
//----------------------------------------------------------------------
void addBook(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList)
{
	char choice = 'A';
	string tempTitle = "EMPTY";
	string tempIsbn = "EMPTY";
	string tempAuthor = "EMPTY";
	string tempPublisher = "EMPTY";
	string tempDate = "EMPTY";
	int tempQty = 0;
	double tempWholesale = 0.0;
	double tempRetail = 0.0;
	InventoryBook * newBook = new InventoryBook;

	do
	{
		system("cls");

		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(42) << "ADD BOOK" << setw(36) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << '*' << setw(63) << "CURRENT BOOK COUNT:" << setw(3) << titleList.length() << setw(12) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << '*' << setw(66) << "--PENDING VALUES" << setw(12) << '*' << '\n';
		cout << left << fixed;
		cout << setw(2) << '*' << setw(6) << "<1>" << setw(29) << "Enter Book Title" << setw(3) << '>' << "--" << setw(36) << tempTitle << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<2>" << setw(29) << "Enter ISBN" << setw(3) << '>' << "--" << setw(36) << tempIsbn << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<3>" << setw(29) << "Enter Author" << setw(3) << '>' << "--" << setw(36) << tempAuthor << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<4>" << setw(29) << "Enter Publisher" << setw(3) << '>' << "--" << setw(36) << tempPublisher << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<5>" << setw(29) << "Enter Date Added (mm/dd/yyyy)" << setw(3) << '>' << "--" << setw(36) << tempDate << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<6>" << setw(29) << "Enter Quantity on Hand" << setw(3) << '>' << "--" << setw(36) << tempQty << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<7>" << setw(29) << "Enter Wholesale Cost" << setw(3) << '>' << "--" << setprecision(2) << '$' << setw(35) << tempWholesale << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<8>" << setw(29) << "Enter Retail Price" << setw(3) << '>' << "--" << '$' << setw(35) << tempRetail << setprecision(0) << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<9>" << setw(70) << "Save Book to Database" << '*' << '\n';
		cout << setw(2) << '*' << setw(6) << "<0>" << setw(70) << "Return to Inventory Menu" << '*' << '\n';
		cout << right;
		cout << '*' << setw(78) << '*' << '\n';
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

		cout << setw(23) << "Choice(0-9): ";
		cin >> choice;
		if(cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = 'A';
		}

		switch(choice)
		{
		case '0':
			//return to inventory menu
			break;
		case '1':
			cout << setw(23) << "Book Title > ";
			getline(cin, tempTitle);
			break;
		case '2':
			cout << setw(23) << "ISBN > ";
			cin >> tempIsbn;
			break;
		case '3':
			cout << setw(23) << "Author > ";
			getline(cin, tempAuthor);
			break;
		case '4':
			cout << setw(23) << "Publisher > ";
			getline(cin, tempPublisher);
			break;
		case '5':
			cout << setw(23) << "Date > ";
			cin >> tempDate;
			break;
		case '6':
			cout << setw(23) << "Quantity > ";
			cin >> tempQty;
			while (cin.fail())
			{
				cout << setw(52) << "Wrong input, please re-enter." << '\n'
						<< setw(23) << "Quantity > ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> tempQty;
			}
			break;
		case '7':
			cout << setw(23) << "Wholesale Price > ";
			cin >> tempWholesale;
			while (cin.fail())
			{
				cout << setw(52) << "Wrong input, please re-enter." << '\n'
						<< setw(23) << "Wholesale Price > ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> tempWholesale;
			}
			break;
		case '8':
			cout << setw(23) << "Retail Price > ";
			cin >> tempRetail;
			while (cin.fail())
			{
				cout << setw(52) << "Wrong input, please re-enter." << '\n'
						<< setw(23) << "Retail Price > ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> tempRetail;
			}
			break;
		case '9':
			// update node value with temp values
			newBook->setTitle(tempTitle);
			newBook->setIsbn(tempIsbn);
			newBook->setAuthor(tempAuthor);
			newBook->setPub(tempPublisher);
			newBook->setDateAdded(tempDate);
			newBook->setQty(tempQty);
			newBook->setWholesale(tempWholesale);
			newBook->setRetail(tempRetail);

			// insert node to list
			(*newBook).setSortCode(0);
			titleList.insert(*newBook);
			(*newBook).setSortCode(1);
			qtyList.insert(*newBook);
			(*newBook).setSortCode(2);
			wholesaleList.insert(*newBook);
			(*newBook).setSortCode(3);
			dateList.insert(*newBook);

			// reset pending value
			tempTitle = "EMPTY";
			tempIsbn = "EMPTY";
			tempAuthor = "EMPTY";
			tempPublisher = "EMPTY";
			tempDate = "EMPTY";
			tempQty = 0;
			tempWholesale = 0.0;
			tempRetail = 0.0;
			break;
		default:
			cout << setw(78) << "Please enter a number in the range 0 - 9.\n\n";
			system("pause");
		}	// end switch
	} while (choice != '0');	// end outer do-while


	return;
}

//----------------------------------------------------------------------
// Function: editBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void editBook(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundTitle;
	size_t foundIsbn;
	string tempTitle = "EMPTY";
	string tempIsbn = "EMPTY";
	string tempAuthor = "EMPTY";
	string tempPublisher = "EMPTY";
	string tempDate = "EMPTY";
	int tempQty = 0;
	double tempWholesale = 0.0;
	double tempRetail = 0.0;
	linkedListIterator<InventoryBook> myIterator;	// iterator
	InventoryBook * newBook = new InventoryBook; // edited book

	system("cls");

	// display menu
	cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
	cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
	cout << '*' << setw(43) << "EDIT BOOK" << setw(35) << '*' << '\n';
	cout << '*' << setw(78) << '*' << '\n';
	cout << '*' << setw(63) << "CURRENT BOOK COUNT:" << setw(3) << titleList.length() << setw(7) << '*' << '\n';
	cout << '*' << setw(78) << '*' << '\n';
	cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

	// get search term
	cout << setw(13) << "Search: > ";
	getline(cin, userSearch);
	// ignore caps on search term
	for (unsigned int i = 0; i < userSearch.length(); i++)
	{
		if (isupper(userSearch[i]))
		{
			userSearch[i] = tolower(userSearch[i]);
		}
	}

	myIterator = titleList.begin();
	do
	{
		// ignore caps on target title
		target = (*myIterator).getTitle();
		for (unsigned int i = 0; i < target.length(); i++)
		{
			if (isupper(target[i]))
			{
				target[i] = tolower(target[i]);
			}
		}

		foundTitle = target.find(userSearch);
		if (foundTitle != string::npos)
		{
			cout << "RESULT: > " << (*myIterator).getTitle() << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				cout << '\n';
				(*myIterator).print();
				cout << '\n' << "Is this the book you want to EDIT? (Y/N): ";
				cin >> choice;

				break;
			}
		}

		foundIsbn = ((*myIterator).getIsbn()).find(userSearch);
		if (foundIsbn != string::npos)
		{
			cout << "RESULT: > " << (*myIterator).getIsbn() << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				cout << '\n';
				(*myIterator).print();
				cout << '\n' << "Is this the book you want to EDIT? (Y/N): ";
				cin >> choice;

				break;
			}
		}

		system("cls");

		// display menu
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(43) << "EDIT BOOK" << setw(35) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << '*' << setw(63) << "CURRENT BOOK COUNT:" << setw(3) << titleList.length() << setw(7) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '\n';
		++myIterator;
	} while (myIterator != titleList.end());	// end do-while

	// if book not found
	if(myIterator == titleList.end() || (foundTitle == string::npos && foundIsbn == string::npos))
	{
		cout << setw(13) << "Book Not Found." << '\n';
		system("pause");
	}

	if (tolower(choice) == 'y')
	{
		// setup display info with selected book information
		tempTitle = (*myIterator).getTitle();
		tempIsbn = (*myIterator).getIsbn();
		tempAuthor = (*myIterator).getAuthor();
		tempPublisher = (*myIterator).getPub();
		tempDate = (*myIterator).getDateAdded();
		tempQty = (*myIterator).getQty();
		tempWholesale = (*myIterator).getWholesale();
		tempRetail = (*myIterator).getRetail();

		do
		{
			system("cls");

			// display menu
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
			cout << '*' << setw(43) << "EDIT BOOK" << setw(35) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << '*' << setw(63) << "CURRENT BOOK COUNT:" << setw(3) << titleList.length() << setw(7) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			// display edit screen
			cout << '*' << setw(66) << "--CURRENT VALUES" << setw(12) << '*' << '\n';
			cout << left << fixed;
			cout << setw(2) << '*' << setw(6) << "<1>" << setw(29) << "Edit Book Title" << setw(3) << '>' << "--" << setw(36) << tempTitle << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<2>" << setw(29) << "Edit ISBN" << setw(3) << '>' << "--" << setw(36) << tempIsbn << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<3>" << setw(29) << "Edit Author" << setw(3) << '>' << "--" << setw(36) << tempAuthor << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<4>" << setw(29) << "Edit Publisher" << setw(3) << '>' << "--" << setw(36) << tempPublisher << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<5>" << setw(29) << "Edit Date Added (mm/dd/yyyy)" << setw(3) << '>' << "--" << setw(36) << tempDate << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<6>" << setw(29) << "Edit Quantity on Hand" << setw(3) << '>' << "--" << setw(36) << tempQty << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<7>" << setw(29) << "Edit Wholesale Cost" << setw(3) << '>' << "--" << setprecision(2) << '$' << setw(35) << tempWholesale << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<8>" << setw(29) << "Edit Retail Price" << setw(3) << '>' << "--" << '$' << setw(35) << tempRetail << setprecision(0) << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<9>" << setw(70) << "Save Edited Book" << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<0>" << setw(70) << "Return to Inventory Menu" << '*' << '\n';
			cout << right;
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

			// get user menu choice
			cout << setw(23) << "Choice(1-9): ";
			cin >> choice;
			if(cin.get() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = 'A';
			}

			switch(choice)
			{
			case '1':
				cout << setw(23) << "Book Title > ";
				getline(cin, tempTitle);
				break;
			case '2':
				cout << setw(23) << "ISBN > ";
				cin >> tempIsbn;
				break;
			case '3':
				cout << setw(23) << "Author > ";
				getline(cin, tempAuthor);
				break;
			case '4':
				cout << setw(23) << "Publisher > ";
				getline(cin, tempPublisher);
				break;
			case '5':
				cout << setw(23) << "Date > ";
				cin >> tempDate;
				break;
			case '6':
				cout << setw(23) << "Quantity > ";
				cin >> tempQty;
				while (cin.fail() || tempQty < 0)
				{
					cout << setw(52) << "Wrong input, please re-enter." << '\n'
							<< setw(23) << "Quantity > ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> tempQty;
				}
				break;
			case '7':
				cout << setw(23) << "Wholesale Price > ";
				cin >> tempWholesale;
				while (cin.fail())
				{
					cout << setw(52) << "Wrong input, please re-enter." << '\n'
							<< setw(23) << "Wholesale Price > ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> tempWholesale;
				}
				break;
			case '8':
				cout << setw(23) << "Retail Price > ";
				cin >> tempRetail;
				while (cin.fail())
				{
					cout << setw(52) << "Wrong input, please re-enter." << '\n'
							<< setw(23) << "Retail Price > ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> tempRetail;
				}
				break;
			case '9':
				// delete old book with previous info
				titleList.deleteNode(*myIterator);
				qtyList.deleteNode(*myIterator);
				wholesaleList.deleteNode(*myIterator);
				dateList.deleteNode(*myIterator);
				// add information to new book
				newBook->setTitle(tempTitle);
				newBook->setIsbn(tempIsbn);
				newBook->setAuthor(tempAuthor);
				newBook->setPub(tempPublisher);
				newBook->setDateAdded(tempDate);
				newBook->setQty(tempQty);
				newBook->setWholesale(tempWholesale);
				newBook->setRetail(tempRetail);
				// insert new book to lists
				(*newBook).setSortCode(0);
				titleList.insert(*newBook);
				(*newBook).setSortCode(1);
				qtyList.insert(*newBook);
				(*newBook).setSortCode(2);
				wholesaleList.insert(*newBook);
				(*newBook).setSortCode(3);
				dateList.insert(*newBook);
				cout << setw(50) << "Book has been saved. Returning to Inventory Menu.\n";
				system("pause");
				break;
			case '0':
				// return to inventory
				break;
			default:
				cout << setw(78) << "Please enter a number in the range 1 - 9.\n\n";
				system("pause");
			}	// end switch (menu choice)

		} while(choice != '0' && choice != '9');	// end do-while
	}	// end if (tolower(choice == 'y'))
	return;
}

//----------------------------------------------------------------------
// Function: deleteBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void deleteBook(orderedLinkedList<InventoryBook>& titleList, orderedLinkedList<InventoryBook>& qtyList, orderedLinkedList<InventoryBook>& wholesaleList, orderedLinkedList<InventoryBook>& dateList)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundTitle;
	size_t foundIsbn;
	linkedListIterator<InventoryBook> myIterator;	// iterator

	do
	{
		// reset variables
		choice = '\0';
		userSearch = "";
		target = "";

		system("cls");

		// display menu
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(45) << "DELETE BOOK" << setw(33) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << '*' << setw(63) << "CURRENT BOOK COUNT:" << setw(3) << titleList.length() << setw(7) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

		// Book Search
		cout << setw(13) << "Search: > ";
		getline(cin, userSearch);

		// ignore caps on search term
		for (unsigned int i = 0; i < userSearch.length(); i++)
		{
			if (isupper(userSearch[i]))
			{
				userSearch[i] = tolower(userSearch[i]);
			}
		}

		// search database
		myIterator = titleList.begin();
		do
		{
			// ignore caps on titles
			target = (*myIterator).getTitle();
			for (unsigned int i = 0; i < target.length(); i++)
			{
				if (isupper(target[i]))
				{
					target[i] = tolower(target[i]);
				}
			}

			// find user search in title
			foundTitle = target.find(userSearch);
			if (foundTitle != string::npos)
			{
				cout << "RESULT: > " << (*myIterator).getTitle() << '\n';
				cout << "View this book record? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					cout << '\n';
					(*myIterator).print();
					cout << '\n';
					cout << "Is this the book you want to DELETE? (Y/N): ";
					cin >> choice;
					break;
				}
			}

			// find user search in isbn
			foundIsbn = ((*myIterator).getIsbn()).find(userSearch);
			if (foundIsbn != string::npos)
			{
				cout << "RESULT: > " << (*myIterator).getIsbn() << '\n';
				cout << "View this book record? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					cout << '\n';
					(*myIterator).print();
					cout << '\n';
					cout << "Is this the book you want to DELETE? (Y/N): ";
					cin >> choice;
					break;
				}
			}

			system("cls");
			// display menu
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
			cout << '*' << setw(45) << "DELETE BOOK" << setw(33) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << '*' << setw(63) << "CURRENT BOOK COUNT:" << setw(3) << titleList.length() << setw(7) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			cout << '\n';

			++myIterator;
		} while (myIterator != titleList.end());		// end of database search

		// if search result is negative
		if(myIterator == titleList.end() || (foundTitle == string::npos && foundIsbn == string::npos))
		{
			cout << setw(13) << "Book Not Found." << '\n';
			system("pause");
		}

		// delete book
		if (tolower(choice) == 'y')
		{
			titleList.deleteNode(*myIterator);
			qtyList.deleteNode(*myIterator);
			wholesaleList.deleteNode(*myIterator);
			dateList.deleteNode(*myIterator);

			cout << "Book Deleted.\n";
			cout << "Delete Another? (Y/N): ";
			cin >> choice;
			cin.ignore();
		}
	} while (choice == 'y');

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
	double totalPage = ceil(double(titleList.length())/10);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	int i = 0;
	myIterator = titleList.begin();
	do
	{
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
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     CURRENT BOOK COUNT: " << titleList.length()
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
		while (myIterator != titleList.end())
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
			++myIterator;
			i++;
			if (i % 10 == 0 && myIterator != titleList.end())
			{
				currentPage++;
				system("pause");
				break;
			}
		}	// end iterator loop
	} while(myIterator != titleList.end());
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
	double totalPage = ceil(double(titleList.length())/10);
	double subtotal = 0.00;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	int i = 0;
	myIterator = titleList.begin();
	do
	{
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
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     CURRENT BOOK COUNT: " << titleList.length()
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
		while (myIterator != titleList.end())
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
			++myIterator;
			i++;
			if (i % 10 == 0 && myIterator != titleList.end())
			{
				currentPage++;
				system("pause");
				break;
			}
		}	// end iterator loop
	} while(myIterator != titleList.end());

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
	double totalPage = ceil(double(titleList.length())/10);
	double subtotal = 0.00;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	int i = 0;
	myIterator = titleList.begin();
	do
	{
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
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     CURRENT BOOK COUNT: " << titleList.length()
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
		while (myIterator != titleList.end())
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
			++myIterator;
			i++;
			if (i % 10 == 0 && myIterator != titleList.end())
			{
				currentPage++;
				system("pause");
				break;
			}
		}	// end iterator loop
	} while(myIterator != titleList.end());

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
	double totalPage = ceil(double(qtyList.length())/10);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	int i = 0;
	myIterator = qtyList.begin();
	do
	{
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
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     CURRENT BOOK COUNT: " << qtyList.length()
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
		while (myIterator != qtyList.end())
		{
			cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
					<< setw(5) << ' '
					<< setw(10) << (*myIterator).getIsbn()
					<< setw(5) << ' '
					<< right << setw(7) << (*myIterator).getQty();
			cout << "\n\n";
			++myIterator;
			i++;
			if (i % 10 == 0 && myIterator != qtyList.end())
			{
				currentPage++;
				system("pause");
				break;
			}
		}	// end iterator loop
	} while(myIterator != qtyList.end());
	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: repCost()
//
// Receives: orderedLinkedList<InventoryBook> wholesaleList
// Returns: none
//----------------------------------------------------------------------
void repCost(orderedLinkedList<InventoryBook> wholesaleList)
{
	int currentPage = 1;
	double totalPage = ceil(double(wholesaleList.length())/10);
	double subtotal = 0.00;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	int i = 0;
	myIterator = wholesaleList.begin();
	do
	{
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
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     CURRENT BOOK COUNT: " << wholesaleList.length()
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
		while (myIterator != wholesaleList.end())
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
			++myIterator;
			i++;
			if (i % 10 == 0 && myIterator != wholesaleList.end())
			{
				currentPage++;
				system("pause");
				break;
			}
		}	// end iterator loop
	} while(myIterator != wholesaleList.end());

	// total wholesale value
	cout << left << setw(69) << "Total Wholesale Value: "
			<< setw(1) << '$' << right << setfill('.') << setw(13) << setprecision(2) << subtotal << setfill(' ') << setprecision(0)
			<< "\n\n";

	system("pause");
	return;
}

//----------------------------------------------------------------------
// Function: repAge()
//
// Receives: orderedLinkedList<InventoryBook> dateList
// Returns: none
//----------------------------------------------------------------------
void repAge(orderedLinkedList<InventoryBook> dateList)
{
	int currentPage = 1;
	double totalPage = ceil(double(dateList.length())/10);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	linkedListIterator<InventoryBook> myIterator;	// iterator

	int i = 0;
	myIterator = dateList.begin();
	do
	{
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
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     CURRENT BOOK COUNT: " << dateList.length()
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
		while (myIterator != dateList.end())
		{
			cout << left << setw(37) << ((*myIterator).getTitle()).substr(0,37)
					<< setw(5) << ' '
					<< setw(10) << (*myIterator).getIsbn()
					<< setw(5) << ' '
					<< right << setw(7) << (*myIterator).getQty()
					<< setw(5) << ' '
					<< setw(10) << (*myIterator).getDateAdded();
			cout << "\n\n";
			++myIterator;
			i++;
			if (i % 10 == 0 && myIterator != dateList.end())
			{
				currentPage++;
				system("pause");
				break;
			}
		}	// end iterator loop
	} while(myIterator != dateList.end());
	system("pause");
	return;
}
