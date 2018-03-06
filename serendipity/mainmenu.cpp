// ----------------------------------------------------------------------
// File name: mainmenu.cpp												-
// Project name: serendipity											-
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 01/16/2018											-
// Date of Last Modification: 03/06/2018								-
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
// cashier() Algorithm:													-
// Step 4: Ask user to input date										-
// Step 5: Ask user to input book quantity								-
//		if invalid input, ask user to re-enter							-
// Step 6: Ask user to input ISBN										-
// Step 7: Ask user to input book title									-
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
//																		-
// - VARIABLES															-
// -																	-
// - NAME					DATA TYPE				INITIAL VALUE		-
// - --------------------   ----------				-------------		-
// - title					string[]									-
// - isbn					string[]									-
// - author					string[]									-
// - publisher				string[]									-
// - date					string[]									-
// - qty					int[]					{0}					-
// - wholesale				double[]				{0}					-
// - retail					double[]				{0}					-
// - choice					char					\0					-
// - bookCount				int						0					-
// - userSearch				string										-
// - target					string										-
// - foundTitle				size_t										-
// - foundIsbn				size_t										-
// ----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

const float SALES_TAX = 0.06;
const int DBSIZE = 20;

int cashier(string[], string[], string[], string[], string[], int[], double[], double[]);
int invMenu(string[], string[], string[], string[], string[], int[], double[], double[], int& bookCount);
int bookInfo(string, string, string, string, string, int, double, double);
int reports(string[], string[], string[], string[], string[], int[], double[], double[]);
void lookUpBook(string[], string[], string[], string[], string[], int[], double[], double[], int& bookCount);
void addBook(string[], string[], string[], string[], string[], int[], double[], double[], int& bookCount);
void editBook(string[], string[], string[], string[], string[], int[], double[], double[], int& bookCount);
void deleteBook(string[], string[], string[], string[], string[], int[], double[], double[], int& bookCount);
void repListing(string[], string[], string[], string[], string[], int[], double[], double[]);
void repWholesale(string[], string[], string[], string[], string[], int[], double[], double[]);
void repRetail(string[], string[], string[], string[], string[], int[], double[], double[]);
void repQty(string[], string[], string[], string[], string[], int[], double[], double[]);
void repCost(string[], string[], string[], string[], string[], int[], double[], double[]);
void repAge(string[], string[], string[], string[], string[], int[], double[], double[]);

