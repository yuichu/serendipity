// ----------------------------------------------------------------------
// File name: mainmenu.cpp												-
// Project name: serendipity											-
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 01/16/2018											-
// Date of Last Modification: 02/11/2018								-
// ----------------------------------------------------------------------
// Purpose: Serendipity Bookstore's POS system							-
// ----------------------------------------------------------------------
// main() Algorithm:													-
// Step 1: Display main menu											-
// Step 2: Ask user to input choice at least once						-
// Step 3: Choice 1-3 executes the next menu function					-									-
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
// ----------------------------------------------------------------------
// -							DATA DICTIONARY							-
// - CONSTANTS															-
// -																	-
// - NAME					DATA TYPE				VALUE				-
// - --------------------   ----------				--------			-
// - SALES_TAX				const float				0.06
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
// - choice					char					\0 (NULL)			-
// ----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

const float SALES_TAX = 0.06;
const int DBSIZE = 20;

int cashier(string[], string[], string[], string[], string[], int[], double[], double[]);
int invMenu(string[], string[], string[], string[], string[], int[], double[], double[], int bookCount);
int bookInfo(string, string, string, string, string, int, double, double);
int reports(string[], string[], string[], string[], string[], int[], double[], double[]);
void lookUpBook(string[], string[], string[], string[], string[], int[], double[], double[]);
void addBook(string[], string[], string[], string[], string[], int[], double[], double[], int bookCount);
void editBook(string[], string[], string[], string[], string[], int[], double[], double[]);
void deleteBook(string[], string[], string[], string[], string[], int[], double[], double[]);
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

		cout << setw(60) << "Serendipity Booksellers\n"
				<< setw(55) << "Main Menu\n\n";

		cout << setw(53) << "1.  Cashier Module\n"
				<< setw(64) << "2.  Inventory Database Module\n"
				<< setw(52) << "3.  Report Module\n"
				<< setw(44) << "4.  Exit\n\n";

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
			cashier(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '2':
			invMenu(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '3':
			reports(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '4':
			cout << setw(44) << "Goodbye.\n";
			system("pause");
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
	string currentDate = "\0";
	int userQty = 0;
	string userIsbn = "\0";
	string userTitle = "\0";
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
		string date[], int qty[], double wholesale[], double retail[], int bookCount)
{
	char choice = '\0';

	do
	{
		system("cls");

		cout << setw(60) << "Serendipity Booksellers\n"
				<< setw(59) << "Inventory Database\n\n";

		cout << setw(53) << "1.  Look Up a Book\n"
				<< setw(49) << "2.  Add a Book\n"
				<< setw(59) << "3.  Edit a Book's Record\n"
				<< setw(52) << "4.  Delete a Book\n"
				<< setw(63) << "5.  Return to the Main Menu\n\n";

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
			lookUpBook(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '2':
			addBook(isbn, title, author, publisher, date, qty, wholesale, retail, bookCount);
			break;
		case '3':
			editBook(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '4':
			deleteBook(isbn, title, author, publisher, date, qty, wholesale, retail);
			break;
		case '5':
			cout << setw(61) << "Returning to Main Menu...\n";
			system("pause");
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
	system("cls");

	cout << setw(60) << "Serendipity Booksellers\n"
			<< setw(58) << "Book Information\n\n";

	cout << "ISBN: " << isbn
			<< "\nTitle: " << title
			<< "\nAuthor: " << author
			<< "\nPublisher: " << publisher
			<< "\nDate Added: " << date
			<< "\nQuantity-On-Hand: " << qty
			<< "\nWhoesale Cost: " << wholesale
			<< "\nRetail Price: " << retail
			<< '\n';

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
			cout << setw(61) << "Returning to Main Menu...\n";
			system("pause");
			break;
		default:
			cout << setw(78) << "Please enter a number in the range 1 - 7.\n\n";
			system("pause");
		}
	} while(choice != '7');

	return 0;
}

void lookUpBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Look Up Book.\n";
	system("pause");
}

void addBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[], int bookCount)
{
	cout << "You selected Add Book.\n";
	system("pause");
}

void editBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Edit Book.\n";
	system("pause");
}

void deleteBook(string isbn[], string title[], string author[], string publisher[],
		string date[], int qty[], double wholesale[], double retail[])
{
	cout << "You selected Delete Book.\n";
	system("pause");
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

