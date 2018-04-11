// ----------------------------------------------------------------------
// File name: mainmenu.cpp												-
// Project name: serendipity											-
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 01/16/2018											-
// Date of Last Modification: 04/10/2018								-
// ----------------------------------------------------------------------
// Purpose: Serendipity Bookstore's POS system which allows user to add,-
//			modify, and delete a library of up to 20 books.				-
// ----------------------------------------------------------------------
// main() Algorithm:													-
// Step 1: Display main menu											-
// Step 2: Ask user to input choice at least once						-
// Step 3: Choice 1-3 executes the next menu function					-
// 		Choice 4 ends program											-
//		if invalid input, ask user to re-enter							-
// cashier():															-
// Step 4: User search for book title									-
// Step 5: Search through array for matching title						-
// Step 6: If user finds title, display information						-
// Step 7: If user wants to purchase book								-
// Step 8: Ask user to input book price									-
//		if invalid input, ask user to re-enter							-
// Step 9: calculate subtotal											-
// Step 10: Display sales slip											-
// Step 11: Ask if user wishes to repeat program						-
//		if yes, repeat													-
//		if no, return to main menu										-
//		if invalid input, ask user to re-enter							-
// addBook():															-
// Step 12: Display Menu												-
// Step 13: Option 1-8, assign user input value to temp variable		-
// Step 13: Option 9, write value in temp to array & increase bookCount	-
// editBook():															-
// Step 14: User search for book title									-
// Step 15: Search through array for matching title						-
// Step 16: If user finds title, display information					-
// Step 17: If user wants to edit book info, display edit menu			-
// Step 18: Option 1-8, re-write user input value to array				-
// deleteBook():														-
// Step 19: User search for book title									-
// Step 20: Search through array for matching title						-
// Step 21: If user finds title, display information					-
// Step 22: If user wants to delete book,								-
// Step 23: Shift value in each element down one to fill element of deleted book
// Step 24: Decrease bookCount											-
// lookUpBook():														-
// Step 25: Ask user to search for book title							-
// Step 26: Search through array for matching book title				-
// Step 27: If user finds title, display information					-
// ----------------------------------------------------------------------
// -							DATA DICTIONARY							-
// - CONSTANTS															-
// -																	-
// - NAME					DATA TYPE				VALUE				-
// - --------------------   ----------				--------			-
// - SALES_TAX				const float				0.06				-
// - DBSIZE					const int				20					-
// - BookData				struct
//																		-
// - VARIABLES															-
// -																	-
// - NAME					DATA TYPE				INITIAL VALUE		-
// - --------------------   ----------				-------------		-
// - title					string										-
// - isbn					string										-
// - author					string										-
// - publisher				string										-
// - date					string										-
// - qty					int											-
// - wholesale				double										-
// - retail					double										-
// - choice					char					\0					-
// - bookCount				int						0					-
// - userSearch				string										-
// - target					string										-
// - foundTitle				size_t										-
// - foundIsbn				size_t										-
// - t						time_t					time(0)				-
// - bookArray				BookData[]									-
// ----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>
#include <ctime>
using namespace std;

const float SALES_TAX = 0.06;
const int DBSIZE = 20;

struct BookData
{
//	for later cstring use
//	char bookTitle[51];	// 50 characters in length
//	char isbn[14]; // 13 characters in length
//	char author[31]; // 30 characters in length
//	char publisher[31]; //30 characters in length
//	char dateAdded[11]; // MM-DD-YYYY 10 characters in length
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
};

int cashier(BookData bookArray[], int& bookCount);
int invMenu(BookData bookArray[], int& bookCount);
int bookInfo(string, string, string, string, string, int, double, double);
int retailInfo(string isbn, string title, string author, string publisher, string date, int qty, double retail);
int reports(BookData bookArray[], int bookCount);
void lookUpBook(BookData bookArray[], int& bookCount);
void addBook(BookData bookArray[], int& bookCount);
void editBook(BookData bookArray[], int& bookCount);
void deleteBook(BookData bookArray[], int& bookCount);
void repListing(BookData bookArray[], int bookCount);
void repWholesale(BookData bookArray[], int bookCount);
void repRetail(BookData bookArray[], int bookCount);
void repQty(BookData bookArray[], int bookCount);
void repCost(BookData bookArray[], int bookCount);
void repAge(BookData bookArray[], int bookCount);
void setTitle(BookData bookArray[], int bookCount, string title);
void setIsbn(BookData bookArray[], int bookCount, string isbn);
void setAuthor(BookData bookArray[], int bookCount, string author);
void setPub(BookData bookArray[], int bookCount, string publisher);
void setDateAdded(BookData bookArray[], int bookCount, string date);
void setQty(BookData bookArray[], int bookCount, int qty);
void setWholesale(BookData bookArray[], int bookCount, double wholesale);
void setRetail(BookData bookArray[], int bookCount, double retail);
void removeBook(BookData bookArray[], int& bookCount, int target);

int main()
{
	// struct array (new)
	BookData bookArray[DBSIZE];
	char choice = '\0';
	int bookCount = 0;		// index

	do
	{
		system("cls");

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
			cashier(bookArray, bookCount);
			break;
		case '2':
			invMenu(bookArray, bookCount);
			break;
		case '3':
			reports(bookArray, bookCount);
			break;
		case '4':
			break;
		default:
			cout << "Please enter a number in the range 1 - 4.\n\n";
			system("pause");
		}

	} while (choice != '4');

	return 0;
}

