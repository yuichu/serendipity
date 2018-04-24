#include "InventoryBook.h"

//															CONSTRUCTORS
//----------------------------------------------------------------------
// Function: InventoryBook()
// default constructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
InventoryBook::InventoryBook()
{
	setDateAdded("Not Set");
	setQty(0);
	setWholesale(0.0);
	setRetail(0.0);
}

//----------------------------------------------------------------------
// Function: InventoryBook()
// overload constructor
// Receives: string bookTitle, string isbn, string author, string publisher,
//			string dateAdded, int qtyOnHand, double wholesale, double retail
// Returns: none
//----------------------------------------------------------------------
InventoryBook::InventoryBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail)
:BookData(bookTitle, isbn, author, publisher)
{
	setDateAdded(dateAdded);
	setQty(qtyOnHand);
	setWholesale(wholesale);
	setRetail(retail);
}


//----------------------------------------------------------------------
// Function: ~InventoryBook()
// deconstructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
InventoryBook::~InventoryBook(){}


//																PRINT
//----------------------------------------------------------------------
// Function: print()
// print book info
// Receives: none
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::print()
{
	cout << "Inventory Data: "
			<< "------------------------------------" << "\n";
	BookData::print();
	cout << getDateAdded() << "\n"
			<< getQty() << "\n"
			<< getWholesale() << "\n"
			<< getRetail() << "\n";
}

//																SETTERS
//----------------------------------------------------------------------
// Function: setDateAdded()
// set date book was added to POS system
// Receives: string dateAdded
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::setDateAdded(string dateAdded)
{
	this->dateAdded = dateAdded;
}

//----------------------------------------------------------------------
// Function: setQty()
// set quantity of book on hand
// Receives: int qtyOnHand
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::setQty(int qtyOnHand)
{
	this->qtyOnHand = qtyOnHand;
}

//----------------------------------------------------------------------
// Function: setWholesale()
// set wholesale price of books
// Receives: double wholesale
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::setWholesale(double wholesale)
{
	this->wholesale = wholesale;
}

//----------------------------------------------------------------------
// Function: setRetail()
// set retail price of book
// Receives: double retail
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::setRetail(double retail)
{
	this->retail = retail;
}

//																GETTERS
//----------------------------------------------------------------------
// Function: getDateAdded()
// get date book was added to system
// Receives: none
// Returns: string dateAdded
//----------------------------------------------------------------------
string InventoryBook::getDateAdded()
{
	return dateAdded;
}

//----------------------------------------------------------------------
// Function: getQty()
// get qty of book on hand
// Receives: none
// Returns: int qtyOnHand
//----------------------------------------------------------------------
int InventoryBook::getQty()
{
	return qtyOnHand;
}

//----------------------------------------------------------------------
// Function: getWholesale()
// get wholesale price of book
// Receives: none
// Returns: double wholesale
//----------------------------------------------------------------------
double InventoryBook::getWholesale()
{
	return wholesale;
}

//----------------------------------------------------------------------
// Function: getRetail()
// get retail price of book
// Receives: none
// Returns: double retail
//----------------------------------------------------------------------
double InventoryBook::getRetail()
{
	return retail;
}

//----------------------------------------------------------------------
// Function: removeBook()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
//void InventoryBook::removeBook()
//{
//
//}

//----------------------------------------------------------------------
// Function: isEmpty()
//
// Receives:
// Returns:
//----------------------------------------------------------------------
//bool InventoryBook::isEmpty()
//{
//
//}
