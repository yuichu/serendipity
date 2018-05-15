#ifndef BOOKDATA_H_
#define BOOKDATA_H_

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

class BookData
{
public:
	BookData();
	BookData(string bookTitle, string isbn, string author, string publisher);
	~BookData(void); // @suppress("Class has a virtual method and non-virtual destructor")

	virtual void print();

	void setTitle(string bookTitle);
	void setIsbn(string isbn);
	void setAuthor(string author);
	void setPub(string pubilsher);

	string getTitle() const;
	string getIsbn() const;
	string getAuthor() const;
	string getPub() const;

	void removeBook();

	bool operator>=(const BookData& other_Book) const;
	bool operator==(const BookData& other_Book) const;
	bool operator!=(const BookData& other_Book) const;

	friend ostream& operator<< (ostream& osObject, const BookData& c)
	{
		osObject << left << setfill(' ')<< " " << setw(29) << c.bookTitle.substr (0,28)
			<< setw(11) << c.isbn << setw(15) << c.author.substr(0,14)
			<< setw(11) << c.publisher.substr (0,14) << endl;

		return osObject;
	}

private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;

};

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


//														OVERLOAD OPERATOR
//----------------------------------------------------------------------
bool BookData::operator>=(const BookData& other_Book) const
{
	bool found = false;

	// default
	if (this != &other_Book)
	{
		if((strcmp(this->isbn.c_str(), other_Book.isbn.c_str())) >= 0)
		{
			found = true;
		}
	}

	return found;
}

//----------------------------------------------------------------------
bool BookData::operator==(const BookData& other_Book) const
{
	bool found = false;

	if (this != &other_Book)
	{
		if ((strcmp(this->isbn.c_str(), other_Book.isbn.c_str())) == 0)
		{
			found = true;
		}

	}

	return found;
}

//----------------------------------------------------------------------
bool BookData::operator!=(const BookData& other_Book) const
{
	bool found = false;

	if (this != &other_Book)
	{
		if ((strcmp(this->isbn.c_str(), other_Book.isbn.c_str())) == 0)
		{
			found = true;
		}
	}

	return !found;
}

//----------------------------------------------------------------------

#endif /* BOOKDATA_H_ */