int cashier(BookData bookArray[], int& bookCount)
{
	BookData cart[DBSIZE];
	BookData tempStock[DBSIZE];

	string userSearch = "";
	string target;
	string targetIsbn;
	size_t foundTitle;
	int userQty = 0;
	float subtotal = 0.00;
	char choice = '\0';


	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	do
	{
		// copy book info to temp stock & cart
		for (int i = 0; i < bookCount; i++)
		{
			tempStock[i] = bookArray[i];
			cart[i] = bookArray[i];
			cart[i].qtyOnHand = 0;
		}

		do
		{
			// reset screen & choice var
			system("cls");
			choice = '\0';

			// display menu
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
			cout << '*' << setw(45) << "CASHIER MODULE" << setw(33) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

			cout << "Today's Date: "
					<< (now->tm_mon + 1) << '/' <<  now->tm_mday << '/' << (now->tm_year + 1900) << "\n\n";

			// get user search term
			cout << "Title or ISBN: ";
			getline(cin, userSearch);

			// change search term to ignore case (loop per character)
			for (unsigned int i = 0; i < userSearch.length(); i++)
			{
				if (isupper(userSearch[i]))
				{
					userSearch[i] = tolower(userSearch[i]);
				}
			}

			int i = 0;
			do
			{
				// change target title to ignore case
				target = tempStock[i].bookTitle;
				for (unsigned int i = 0; i < target.length(); i++)
				{
					if (isupper(target[i]))
					{
						target[i] = tolower(target[i]);
					}
				}
				targetIsbn = tempStock[i].isbn;
				for (unsigned int i = 0; i < targetIsbn.length(); i++)
				{
					if (isupper(targetIsbn[i]))
					{
						targetIsbn[i] = tolower(targetIsbn[i]);
					}
				}

				// find title from partial search term
				foundTitle = target.find(userSearch);
				// if title or isbn is found
				if (foundTitle != string::npos || targetIsbn == userSearch)
				{
					// title
					if (foundTitle != string::npos)
					{
						cout << "RESULT: > " << tempStock[i].bookTitle << '\n';
						cout << "View this book? (Y/N): ";
					}

					// isbn
					if (targetIsbn == userSearch)
					{
						cout << "RESULT: > " << tempStock[i].isbn << '\n';
						cout << "View this book? (Y/N): ";
					}

					choice = '\0';
					cin >> choice;
					if(cin.get() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						choice = '0';
					}
				}


				// if user wants to view book
				if (tolower(choice) == 'y')
				{
					// display book
					retailInfo(tempStock[i].isbn, tempStock[i].bookTitle, tempStock[i].author, tempStock[i].publisher, tempStock[i].dateAdded, tempStock[i].qtyOnHand, tempStock[i].retail);

					cout << "Add " << tempStock[i].bookTitle << " to cart? (Y/N): ";
					cin >> choice;
					if(cin.get() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						choice = '0';
					}

					// if user decides to add book to cart
					if (tolower(choice == 'y'))
					{
						// check if book is in stock
						if (tempStock[i].qtyOnHand == 0)
						{
							cout << "\nSold out. Unable to add to cart.\n";
							i++;
							break;
						}
						// if book in stock, get quantity
						cout << "Quantity of Book (Enter 0 to cancel): ";
						cin >> userQty;
						while (cin.fail() || tempStock[i].qtyOnHand < userQty || userQty <= 0)
						{
							if (tempStock[i].qtyOnHand < userQty)
							{
								cout << "Error, there are only " << tempStock[i].qtyOnHand << " on hand.\n"
										<< "please re-enter quantity: ";
								cin >> userQty;
							}
							if (cin.fail() || userQty < 0)
							{
								cout << "Error, please re-enter quantity (1 or more): ";
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cin >> userQty;
							}
							else if (userQty == 0)
							{
								break;
							}
						}	// end while loop - quantity check

						if (userQty == 0)
						{
							cout << "Cancelled adding to cart." << "\n\n";
							i = bookCount;
							break;
						}
						cout << "\nBook added to cart." << "\n\n";

						// set quantity to cart
						cart[i].qtyOnHand += userQty;

						// set temp stock quantity
						tempStock[i].qtyOnHand = tempStock[i].qtyOnHand - userQty;

						break;

					}	// end if statement - user decides to add book to cart
					else
					{
						break;
						i++;
					}
				}	// end if statement - user views book
				else
				{
					// if use decides not to add book to cart
					// reset display and move onto next book in search
					system("cls");

					// display menu
					cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
					cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
					cout << '*' << setw(45) << "CASHIER MODULE" << setw(33) << '*' << '\n';
					cout << '*' << setw(78) << '*' << '\n';
					cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

					cout << "Today's Date: "
							<< (now->tm_mon + 1) << '/' <<  now->tm_mday << '/' << (now->tm_year + 1900) << "\n\n";

					i++;
					continue;
				}

			} while (i < bookCount);

			// if book was not found in search
			if (i == bookCount || (foundTitle == string::npos && tempStock[i].isbn == userSearch) || tolower(choice) != 'y')
			{
				cout << setw(13) << "Book Not Found." << "\n\n";
			}



			// display exit menu
			cout << "(C) to Continue shopping" << '\n'
					<< "(P) to Proceed to checkout" << '\n'
					<< "(A) to Abort sales and exit cashier module" << "\n\n";
			do
			{
				cout << "Enter Choice:  ";
				choice = '\0';
				cin >> choice;
				if(cin.get() != '\n')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					choice = '0';
				}

				switch(tolower(choice))
				{
				case 'c':	// continue shopping
					break;
				case 'p':	// proceed checkout
					break;
				case 'a':	// abort sales
					cout << "Cart will not be saved. Do you really want to exit? (Y/N):  ";
					cin >> choice;
					if(cin.get() != '\n')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						choice = '0';
					}
					if (tolower(choice) == 'y')
					{
						break;
					}
					else
					{
						choice = 'c';
					}
					break;
				default:
					cout << "\nWrong input.\n";
					choice = '0';
					break;
				}
			} while (choice == '0');	// get menu choice
		} while(tolower(choice) == 'c');	// display menu, get user search term & convert to same case. Goal: do until user does not want to continue shopping

		// print receipt
		if (tolower(choice) == 'p')
		{

			// change stock quantity to reflect after purchase
			for (int i = 0; i < bookCount; i++)
			{
				setQty(bookArray, i, tempStock[i].qtyOnHand);
			}

			system("pause");

			system("cls");

			// Sales Slip
			cout << "Serendipity Book Sellers\n\n";
			cout << "Date: " << (now->tm_mon + 1) << '/' <<  now->tm_mday << '/' << (now->tm_year + 1900) << "\n\n";

			cout << left
					<< setw(5) << "Qty"
					<< setw(15) << "ISBN"
					<< setw(25) << "Title"
					<< setw(12) << "Price"
					<< "Total\n";

			cout << "__________________________________________________________________\n";

			// display books
			for (int i = 0; i < bookCount; i++)
			{
				if (cart[i].qtyOnHand > 0)
				{
					cout << left << setw(5) << cart[i].qtyOnHand
							<< setw(15) << cart[i].isbn
							<< setw(25) << (cart[i].bookTitle).substr(0,23)
							<< fixed << setprecision(2)
							<< setw(1) << "$" << setw(11) << cart[i].retail
							<< setw(1) << "$" << right << setw(6) << (cart[i].retail * float(cart[i].qtyOnHand));
					cout << "\n\n";
				}
			}

			// calculate subtotal
			for (int i = 0; i < bookCount; i++)
			{
				// add to subtotal only if book is in cart
				if (cart[i].qtyOnHand > 0)
				{
					subtotal = subtotal + (cart[i].retail * float(cart[i].qtyOnHand));
				}
			}

			// display total
			cout << left << setw(16) << "\n\n\n" << setw(44) << "Subtotal" << "$" << right << setw(6) << subtotal
					<< left << setw(14) << "\n" << setw(44) << "Tax" << "$" << right << setw(6) << subtotal*SALES_TAX
					<< left << setw(14) << "\n" << setw(44) << "Total" << "$" << right << setw(6) << (subtotal*SALES_TAX) + subtotal << "\n";

			cout << "\nThank you for Shopping at Serendipity!\n\n";

			cout << "Process another transaction (Y/N)?: ";
			choice = '\0';
			cin >> choice;
			if(cin.get() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = '0';
			}

		}	// end print receipt
		else
		{
			break;
		}
	} while (tolower(choice) == 'y');
	return 0;
}

