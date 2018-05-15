#ifndef SOLDBOOK_H_
#define SOLDBOOK_H_

#include "InventoryBook.h"

class SoldBook: public InventoryBook
{
public:
	SoldBook();
	SoldBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail, int sortCode, double taxRate, int qtySold, double tax);
	~SoldBook(); // @suppress("Class has a virtual method and non-virtual destructor")

	void print();

	void setTaxRate(double taxRate);
	void setQtySold(int qtySold);
	void setTax(double retail, int qtySold);

	double getTaxRate() const;
	int getQtySold() const;
	double getTax() const;

private:
	double taxRate;
	int qtySold;
	double tax;
	double subTotal;
	double total;
};

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
	setTax(0.0, 0);
}

//----------------------------------------------------------------------
// Function: SoldBook()
// overload constructor
// Receives: string bookTitle, string isbn, string author, string publisher,
//			string dateAdded, int qtyOnHand, double wholesale, double retail,
//			double taxRate, int qtySold, double tax
// Returns: none
//----------------------------------------------------------------------
SoldBook::SoldBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail, int sortCode, double taxRate, int qtySold, double tax)
:InventoryBook(bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, sortCode)
{
	setTaxRate(taxRate);
	setQtySold(qtySold);
	setTax(retail, qtySold);
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
void SoldBook::setTax(double retail, int qtySold)
{
	this->tax = retail * qtySold * this->getTaxRate();

}

//																GETTERS
//----------------------------------------------------------------------
// Function: getTaxRate()
// get tax rate
// Receives: none
// Returns: double taxRate
//----------------------------------------------------------------------
double SoldBook::getTaxRate() const
{
	return taxRate;
}

//----------------------------------------------------------------------
// Function: getQtySold()
// get quantity of book sold
// Receives: none
// Returns: int qtySold
//----------------------------------------------------------------------
int SoldBook::getQtySold() const
{
	return qtySold;
}

//----------------------------------------------------------------------
// Function: getTax()
// get tax
// Receives: none
// Returns: double tax
//----------------------------------------------------------------------
double SoldBook::getTax() const
{
	return tax;
}

#endif /* SOLDBOOK_H_ */
