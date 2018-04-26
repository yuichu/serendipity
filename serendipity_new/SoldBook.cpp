#include "SoldBook.h"

//															CONSTRUCTORS
//----------------------------------------------------------------------
// Function: SoldBook()
// default constructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
SoldBook::SoldBook()
{
	setTaxRate(0.06);
	setQtySold(0);
	setTax(0.0);
}

//----------------------------------------------------------------------
// Function: SoldBook()
// overload constructor
// Receives: string bookTitle, string isbn, string author, string publisher,
//			string dateAdded, int qtyOnHand, double wholesale, double retail,
//			double taxRate, int qtySold, double tax
// Returns: none
//----------------------------------------------------------------------
SoldBook::SoldBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail, double taxRate, int qtySold, double tax)
:InventoryBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail)
{
	setTaxRate(taxRate);
	setQtySold(qtySold);
	tax = retail*qtySold*taxRate;
	setTax(tax);
}

//----------------------------------------------------------------------
// Function: ~SoldBook()
// deconstructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
SoldBook::~SoldBook(){}


//																PRINT
//----------------------------------------------------------------------
// Function: print()
// print book info
// Receives: none
// Returns: none
//----------------------------------------------------------------------
void SoldBook::print()
{
	InventoryBook::print();
	cout << "Sold Book Data: " << "\n"
			<< "------------------------------------" << "\n";
	cout << fixed << setprecision(2)
			<< "Tax Rate: $" << getTaxRate() << "\n"
			<< setprecision(0)
			<< "Quantity Sold: " << getQtySold() << "\n"
			<< setprecision(2)
			<< "Tax: $" << getTax() << "\n"
			<< setprecision(0);
}

//																SETTERS
//----------------------------------------------------------------------
// Function: setTaxRate()
//
// Receives: double taxRate
// Returns: none
//----------------------------------------------------------------------
void SoldBook::setTaxRate(double taxRate)
{
	this->taxRate = taxRate;
}

//----------------------------------------------------------------------
// Function: setQtySold()
//
// Receives: int qtySold
// Returns: none
//----------------------------------------------------------------------
void SoldBook::setQtySold(int qtySold)
{
	this->qtySold = qtySold;
}

//----------------------------------------------------------------------
// Function: setTax()
//
// Receives: double tax
// Returns: none
//----------------------------------------------------------------------
void SoldBook::setTax(double tax)
{
	this->tax = tax;
}

//																GETTERS
//----------------------------------------------------------------------
// Function: getTaxRate()
// get tax rate
// Receives: none
// Returns: double taxRate
//----------------------------------------------------------------------
const double SoldBook::getTaxRate()
{
	return taxRate;
}

//----------------------------------------------------------------------
// Function: getQtySold()
// get quantity of book sold
// Receives: none
// Returns: int qtySold
//----------------------------------------------------------------------
const int SoldBook::getQtySold()
{
	return qtySold;
}

//----------------------------------------------------------------------
// Function: getTax()
// get tax
// Receives: none
// Returns: double tax
//----------------------------------------------------------------------
const double SoldBook::getTax()
{
	return tax;
}