int invMenu(BookData bookArray[], int& bookCount)
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
			lookUpBook(bookArray, bookCount);
			break;
		case '2':
			addBook(bookArray, bookCount);
			break;
		case '3':
			editBook(bookArray, bookCount);
			break;
		case '4':
			deleteBook(bookArray, bookCount);
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

int bookInfo(string isbn, string title, string author, string publisher,
		string date, int qty, double wholesale, double retail)
{
	cout << fixed << '\n';
	cout << "Title:" << setfill('-') << setw(24) << '-' << setfill(' ') << " >" << title << '\n'
			<< "ISBN:" << setfill('-') << setw(25) << '-' << setfill(' ') << " >" << isbn << '\n'
			<< "Author:" << setfill('-') << setw(23) << '-' << setfill(' ') << " >" << author << '\n'
			<< "Publisher:" << setfill('-') << setw(20) << '-' << setfill(' ') << " >" << publisher << '\n'
			<< "Date Added:" << setfill('-') << setw(19) << '-' << setfill(' ') << " >" << date << '\n'
			<< "Quantity-On-Hand:" << setfill('-') << setw(13) << '-' << setfill(' ') << " >" << qty << '\n'
			<< "Wholesale Cost:" << setfill('-') << setw(15) << '-' << setfill(' ') << " >$" << setprecision(2) << wholesale << '\n'
			<< "Retail Price:" << setfill('-') << setw(17) << '-' << setfill(' ') << " >$" << retail << setprecision(0) << '\n';
	system("pause");
	cout << '\n';
	return 0;
}

int retailInfo(string isbn, string title, string author, string publisher,
		string date, int qty, double retail)
{
	cout << fixed << '\n';
	cout << "Title:" << setfill('-') << setw(24) << '-' << setfill(' ') << " >" << title << '\n'
			<< "ISBN:" << setfill('-') << setw(25) << '-' << setfill(' ') << " >" << isbn << '\n'
			<< "Author:" << setfill('-') << setw(23) << '-' << setfill(' ') << " >" << author << '\n'
			<< "Publisher:" << setfill('-') << setw(20) << '-' << setfill(' ') << " >" << publisher << '\n'
			<< "Date Added:" << setfill('-') << setw(19) << '-' << setfill(' ') << " >" << date << '\n'
			<< "Quantity-On-Hand:" << setfill('-') << setw(13) << '-' << setfill(' ') << " >" << qty << '\n'
			<< "Retail Price:" << setfill('-') << setw(17) << '-' << setfill(' ') << " >$" << retail << setprecision(0) << '\n';
	cout << '\n';
	return 0;
}

