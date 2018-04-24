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

}

//----------------------------------------------------------------------
// Function: SoldBook()
// overload constructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
SoldBook::SoldBook()
{

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