int main()
{
	string title[DBSIZE];
	string isbn[DBSIZE];
	string author[DBSIZE];
	string publisher[DBSIZE];
	string date[DBSIZE];
	int qty[DBSIZE] = {0};
	double wholesale[DBSIZE] = {0};
	double retail[DBSIZE] = {0};
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
			cashier(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '2':
			invMenu(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '3':
			reports(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '4':
			break;
		default:
			cout << setw(78) << "Please enter a number in the range 1 - 4.\n\n";
			system("pause");
		}

	} while (choice != '4');

	return 0;
}

int cashier(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	string currentDate = "";
	int userQty = 0;
	string userIsbn = "";
	string userTitle = "";
	float unitPrice = 0.00;
	float subtotal = 0.00;
	char choice = '\0';

	do
	{
		system("cls");

		// Cashier Module
		cout << "Serendipity Booksellers\n"
				<< setw(17) << "Cashier Module\n\n";

		cout << "Date (MM/DD/YY): ";
		cin >> currentDate;


		cout << "Quantity of Book: ";
		cin >> userQty;
		while (cin.fail())
		{
			cout << "Wrong input, please re-enter quantity: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> userQty;
			if (!cin.fail())
			{
				break;
			}
		}

		cout << "ISBN: ";
		cin >> userIsbn;

		cout << "Title: ";
		cin.ignore();
		getline(cin, userTitle);

		cout << "Price: ";
		cin >> unitPrice;
		while (cin.fail())
		{
			cout << "Wrong input, please re-enter price: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> unitPrice;
			if (!cin.fail())
			{
				break;
			}
		}

		subtotal = unitPrice*float(userQty);

		cout << "\n\nLoading...\n";
		system("pause");
		system("cls");


		// Sales Slip
		cout << "Serendipity Book Sellers\n\n";
		cout << "Date: " << date << "\n\n";

		cout << left
				<< setw(5) << "Qty"
				<< setw(15) << "ISBN"
				<< setw(25) << "Title"
				<< setw(12) << "Price"
				<< "Total\n";

		cout << "__________________________________________________________________\n";

		cout << setw(5) << userQty
				<< setw(15) << userIsbn
				<< setw(25) << userTitle
				<< fixed << setprecision(2)
				<< setw(1) << "$" << setw(11) << unitPrice
				<< setw(1) << "$" << right << setw(6) << subtotal;


		cout << left << setw(16) << "\n\n\n" << setw(44) << "Subtotal" << "$" << right << setw(6) << subtotal
				<< left << setw(14) << "\n" << setw(44) << "Tax" << "$" << right << setw(6) << subtotal*SALES_TAX
				<< left << setw(14) << "\n" << setw(44) << "Total" << "$" << right << setw(6) << (subtotal*SALES_TAX) + subtotal << "\n";

		cout << "\nThank you for Shopping at Serendipity!\n\n";

		cout << "Process another transaction (Y/N)?: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (tolower(choice) != 'y' && tolower(choice) != 'n')
		{
			cout << "Invalid selection, please enter \'Y\' or \'N\'.\n\n";

			cout << "Process another transaction (Y/N)?: ";
			cin >> choice;
		}

	} while (tolower(choice) == 'y');

	return 0;
}

int invMenu(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[], int& bookCount)
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
			lookUpBook(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '2':
			addBook(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '3':
			editBook(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '4':
			deleteBook(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '5':
			break;
		default:
			cout << setw(78) << "Please enter a number in the range 1 - 5.\n\n";
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

int reports(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
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
			repListing(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '2':
			repWholesale(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '3':
			repRetail(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '4':
			repQty(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '5':
			repCost(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '6':
			repAge(isbn, title, author, publisher, date, qty, wholesale, retail);
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

void lookUpBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[], int& bookCount)
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
		target = title[i];
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
			cout << "RESULT: > " << title[i] << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				bookInfo(isbn[i], title[i], author[i], publisher[i], date[i], qty[i], wholesale[i], retail[i]);
				break;
			}
		}

		// find ISBN from partial search term
		foundIsbn = isbn[i].find(userSearch);
		if (foundIsbn != string::npos)
		{
			cout << "RESULT: > " << isbn[i] << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				bookInfo(isbn[i], title[i], author[i], publisher[i], date[i], qty[i], wholesale[i], retail[i]);
				break;
			}
		}

		system("cls");

		// Display Menu
		cout << setfill('*') << setw(79) << '*' << setfill(' ') << '\n';
		cout << '*' << setw(50) << "SERENDIPITY BOOKSELLERS" << setw(28) << '*' << '\n';
		cout << '*' << setw(53) << "INVENTORY MENU" << setw(25) << '*' << '\n';
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

void addBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[], int& bookCount)
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
			title[bookCount] = tempTitle;
			isbn[bookCount] = tempIsbn;
			author[bookCount] = tempAuthor;
			publisher[bookCount] = tempPublisher;
			date[bookCount] = tempDate;
			qty[bookCount] = tempQty;
			wholesale[bookCount] = tempWholesale;
			retail[bookCount] = tempRetail;
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

void editBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[], int& bookCount)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundTitle;
	size_t foundIsbn;


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
		target = title[i];
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
			cout << "RESULT: > " << title[i] << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				bookInfo(isbn[i], title[i], author[i], publisher[i], date[i], qty[i], wholesale[i], retail[i]);
				cout << "Is this the book you want to EDIT? (Y/N): ";
				cin >> choice;

				break;
			}
		}

		foundIsbn = isbn[i].find(userSearch);
		if (foundIsbn != string::npos)
		{
			cout << "RESULT: > " << isbn[i] << '\n';
			cout << "View this book record? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				bookInfo(isbn[i], title[i], author[i], publisher[i], date[i], qty[i], wholesale[i], retail[i]);
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
			cout << setw(2) << '*' << setw(6) << "<1>" << setw(29) << "Edit Book Title" << setw(3) << '>' << "--" << setw(36) << title[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<2>" << setw(29) << "Edit ISBN" << setw(3) << '>' << "--" << setw(36) << isbn[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<3>" << setw(29) << "Edit Author" << setw(3) << '>' << "--" << setw(36) << author[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<4>" << setw(29) << "Edit Publisher" << setw(3) << '>' << "--" << setw(36) << publisher[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<5>" << setw(29) << "Edit Date Added (mm/dd/yyyy)" << setw(3) << '>' << "--" << setw(36) << date[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<6>" << setw(29) << "Edit Quantity on Hand" << setw(3) << '>' << "--" << setw(36) << qty[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<7>" << setw(29) << "Edit Wholesale Cost" << setw(3) << '>' << "--" << setprecision(2) << '$' << setw(35) << wholesale[i] << '*' << '\n';
			cout << setw(2) << '*' << setw(6) << "<8>" << setw(29) << "Edit Retail Price" << setw(3) << '>' << "--" << '$' << setw(35) << retail[i] << setprecision(0) << '*' << '\n';
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
				getline(cin, title[i]);
				break;
			case '2':
				cout << setw(23) << "ISBN > ";
				cin >> isbn[i];
				break;
			case '3':
				cout << setw(23) << "Author > ";
				getline(cin, author[i]);
				break;
			case '4':
				cout << setw(23) << "Publisher > ";
				getline(cin, publisher[i]);
				break;
			case '5':
				cout << setw(23) << "Date > ";
				cin >> date[i];
				break;
			case '6':
				cout << setw(23) << "Quantity > ";
				cin >> qty[i];
				while (cin.fail())
				{
					cout << setw(52) << "Wrong input, please re-enter." << '\n'
							<< setw(23) << "Quantity > ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> qty[i];
				}
				break;
			case '7':
				cout << setw(23) << "Wholesale Price > ";
				cin >> wholesale[i];
				while (cin.fail())
				{
					cout << setw(52) << "Wrong input, please re-enter." << '\n'
							<< setw(23) << "Wholesale Price > ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> wholesale[i];
				}
				break;
			case '8':
				cout << setw(23) << "Retail Price > ";
				cin >> retail[i];
				while (cin.fail())
				{
					cout << setw(52) << "Wrong input, please re-enter." << '\n'
							<< setw(23) << "Retail Price > ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> retail[i];
				}
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

void deleteBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[], int& bookCount)
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
			target = title[i];
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
				cout << "RESULT: > " << title[i] << '\n';
				cout << "View this book record? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					bookInfo(isbn[i], title[i], author[i], publisher[i], date[i], qty[i], wholesale[i], retail[i]);
					cout << "Is this the book you want to DELETE? (Y/N): ";
					cin >> choice;
					break;
				}
			}

			// find user search in isbn
			foundIsbn = isbn[i].find(userSearch);
			if (foundIsbn != string::npos)
			{
				cout << "RESULT: > " << isbn[i] << '\n';
				cout << "View this book record? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					bookInfo(isbn[i], title[i], author[i], publisher[i], date[i], qty[i], wholesale[i], retail[i]);
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
			while (i < bookCount - 1)
			{
				// shift array
				title[i] = title[i + 1];
				isbn[i] = isbn[i + 1];
				author[i] = author[i + 1];
				publisher[i] = publisher[i + 1];
				date[i] = date[i + 1];
				qty[i] = qty[i + 1];
				wholesale[i] = wholesale[i + 1];
				retail[i] = retail[i + 1];
				i++;
			}

			// reset last empty element
			title[bookCount - 1] = "";
			isbn[bookCount - 1] = "";
			author[bookCount - 1] = "";
			publisher[bookCount - 1] = "";
			date[bookCount - 1] = "";
			qty[bookCount - 1] = 0;
			wholesale[bookCount - 1] = 0;
			retail[bookCount - 1] = 0;
			bookCount--;

			cout << "Book Deleted.\n";
			cout << "Delete Another? (Y/N): ";
			cin >> choice;
			cin.ignore();
		}
	} while (choice == 'y');
}

void repListing(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Inventory Listing.\n";
	system("pause");
}

void repWholesale(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Inventory Wholesale Value.\n";
	system("pause");
}

void repRetail(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Inventory Retail Value.\n";
	system("pause");
}

void repQty(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Listing By Quantity.\n";
	system("pause");
}

void repCost(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Listing By Cost.\n";
	system("pause");
}

void repAge(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Listing by Age.\n";
	system("pause");
}