int reports(BookData bookArray[], int bookCount)
{
	char choice = '\0';

	do
	{
		system("cls");

		cout << setw(60) << "Serendipity Booksellers\n"
				<< setw(53) << "Reports\n\n";

		cout << setw(56) << "1.  Inventory Listing\n"
				<< setw(64) << "2.  Inventory Wholesale Value\n"
				<< setw(61) << "3.  Inventory Retail Value\n"
				<< setw(58) << "4.  Listing by Quantity\n"
				<< setw(54) << "5.  Listing by Cost\n"
				<< setw(53) << "6.  Listing by Age\n"
				<< setw(63) << "7.  Return to the Main Menu\n\n";

		cout << setw(54) <<  "Enter Your Choice: ";
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
			repListing(bookArray, bookCount);
			break;
		case '2':
			repWholesale(bookArray, bookCount);
			break;
		case '3':
			repRetail(bookArray, bookCount);
			break;
		case '4':
			repQty(bookArray, bookCount);
			break;
		case '5':
			repCost(bookArray, bookCount);
			break;
		case '6':
			repAge(bookArray, bookCount);
			break;
		case '7':
			break;
		default:
			cout << setw(78) << "Please enter a number in the range 1 - 7.\n\n";
			system("pause");
		}
	} while(choice != '7');

	return 0;
}

void lookUpBook(BookData bookArray[], int& bookCount)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundTitle;
	size_t foundIsbn;

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

	int i = 0;
	do
	{
		// change target title to ignore case
		target = bookArray[i].bookTitle;
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
			cout << "RESULT: > " << bookArray[i].bookTitle << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				bookInfo(bookArray[i].isbn, bookArray[i].bookTitle, bookArray[i].author, bookArray[i].publisher, bookArray[i].dateAdded, bookArray[i].qtyOnHand, bookArray[i].wholesale, bookArray[i].retail);
				break;
			}
		}

		// find ISBN from partial search term
		foundIsbn = (bookArray[i].isbn).find(userSearch);
		if (foundIsbn != string::npos)
		{
			cout << "RESULT: > " << bookArray[i].isbn << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				bookInfo(bookArray[i].isbn, bookArray[i].bookTitle, bookArray[i].author, bookArray[i].publisher, bookArray[i].dateAdded, bookArray[i].qtyOnHand, bookArray[i].wholesale, bookArray[i].retail);
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
		i++;
	} while (i < bookCount);

	// If user exhausts all book options or no matching title is found
	if(i == bookCount || (foundTitle == string::npos && foundIsbn == string::npos))
	{
		cout << setw(13) << "Book Not Found." << '\n';
		system("pause");
	}

}

void addBook(BookData bookArray[], int& bookCount)
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

	do
	{
		system("cls");

		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(42) << "ADD BOOK" << setw(36) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << '*' << setw(43) << "DATABASE SIZE:" << setw(3) << DBSIZE << setw(2) << ' '
				<< setw(20) << "CURRENT BOOK COUNT:" << setw(3) << bookCount << setw(7) << '*' << '\n';
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

		if (bookCount >= 20)
		{
			cout << "Database is Full. Press Enter to return to Inventory Menu.\n";
			cin.get();
			break;
		}

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
			// save pending value to array
			setTitle(bookArray, bookCount, tempTitle);
			setIsbn(bookArray, bookCount, tempIsbn);
			setAuthor(bookArray, bookCount, tempAuthor);
			setPub(bookArray, bookCount, tempPublisher);
			setDateAdded(bookArray, bookCount, tempDate);
			setQty(bookArray, bookCount, tempQty);
			setWholesale(bookArray, bookCount, tempWholesale);
			setRetail(bookArray, bookCount, tempRetail);
			// increase book count
			bookCount++;

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
		}
	} while (choice != '0');
}

