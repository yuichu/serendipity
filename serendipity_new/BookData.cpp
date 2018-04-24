#include "BookData.h"

//															CONSTRUCTORS
//----------------------------------------------------------------------
// Function: BookData()
// default constructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
BookData::BookData()
{
	setTitle("Not Set");
	setIsbn("Not Set");
	setAuthor("Not Set");
	setPub("Not Set");
	setDateAdded("Not Set");
	setQty(0);
	setWholesale(0.0);
	setRetail(0.0);
}

//----------------------------------------------------------------------
// Function: BookData()
// overload constructor
// Receives: string bookTitle, string isbn, string author, string publisher,
//			string dateAdded, int qtyOnHand, double wholesale, double retail
// Returns: none
//----------------------------------------------------------------------
BookData::BookData(string bookTitle, string isbn, string author, string publisher,
		string dateAdded, int qtyOnHand, double wholesale, double retail)
{
	setTitle(bookTitle);
	setIsbn(isbn);
	setAuthor(author);
	setPub(publisher);
	setDateAdded(dateAdded);
	setQty(qtyOnHand);
	setWholesale(wholesale);
	setRetail(retail);
}


//----------------------------------------------------------------------
// Function: ~BookData()
// deconstructor
// Receives: none
// Returns: none
//----------------------------------------------------------------------
BookData::~BookData(){}


//																PRINT
//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------


//																SETTERS
//----------------------------------------------------------------------
// Function: setTitle()
// set book title
// Receives: string bookTitle
// Returns: none
//----------------------------------------------------------------------
void BookData::setTitle(string bookTitle)
{
	this->bookTitle = bookTitle;
}

//----------------------------------------------------------------------
// Function: setIsbn()
// set book ISBN
// Receives: string isbn
// Returns: none
//----------------------------------------------------------------------
void BookData::setIsbn(string isbn)
{
	this->isbn = isbn;
}

//----------------------------------------------------------------------
// Function: setAuthor()
// set book author
// Receives: string author
// Returns: none
//----------------------------------------------------------------------
void BookData::setAuthor(string author)
{
	this->author = author;
}

//----------------------------------------------------------------------
// Function: setPub()
// set book publisher
// Receives: string publisher
// Returns: none
//----------------------------------------------------------------------
void BookData::setPub(string publisher)
{
	this->publisher = publisher;
}

//----------------------------------------------------------------------
// Function: setDateAdded()
// set date book was added to POS system
// Receives: string dateAdded
// Returns: none
//----------------------------------------------------------------------
void BookData::setDateAdded(string dateAdded)
{
	this->dateAdded = dateAdded;
}

//----------------------------------------------------------------------
// Function: setQty()
// set quantity of book on hand
// Receives: int qtyOnHand
// Returns: none
//----------------------------------------------------------------------
void BookData::setQty(int qtyOnHand)
{
	this->qtyOnHand = qtyOnHand;
}

//----------------------------------------------------------------------
// Function: setWholesale()
// set wholesale price of book
// Receives: double wholesale
// Returns: none
//----------------------------------------------------------------------
void BookData::setWholesale(double wholesale)
{
	this->wholesale = wholesale;
}

//----------------------------------------------------------------------
// Function: setRetail()
// set retail price of book
// Receives: double retail
// Returns: none
//----------------------------------------------------------------------
void BookData::setRetail(double retail)
{
	this->retail = retail;
}

//																GETTERS
//----------------------------------------------------------------------
// Function: getTitle()
// get book title
// Receives: none
// Returns: string bookTitle
//----------------------------------------------------------------------
string BookData::getTitle()
{
	return bookTitle;
}

//----------------------------------------------------------------------
// Function: getIsbn()
// get book ISBN
// Receives: none
// Returns: string isbn
//----------------------------------------------------------------------
string BookData::getIsbn()
{
	return isbn;
}

//----------------------------------------------------------------------
// Function: getAuthor()
// get book author
// Receives: none
// Returns: string author
//----------------------------------------------------------------------
string BookData::getAuthor()
{
	return author;
}

//----------------------------------------------------------------------
// Function: getPub()
// get book publisher
// Receives: none
// Returns: string publisher
//----------------------------------------------------------------------
string BookData::getPub()
{
	return publisher;
}

//----------------------------------------------------------------------
// Function: getDateAdded()
// get date book was added to system
// Receives: none
// Returns: string dateAdded
//----------------------------------------------------------------------
string BookData::getDateAdded()
{
	return dateAdded;
}

//----------------------------------------------------------------------
// Function: getQty()
// get qty of book on hand
// Receives: none
// Returns: int qtyOnHand
//----------------------------------------------------------------------
int BookData::getQty()
{
	return qtyOnHand;
}

//----------------------------------------------------------------------
// Function: getWholesale()
// get wholesale price of book
// Receives: none
// Returns: double wholesale
//----------------------------------------------------------------------
double BookData::getWholesale()
{
	return wholesale;
}

//----------------------------------------------------------------------
// Function: getRetail()
// get retail price of book
// Receives: none
// Returns: double retail
//----------------------------------------------------------------------
double BookData::getRetail()
{
	return retail;
}
