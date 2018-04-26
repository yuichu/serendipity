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
// - 
// - 
// - 
// ----------------------------------------------------------------------

#include "BookData.h"
#include "InventoryBook.h"
#include "SoldBook.h"

const float SALES_TAX = 0.06;
const int DBSIZE = 1;

int main()
{
	InventoryBook book[DBSIZE];
	SoldBook soldBook[DBSIZE];

	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;

	for (int i = 0; i < DBSIZE; i++)
	{
		cout << "Enter Book " << i + 1 << " Info" << "\n";

		// BookData
		cout << "Title: ";
		getline(cin, bookTitle);

		cout << "ISBN: ";
		getline(cin, isbn);

		cout << "Author: ";
		getline(cin, author);

		cout << "Publisher: ";
		getline(cin, publisher);

		// InventoryBook
		cout << "Date Added: ";
		getline(cin, dateAdded);

		cout << "Qty on Hand: ";
		cin >> qtyOnHand;

		cout << "Wholesale $";
		cin >> wholesale;

		cout << "Retail: $";
		cin >> retail;

		book[i] = {bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail};
		soldBook[i] = {bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, SALES_TAX, 5, 0};
		cout << "Book " << i + 1 << " Info has been added." << "\n\n";

		system("pause");
	}

	system("cls");

	for (int i = 0; i < DBSIZE; i++)
	{
		book[i].print();

		cout << "\n\n\n";

		soldBook[i].print();
	}

	system("pause");

	return 0;
}