void editBook(BookData bookArray[], int& bookCount)
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


	system("cls");

	// display menu
	cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
	cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
	cout << '*' << setw(43) << "EDIT BOOK" << setw(35) << '*' << '\n';
	cout << '*' << setw(78) << '*' << '\n';
	cout << '*' << setw(43) << "DATABASE SIZE:" << setw(3) << DBSIZE << setw(2) << ' '
			<< setw(20) << "CURRENT BOOK COUNT:" << setw(3) << bookCount << setw(7) << '*' << '\n';
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

	int i = 0;
	do
	{
		// ignore caps on target title
		target = bookArray[i].bookTitle;
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
			cout << "RESULT: > " << bookArray[i].bookTitle << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				bookInfo(bookArray[i].isbn, bookArray[i].bookTitle, bookArray[i].author, bookArray[i].publisher, bookArray[i].dateAdded, bookArray[i].qtyOnHand, bookArray[i].wholesale, bookArray[i].retail);
				cout << "Is this the book you want to EDIT? (Y/N): ";
				cin >> choice;

				break;
			}
		}

		foundIsbn = (bookArray[i].isbn).find(userSearch);
		if (foundIsbn != string::npos)
		{
			cout << "RESULT: > " << bookArray[i].isbn << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				bookInfo(bookArray[i].isbn, bookArray[i].bookTitle, bookArray[i].author, bookArray[i].publisher, bookArray[i].dateAdded, bookArray[i].qtyOnHand, bookArray[i].wholesale, bookArray[i].retail);
				cout << "Is this the book you want to EDIT? (Y/N): ";
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
		cout << '*' << setw(43) << "DATABASE SIZE:" << setw(3) << DBSIZE << setw(2) << ' '
				<< setw(20) << "CURRENT BOOK COUNT:" << setw(3) << bookCount << setw(7) << '*' << '\n';
		cout << '*' << setw(78) << '*' << '\n';
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '\n';
		i++;
	} while (i < bookCount);

	if(i == bookCount || (foundTitle == string::npos && foundIsbn == string::npos))
	{
		cout << setw(13) << "Book Not Found." << '\n';
		system("pause");
	}

	if (tolower(choice) == 'y')
	{
		do
		{
			system("cls");

			// display menu
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
			cout << '*' << setw(43) << "EDIT BOOK" << setw(35) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << '*' << setw(43) << "DATABASE SIZE:" << setw(3) << DBSIZE << setw(2) << ' '
					<< setw(20) << "CURRENT BOOK COUNT:" << setw(3) << bookCount << setw(7) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			// display edit screen
			cout << '*' << setw(66) << "--CURRENT VALUES" << setw(12) << '*' << '\n';
			cout << left << fixed;
			cout << setw(2) << '*' << setw(6) << "<1>" << setw(29) << "Edit Book Title" << setw(3) << '>' << "--" << setw(36) << bookArray[i].bookTitle << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<2>" << setw(29) << "Edit ISBN" << setw(3) << '>' << "--" << setw(36) << bookArray[i].isbn << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<3>" << setw(29) << "Edit Author" << setw(3) << '>' << "--" << setw(36) << bookArray[i].author << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<4>" << setw(29) << "Edit Publisher" << setw(3) << '>' << "--" << setw(36) << bookArray[i].publisher << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<5>" << setw(29) << "Edit Date Added (mm/dd/yyyy)" << setw(3) << '>' << "--" << setw(36) << bookArray[i].dateAdded << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<6>" << setw(29) << "Edit Quantity on Hand" << setw(3) << '>' << "--" << setw(36) << bookArray[i].qtyOnHand << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<7>" << setw(29) << "Edit Wholesale Cost" << setw(3) << '>' << "--" << setprecision(2) << '$' << setw(35) << bookArray[i].wholesale << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<8>" << setw(29) << "Edit Retail Price" << setw(3) << '>' << "--" << '$' << setw(35) << bookArray[i].retail << setprecision(0) << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<9>" << setw(70) << "Return to Inventory Menu" << '*' << '\n';
			cout << right;
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';

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
				setTitle(bookArray, i, tempTitle);
				tempTitle = "EMPTY";
				break;
			case '2':
				cout << setw(23) << "ISBN > ";
				cin >> tempIsbn;
				setIsbn(bookArray, i, tempIsbn);
				tempIsbn = "EMPTY";
				break;
			case '3':
				cout << setw(23) << "Author > ";
				getline(cin, tempAuthor);
				setAuthor(bookArray, i, tempAuthor);
				tempAuthor = "EMPTY";
				break;
			case '4':
				cout << setw(23) << "Publisher > ";
				getline(cin, tempPublisher);
				setPub(bookArray, i, tempPublisher);
				tempPublisher = "EMPTY";
				break;
			case '5':
				cout << setw(23) << "Date > ";
				cin >> tempDate;
				setDateAdded(bookArray, i, tempDate);
				tempDate = "EMPTY";
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
				setQty(bookArray, i, tempQty);
				tempQty = 0;
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
				setWholesale(bookArray, i, tempWholesale);
				tempWholesale = 0.0;
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
				setRetail(bookArray, i, tempRetail);
				tempRetail = 0.0;
				break;
			case '9':
				break;
			default:
				cout << setw(78) << "Please enter a number in the range 1 - 9.\n\n";
				system("pause");
			}

		} while(choice != '9');
	}
}

void deleteBook(BookData bookArray[], int& bookCount)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundTitle;
	size_t foundIsbn;


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
		cout << '*' << setw(43) << "DATABASE SIZE:" << setw(3) << DBSIZE << setw(2) << ' '
				<< setw(20) << "CURRENT BOOK COUNT:" << setw(3) << bookCount << setw(7) << '*' << '\n';
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
		int i = 0;
		do
		{
			// ignore caps on titles
			target = bookArray[i].bookTitle;
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
				cout << "RESULT: > " << bookArray[i].bookTitle << '\n';
				cout << "View this book record? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					bookInfo(bookArray[i].isbn, bookArray[i].bookTitle, bookArray[i].author, bookArray[i].publisher, bookArray[i].dateAdded, bookArray[i].qtyOnHand, bookArray[i].wholesale, bookArray[i].retail);
					cout << "Is this the book you want to DELETE? (Y/N): ";
					cin >> choice;
					break;
				}
			}

			// find user search in isbn
			foundIsbn = (bookArray[i].isbn).find(userSearch);
			if (foundIsbn != string::npos)
			{
				cout << "RESULT: > " << bookArray[i].isbn << '\n';
				cout << "View this book record? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					bookInfo(bookArray[i].isbn, bookArray[i].bookTitle, bookArray[i].author, bookArray[i].publisher, bookArray[i].dateAdded, bookArray[i].qtyOnHand, bookArray[i].wholesale, bookArray[i].retail);
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
			cout << '*' << setw(43) << "DATABASE SIZE:" << setw(3) << DBSIZE << setw(2) << ' '
					<< setw(20) << "CURRENT BOOK COUNT:" << setw(3) << bookCount << setw(7) << '*' << '\n';
			cout << '*' << setw(78) << '*' << '\n';
			cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
			cout << '\n';

			i++;
		} while (i < bookCount);		// end of database search

		// if search result is negative
		if(i == bookCount || (foundTitle == string::npos && foundIsbn == string::npos))
		{
			cout << setw(13) << "Book Not Found." << '\n';
			system("pause");
		}

		// delete book
		if (tolower(choice) == 'y')
		{
			removeBook(bookArray, bookCount, i);

			cout << "Book Deleted.\n";
			cout << "Delete Another? (Y/N): ";
			cin >> choice;
			cin.ignore();
		}
	} while (choice == 'y');
}

