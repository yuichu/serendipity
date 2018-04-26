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
}

//----------------------------------------------------------------------
// Function: BookData()
// overload constructor
// Receives: string bookTitle, string isbn, string author, string publisher,
//			string dateAdded, int qtyOnHand, double wholesale, double retail
// Returns: none
//----------------------------------------------------------------------
BookData::BookData(string bookTitle, string isbn, string author, string publisher)
{
	setTitle(bookTitle);
	setIsbn(isbn);
	setAuthor(author);
	setPub(publisher);
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
// Function: print()
// print book info
// Receives: none
// Returns: none
//----------------------------------------------------------------------
void BookData::print()
{
	cout << "Title: " << getTitle() << "\n"
			<< "ISBN: " << getIsbn() << "\n"
			<< "Author: " << getAuthor() << "\n"
			<< "Publisher: " << getPub() << "\n";
}

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

//																GETTERS
//----------------------------------------------------------------------
// Function: getTitle()
// get book title
// Receives: none
// Returns: string bookTitle
//----------------------------------------------------------------------
string BookData::getTitle() const
{
	return bookTitle;
}

//----------------------------------------------------------------------
// Function: getIsbn()
// get book ISBN
// Receives: none
// Returns: string isbn
//----------------------------------------------------------------------
string BookData::getIsbn() const
{
	return isbn;
}

//----------------------------------------------------------------------
// Function: getAuthor()
// get book author
// Receives: none
// Returns: string author
//----------------------------------------------------------------------
string BookData::getAuthor() const
{
	return author;
}

//----------------------------------------------------------------------
// Function: getPub()
// get book publisher
// Receives: none
// Returns: string publisher
//----------------------------------------------------------------------
string BookData::getPub() const
{
	return publisher;
}
