#ifndef INVENTORYBOOK_H_
#define INVENTORYBOOK_H_

#include "BookData.h"
#include <iomanip>

class InventoryBook: public BookData
{
public:
	InventoryBook();
	InventoryBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail);
	~InventoryBook();

	void print();

	void setDateAdded(string dateAdded);
	void setQty(int qty);
	void setWholesale(double wholesale);
	void setRetail(double retail);

	string getDateAdded() const;
	int getQty() const;
	double getWholesale() const;
	double getRetail() const;

//	void removeBook();
//	bool isEmpty();

private:
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
};

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
	cout << "Inventory Data: " << "\n"
			<< "------------------------------------" << "\n";
	BookData::print();
	cout << "Date Added: " << getDateAdded() << "\n"
			<< "Quantity: " << getQty() << "\n"
			<< fixed << setprecision(2)
			<< "Wholesale: $" << getWholesale() << "\n"
			<< "Retail: $" << getRetail() << "\n"
			<< setprecision(0);
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
string InventoryBook::getDateAdded() const
{
	return dateAdded;
}

//----------------------------------------------------------------------
// Function: getQty()
// get qty of book on hand
// Receives: none
// Returns: int qtyOnHand
//----------------------------------------------------------------------
int InventoryBook::getQty() const
{
	return qtyOnHand;
}

//----------------------------------------------------------------------
// Function: getWholesale()
// get wholesale price of book
// Receives: none
// Returns: double wholesale
//----------------------------------------------------------------------
double InventoryBook::getWholesale() const
{
	return wholesale;
}

//----------------------------------------------------------------------
// Function: getRetail()
// get retail price of book
// Receives: none
// Returns: double retail
//----------------------------------------------------------------------
double InventoryBook::getRetail() const
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


#endif /* INVENTORYBOOK_H_ */