void repListing(BookData bookArray[], int bookCount)
{
	int currentPage = 1;
	double totalPage = ceil(double(bookCount)/10);

	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	int j = 0;
	for (int i = 0; i < int(totalPage); i++)
	{
		system("cls");
		cout << fixed << right;

		cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
		cout << setw(33) << "REPORT LISTING" << "\n";
		cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
				<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
				<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     DATABASE SIZE: " << DBSIZE
				<< "     CURRENT BOOK COUNT: " << bookCount
				<< "\n\n";

		cout << left << setw(30) << "TITLE"
				<< setw(1) << ' '
				<< setw(10) << "ISBN"
				<< setw(1) << ' '
				<< setw(7) << "QTY O/H"
				<< setw(1) << ' '
				<< setw(14) << "WHOLESALE COST"
				<< setw(1) << ' '
				<< setw(14) << "RETAIL COST"
				<< '\n';

		cout << setfill('-') << setw(30) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(10) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(7) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(14) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(14) << '-'
				<< setfill(' ') << '\n';

		while (j < bookCount)
		{
			cout << left << setw(30) << (bookArray[j].bookTitle).substr(0,30)
					<< setw(1) << ' '
					<< setw(10) << bookArray[j].isbn
					<< setw(1) << ' '
					<< right << setw(7) << bookArray[j].qtyOnHand
					<< setw(1) << ' '
					<< left << setw(1) << '$' << right << setw(13) << setprecision(2) << bookArray[j].wholesale << setprecision(0)
					<< setw(1) << ' '
					<< left << setw(1) << '$' << right << setw(13) << setprecision(2) << bookArray[j].retail << setprecision(0);
			cout << "\n\n";

			j++;
			if (j == bookCount)
			{
				break;
			}
			if (j % 10 == 0)
			{
				system("pause");
				break;
			}
		}
		currentPage++;
	}

	system("pause");
}

void repWholesale(BookData bookArray[], int bookCount)
{
	int currentPage = 1;
	double totalPage = ceil(double(bookCount)/10);
	double subtotal = 0.00;

	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	int j = 0;
	for (int i = 0; i < int(totalPage); i++)
	{
		system("cls");
		cout << fixed << right;

		cout << setw(33) << "SERENDIPITY  BOOKSELLERS" << "\n";
		cout << setw(33) << "REPORT WHOLESALE LISTING" << "\n";
		cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
				<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
				<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     DATABASE SIZE: " << DBSIZE
				<< "     CURRENT BOOK COUNT: " << bookCount
				<< "\n\n";

		cout << left << setw(30) << "TITLE"
				<< setw(5) << ' '
				<< setw(10) << "ISBN"
				<< setw(5) << ' '
				<< setw(7) << "QTY O/H"
				<< setw(5) << ' '
				<< setw(14) << "WHOLESALE COST"
				<< '\n';

		cout << setfill('-') << setw(30) << '-'
				<< setfill(' ') << setw(5) << ' '
				<< setfill('-') << setw(10) << '-'
				<< setfill(' ') << setw(5) << ' '
				<< setfill('-') << setw(7) << '-'
				<< setfill(' ') << setw(5) << ' '
				<< setfill('-') << setw(14) << '-'
				<< setfill(' ') << '\n';

		while (j < bookCount)
		{
			cout << left << setw(30) << (bookArray[j].bookTitle).substr(0,30)
					<< setw(5) << ' '
					<< setw(10) << bookArray[j].isbn
					<< setw(5) << ' '
					<< right << setw(7) << bookArray[j].qtyOnHand
					<< setw(5) << ' '
					<< left << setw(1) << '$' << right << setw(13) << setprecision(2) << bookArray[j].wholesale << setprecision(0);
			cout << "\n\n";

			subtotal += (bookArray[j].wholesale * bookArray[j].qtyOnHand);
			j++;
			if (j == bookCount)
			{
				break;
			}
			if (j % 10 == 0)
			{
				system("pause");
				break;
			}
		}
		currentPage++;
	}

	// total wholesale value
	cout << left << setw(62) << "Total Wholesale Value: "
			<< setw(1) << '$' << right << setw(13) << setprecision(2) << subtotal << setprecision(0)
			<< "\n\n";
	system("pause");
}

