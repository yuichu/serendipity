#ifndef INVENTORYBOOK_H_
#define INVENTORYBOOK_H_

#include "BookData.h"
#include <iomanip>
#include <cstring>
#include <cstdlib>

class InventoryBook: public BookData
{
public:
	InventoryBook();
	InventoryBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail, int sortCode);
	~InventoryBook(); // @suppress("Class has a virtual method and non-virtual destructor")

	void print();
	void printRetail();

	void setDateAdded(string dateAdded);
	void setQty(int qty);
	void setWholesale(double wholesale);
	void setRetail(double retail);
	void setSortCode(int sortCode);

	string getDateAdded() const;
	int getQty() const;
	double getWholesale() const;
	double getRetail() const;
	int getSortCode() const;

	bool operator>=(const InventoryBook& other_Book) const;
	bool operator==(const InventoryBook& other_Book) const;
	bool operator!=(const InventoryBook& other_Book) const;

//	void removeBook();
//	bool isEmpty();

private:
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
	int sortCode;	// 0 = title, 1 = QTY, 2 = wholesale, 3 = date
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
	setSortCode(0);
}

//----------------------------------------------------------------------
// Function: InventoryBook()
// overload constructor
// Receives: string bookTitle, string isbn, string author, string publisher,
//			string dateAdded, int qtyOnHand, double wholesale, double retail
// Returns: none
//----------------------------------------------------------------------
InventoryBook::InventoryBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail, int sortCode)
:BookData(bookTitle, isbn, author, publisher)
{
	setDateAdded(dateAdded);
	setQty(qtyOnHand);
	setWholesale(wholesale);
	setRetail(retail);
	setSortCode(sortCode);
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

//----------------------------------------------------------------------
// Function: printRetail()
// print book info
// Receives: none
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::printRetail()
{
	cout << "Inventory Data: " << "\n"
			<< "------------------------------------" << "\n";
	BookData::print();
	cout << "Date Added: " << getDateAdded() << "\n"
			<< "Quantity: " << getQty() << "\n"
			<< fixed << setprecision(2)
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

//----------------------------------------------------------------------
// Function: setSortCode()
// set sort code for nodes for proper linked list ordering
// Receives: int sortCode
// Returns: none
//----------------------------------------------------------------------
void InventoryBook::setSortCode(int sortCode)
{
	this->sortCode = sortCode;
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
// Function: getSortCode()
// get sort code
// Receives: none
// Returns: int sortCode
//----------------------------------------------------------------------
int InventoryBook::getSortCode() const
{
	return sortCode;
}

//														OVERLOAD OPERATOR
//----------------------------------------------------------------------
// Function: operator>=()
// overloading >= operator
// Receives: const InventoryBook& other_Book
// Returns: bool found
//----------------------------------------------------------------------
bool InventoryBook::operator>=(const InventoryBook& other_Book) const
{
	bool found = false;

	string day;
	string month;
	string year;
	int date;

	string otherDay;
	string otherMonth;
	string otherYear;
	int otherDate;

	string thisTitle = this->getTitle();
	string otherTitle = other_Book.getTitle();

	if (this != &other_Book)
	{
		switch (this->sortCode)
		{
		case 0:
			// Case 0 - Title
			if(thisTitle.compare(otherTitle) >= 0)
			{
				found = true;
			}
			break;
		case 1:
			// Case 1 - Qty
			if(this->qtyOnHand <= other_Book.qtyOnHand)
			{
				found = true;
			}
			break;
		case 2:
			// Case 2 - Wholesale
			if(this->wholesale <= other_Book.wholesale)
			{
				found = true;
			}
			break;
		case 3:
			// Case 3 - Date
			month = this->dateAdded.substr(0,2);
			day = this->dateAdded.substr(3,2);
			year = this->dateAdded.substr(6,4);
			date = atoi((year + month + day).c_str());

			otherMonth = other_Book.dateAdded.substr(0,2);
			otherDay = other_Book.dateAdded.substr(3,2);
			otherYear = other_Book.dateAdded.substr(6,4);
			otherDate = atoi((otherYear + otherMonth + otherDay).c_str());

			if(date <= otherDate)
			{
				found = true;
			}
//			if((strcmp(date.c_str(), otherDate.c_str())) >= 0)
//			{
//				found = true;
//			}
			break;
		default:
			break;
		}
	}

	return found;
}
//----------------------------------------------------------------------
// Function: operator==()
// overloading == operator
// Receives: const InventoryBook& other_Book
// Returns: bool found
//----------------------------------------------------------------------
bool InventoryBook::operator==(const InventoryBook& other_Book) const
{
	bool found = false;

	string day;
	string month;
	string year;
	int date;

	string otherDay;
	string otherMonth;
	string otherYear;
	int otherDate;

	string thisTitle = this->getTitle();
	string otherTitle = other_Book.getTitle();

	if (this != &other_Book)
	{
		switch(this->sortCode)
		{
		case 0:
			// Case 0 - Title
			if(thisTitle.compare(otherTitle) == 0)
			{
				found = true;
			}
			break;
		case 1:
			// Case 1 - Qty
			if (this->qtyOnHand == other_Book.qtyOnHand)
			{
				found = true;
			}
			break;
		case 2:
			// Case 2 - Wholesale
			if(this->wholesale == other_Book.wholesale)
			{
				found = true;
			}
			break;
		case 3:
			// Case 3 - Date
			month = this->dateAdded.substr(0,2);
			day = this->dateAdded.substr(3,2);
			year = this->dateAdded.substr(6,4);
			date = atoi((year + month + day).c_str());

			otherMonth = other_Book.dateAdded.substr(0,2);
			otherDay = other_Book.dateAdded.substr(3,2);
			otherYear = other_Book.dateAdded.substr(6,4);
			otherDate = atoi((otherYear + otherMonth + otherDay).c_str());

			if (date == otherDate)
			{
				found = true;
			}
//			if((strcmp(date.c_str(), otherDate.c_str())) == 0)
//			{
//				found = true;
//			}
			break;
		default:
			break;
		}

	}

	return found;
}
//----------------------------------------------------------------------
// Function: operator!=()
// overloading != operator
// Receives: const InventoryBook& other_Book
// Returns: bool found
//----------------------------------------------------------------------
bool InventoryBook::operator!=(const InventoryBook& other_Book) const
{
	bool found = false;

	string day;
	string month;
	string year;
	int date;

	string otherDay;
	string otherMonth;
	string otherYear;
	int otherDate;

	string thisTitle = this->getTitle();
	string otherTitle = other_Book.getTitle();

	if (this != &other_Book)
	{
		switch(this->sortCode)
		{
		case 0:
			// Case 0 - Title
			if(thisTitle.compare(otherTitle) == 0)
			{
				found = true;
			}
			break;
		case 1:
			// Case 1 - Qty
			if (this->qtyOnHand == other_Book.qtyOnHand)
			{
				found = true;
			}
			break;
		case 2:
			// Case 2 - Wholesale
			if(this->wholesale == other_Book.wholesale)
			{
				found = true;
			}
			break;
		case 3:
			// Case 3 - Date
			month = this->dateAdded.substr(0,2);
			day = this->dateAdded.substr(3,2);
			year = this->dateAdded.substr(6,4);
			date = atoi((year + month + day).c_str());

			otherMonth = other_Book.dateAdded.substr(0,2);
			otherDay = other_Book.dateAdded.substr(3,2);
			otherYear = other_Book.dateAdded.substr(6,4);
			otherDate = atoi((otherYear + otherMonth + otherDay).c_str());

			if(date == otherDate)
			{
				found = true;
			}
//			if((strcmp(date.c_str(), otherDate.c_str())) == 0)
//			{
//				found = true;
//			}
			break;
		default:
			break;
		}
	}

	return !found;
}

#endif /* INVENTORYBOOK_H_ */