void repRetail(BookData bookArray[], int bookCount)
{
	int currentPage = 1;
	double totalPage = ceil(double(bookCount)/10);
	double subtotal = 0.00;

	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	int j = 0;
	for (int i = 0; i < int(totalPage); i++)
	{
		system("cls");
		cout << fixed << right;

		cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
		cout << setw(33) << "REPORT RETAIL LISTING" << "\n";
		cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
				<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
				<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     DATABASE SIZE: " << DBSIZE
				<< "     CURRENT BOOK COUNT: " << bookCount
				<< "\n\n";

		cout << left << setw(30) << "TITLE"
				<< setw(5) << ' '
				<< setw(10) << "ISBN"
				<< setw(5) << ' '
				<< setw(7) << "QTY O/H"
				<< setw(5) << ' '
				<< setw(14) << "RETAIL COST"
				<< '\n';

		cout << setfill('-') << setw(30) << '-'
				<< setfill(' ') << setw(5) << ' '
				<< setfill('-') << setw(10) << '-'
				<< setfill(' ') << setw(5) << ' '
				<< setfill('-') << setw(7) << '-'
				<< setfill(' ') << setw(5) << ' '
				<< setfill('-') << setw(14) << '-'
				<< setfill(' ') << '\n';

		while (j < bookCount)
		{
			cout << left << setw(30) << (bookArray[j].bookTitle).substr(0,30)
					<< setw(5) << ' '
					<< setw(10) << bookArray[j].isbn
					<< setw(5) << ' '
					<< right << setw(7) << bookArray[j].qtyOnHand
					<< setw(5) << ' '
					<< left << setw(1) << '$' << right << setw(13) << setprecision(2) << bookArray[j].retail << setprecision(0);
			cout << "\n\n";

			subtotal += (bookArray[j].retail * bookArray[j].qtyOnHand);
			j++;
			if (j == bookCount)
			{
				break;
			}
			if (j % 10 == 0)
			{
				system("pause");
				break;
			}
		}
		currentPage++;
	}

	// total wholesale value
	cout << left << setw(62) << "Total Retail Value: "
			<< setw(1) << '$' << right << setw(13) << setprecision(2) << subtotal << setprecision(0)
			<< "\n\n";
	system("pause");
}

void repQty(BookData bookArray[], int bookCount)
{
	BookData* orderQty;
	BookData temp[1];
	int min;
	int currentPage = 1;
	double totalPage = ceil(double(bookCount)/10);

	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	orderQty = new BookData[bookCount];
	// copy array
	for (int i = 0; i < bookCount; i++)
	{
		orderQty[i] = bookArray[i];
	}

	// sort
	for (int i = 0; i < bookCount - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < bookCount; j++)
		{
			if (orderQty[j].qtyOnHand < orderQty[min].qtyOnHand)
			{
				min = j;
			}
		}

		// swap
		temp[0] = orderQty[min];
		orderQty[min] = orderQty[i];
		orderQty[i] = temp[0];
	}

	int j = bookCount - 1;
	for (int i = 0; i < int(totalPage); i++)
	{
		system("cls");
		cout << fixed << right;

		cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
		cout << setw(33) << "REPORT COST LISTING" << "\n";
		cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
				<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
				<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     DATABASE SIZE: " << DBSIZE
				<< "     CURRENT BOOK COUNT: " << bookCount
				<< "\n\n";

		cout << left << setw(30) << "TITLE"
				<< setw(1) << ' '
				<< setw(10) << "ISBN"
				<< setw(1) << ' '
				<< setw(7) << "QTY O/H"
				<< '\n';

		cout << setfill('-') << setw(30) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(10) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(7) << '-'
				<< setfill(' ') << '\n';

		while (j >= 0)
		{
			cout << left << setw(30) << (orderQty[j].bookTitle).substr(0,30)
					<< setw(1) << ' '
					<< setw(10) << orderQty[j].isbn
					<< setw(1) << ' '
					<< right << setw(7) << orderQty[j].qtyOnHand;

			cout << "\n\n";

			j--;

			if (j < 0)
			{
				break;
			}
			if (j > 0 && j % 9 == 0 && j != 18)
			{
				system("pause");
				break;
			}
		}
		currentPage++;
	}

	system("pause");
	delete[] orderQty;
}

void repCost(BookData bookArray[], int bookCount)
{
	BookData* orderCost;
	BookData temp[1];
	int min;
	int currentPage = 1;
	double totalPage = ceil(double(bookCount)/10);

	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	orderCost = new BookData[bookCount];
	// copy array
	for (int i = 0; i < bookCount; i++)
	{
		orderCost[i] = bookArray[i];
	}

	// sort
	for (int i = 0; i < bookCount - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < bookCount; j++)
		{
			if (orderCost[j].wholesale < orderCost[min].wholesale)
			{
				min = j;
			}
		}

		// swap
		temp[0] = orderCost[min];
		orderCost[min] = orderCost[i];
		orderCost[i] = temp[0];
	}

	int j = bookCount - 1;
	for (int i = 0; i < int(totalPage); i++)
	{
		system("cls");
		cout << fixed << right;

		cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
		cout << setw(33) << "REPORT COST LISTING" << "\n";
		cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
				<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
				<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     DATABASE SIZE: " << DBSIZE
				<< "     CURRENT BOOK COUNT: " << bookCount
				<< "\n\n";

		cout << left << setw(30) << "TITLE"
				<< setw(1) << ' '
				<< setw(10) << "ISBN"
				<< setw(1) << ' '
				<< setw(7) << "QTY O/H"
				<< setw(1) << ' '
				<< setw(14) << "WHOLESALE COST"
				<< '\n';

		cout << setfill('-') << setw(30) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(10) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(7) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(14) << '-'
				<< setfill(' ') << '\n';

		while (j >= 0)
		{
			cout << left << setw(30) << (orderCost[j].bookTitle).substr(0,30)
					<< setw(1) << ' '
					<< setw(10) << orderCost[j].isbn
					<< setw(1) << ' '
					<< right << setw(7) << orderCost[j].qtyOnHand
					<< setw(1) << ' '
					<< left << setw(1) << '$' << right << setw(13) << setprecision(2) << orderCost[j].wholesale << setprecision(0);
					cout << "\n\n";

			j--;
			if (j < 0)
			{
				break;
			}
			if (j > 0 && j % 9 == 0 && j != 18)
			{
				system("pause");
				break;
			}
		}
		currentPage++;
	}

	system("pause");
	delete[] orderCost;
}

void repAge(BookData bookArray[], int bookCount)
{
	BookData* orderAge;
	BookData temp[1];

	int* dateArray;
	int tempDate;
	string day;
	string month;
	string year;
	string dateString;
	int min;
	int currentPage = 1;
	double totalPage = ceil(double(bookCount)/10);

	// current time
	time_t t = time(0);
	struct tm * now = localtime(&t);

	dateArray = new int[bookCount];
	orderAge = new BookData[bookCount];
	// copy array
	for (int i = 0; i < bookCount; i++)
	{
		orderAge[i] = bookArray[i];

		day = (orderAge[i].dateAdded).substr(0,2);
		month = (orderAge[i].dateAdded).substr(3,2);
		year = (orderAge[i].dateAdded).substr(6,4);

		dateString = year + month + day;
		dateArray[i] = atoi(dateString.c_str());
	}


	// sort
	for (int i = 0; i < bookCount; i++)
	{
		min = i;
		for (int j = i + 1; j < bookCount; j++)
		{
			if (dateArray[j] < dateArray[min])
			{
				min = j;
			}
		}

		// swap
		temp[0] = orderAge[min];
		tempDate = dateArray[min];

		orderAge[min] = orderAge[i];
		dateArray[min] = dateArray[i];

		orderAge[i] = temp[0];
		dateArray[i] = tempDate;
		cout << dateArray[i] << '\n';
	}
	system("pause");

	int j = bookCount - 1;
	for (int i = 0; i < int(totalPage); i++)
	{
		system("cls");
		cout << fixed << right;

		cout << setw(33) << "SERENDIPITY BOOKSELLERS" << "\n";
		cout << setw(33) << "REPORT COST LISTING" << "\n";
		cout << "DATE: " << setfill('0') << setw(2) << (now->tm_mon + 1)
				<< setw(1) << '/' << setw(2) << now->tm_mday << setw(1)
				<< '/' << setw(2) << (now->tm_year + 1900) << setfill(' ')
				<< "     PAGE: " << currentPage << " of " << totalPage
				<< "     DATABASE SIZE: " << DBSIZE
				<< "     CURRENT BOOK COUNT: " << bookCount
				<< "\n\n";

		cout << left << setw(30) << "TITLE"
				<< setw(1) << ' '
				<< setw(10) << "ISBN"
				<< setw(1) << ' '
				<< setw(7) << "QTY O/H"
				<< setw(1) << ' '
				<< setw(14) << "WHOLESALE COST"
				<< '\n';

		cout << setfill('-') << setw(30) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(10) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(7) << '-'
				<< setfill(' ') << setw(1) << ' '
				<< setfill('-') << setw(14) << '-'
				<< setfill(' ') << '\n';

		while (j >= 0)
		{
			cout << left << setw(30) << (orderAge[j].bookTitle).substr(0,30)
					<< setw(1) << ' '
					<< setw(10) << orderAge[j].isbn
					<< setw(1) << ' '
					<< right << setw(7) << orderAge[j].qtyOnHand
					<< setw(1) << ' '
					<< setw(10) << orderAge[j].dateAdded;
					cout << "\n\n";

			j--;
			if (j < 0)
			{
				break;
			}
			if (j > 0 && j % 9 == 0 && j != 18)
			{
				system("pause");
				break;
			}
		}
		currentPage++;
	}

	system("pause");
	delete[] orderAge;
	delete[] dateArray;
}

// setter functions
void setTitle(BookData bookArray[], int bookCount, string title)
{
	bookArray[bookCount].bookTitle = title;
}

void setIsbn(BookData bookArray[], int bookCount, string isbn)
{
	bookArray[bookCount].isbn = isbn;
}

void setAuthor(BookData bookArray[], int bookCount, string author)
{
	bookArray[bookCount].author = author;
}

void setPub(BookData bookArray[], int bookCount, string publisher)
{
	bookArray[bookCount].publisher = publisher;
}

void setDateAdded(BookData bookArray[], int bookCount, string date)
{
	bookArray[bookCount].dateAdded = date;
}

void setQty(BookData bookArray[], int bookCount, int qty)
{
	bookArray[bookCount].qtyOnHand = qty;
}

void setWholesale(BookData bookArray[], int bookCount, double wholesale)
{
	bookArray[bookCount].wholesale = wholesale;
}

void setRetail(BookData bookArray[], int bookCount, double retail)
{
	bookArray[bookCount].retail = retail;
}

void removeBook(BookData bookArray[], int& bookCount, int target)
{
	while (target < bookCount - 1)
	{
		// shift array
		bookArray[target].bookTitle = bookArray[target + 1].bookTitle;
		bookArray[target].isbn = bookArray[target + 1].isbn;
		bookArray[target].author = bookArray[target + 1].author;
		bookArray[target].publisher = bookArray[target + 1].publisher;
		bookArray[target].dateAdded = bookArray[target + 1].dateAdded;
		bookArray[target].qtyOnHand = bookArray[target + 1].qtyOnHand;
		bookArray[target].wholesale = bookArray[target + 1].wholesale;
		bookArray[target].retail = bookArray[target + 1].retail;
		target++;
	}

	// reset last empty element
	bookArray[bookCount - 1].bookTitle = "";
	bookArray[bookCount - 1].isbn = "";
	bookArray[bookCount - 1].author = "";
	bookArray[bookCount - 1].publisher = "";
	bookArray[bookCount - 1].dateAdded = "";
	bookArray[bookCount - 1].qtyOnHand = 0;
	bookArray[bookCount - 1].wholesale = 0;
	bookArray[bookCount - 1].retail = 0;

	bookCount--;
}
