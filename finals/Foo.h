#ifndef FOO_H_
#define FOO_H_

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Foo
{
private:
	// method variables
	string foo;
	double fooNum;
	int sortCode;
public:
	// constructors
	Foo();
	Foo(string foo, double fooNum);
	~Foo(void);

	// action methods
	void print();

	// setters
	void setFoo(string foo);
	void setFooNum(double fooNum);
	void setSortCode(int sortCode);

	// getters const
	string getFoo() const;
	double getFooNum() const;
	int getSortCode() const;

	// overload operators
	bool operator>=(const Foo& other_Foo) const;
	bool operator==(const Foo& other_Foo) const;
	bool operator!=(const Foo& other_Foo) const;

	//----------------------------------------------------------------------
	// Function: operator<<()
	// overload ostream
	// Receives: ostream& osObject, const BookData& c
	// Returns: ostream osObject
	//----------------------------------------------------------------------
//	friend ostream& operator<< (ostream& osObject, const Foo& c)
//	{
//		osObject << left << setfill(' ')<< " " << setw(29) << c.bookTitle.substr (0,28)
//			<< setw(11) << c.isbn << setw(15) << c.author.substr(0,14)
//			<< setw(11) << c.publisher.substr (0,14) << endl;
//
//		return osObject;
//	}
};

//																	CONSTRUCTORS
//-------------------------------------------------------------------------------
// Function:
// default constructor
// Receives: none
// Returns: none
//-------------------------------------------------------------------------------
Foo::Foo()
{
	setFoo("Not Set");
	setFooNum(0.0);
}

//-------------------------------------------------------------------------------
// Function:
// overload constructor
// Receives:
// Returns: none
//-------------------------------------------------------------------------------
Foo::Foo(string foo, double fooNum)
{
	setFoo(foo);
	setFooNum(fooNum);
}

//-------------------------------------------------------------------------------
// Function:
// destructor
// Receives: none
// Returns: none
//-------------------------------------------------------------------------------
Foo::~Foo(){}


//																		PRINT
//-------------------------------------------------------------------------------
// Function: print()
// display method information
// Receives: none
// Returns: none
//-------------------------------------------------------------------------------
void Foo::print()
{
	cout << getFoo() << '\n';
	cout << getFooNum() << '\n';
}

//																		SETTERS
//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns: none
//-------------------------------------------------------------------------------
void Foo::setFoo(string foo)
{
	this->foo = foo;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns: none
//-------------------------------------------------------------------------------
void Foo::setFooNum(double fooNum)
{
	this->fooNum = fooNum;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns: none
//-------------------------------------------------------------------------------
void Foo::setSortCode(int sortCode)
{
	this->sortCode = sortCode;
}

//																		GETTERS
//-------------------------------------------------------------------------------
// Function:
//
// Receives: none
// Returns:
//-------------------------------------------------------------------------------
string Foo::getFoo() const
{
	return foo;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives: none
// Returns:
//-------------------------------------------------------------------------------
double Foo::getFooNum() const
{
	return fooNum;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives: none
// Returns:
//-------------------------------------------------------------------------------
int Foo::getSortCode() const
{
	return sortCode;
}

//																OVERLOAD OPERATOR
//-------------------------------------------------------------------------------
// Function: operator>=()
// overloading >= operator
// Receives:
// Returns: bool found
//-------------------------------------------------------------------------------
bool Foo::operator>=(const Foo& other_Foo) const
{
	bool found = false;

//	string day;
//	string month;
//	string year;
//	int date;
//	string otherDay;
//	string otherMonth;
//	string otherYear;
//	int otherDate;

	string thisFoo = this->getFoo();
	string otherFoo = other_Foo.getFoo();


	if (this != &other_Foo)
	{
		switch (this->sortCode)
		{
		case 0:	// Case 0 - String
			if(thisFoo.compare(otherFoo) >= 0)
			{
				found = true;
			}
			break;
		case 1:	// Case 1 - Double
			if(this->fooNum <= other_Foo.fooNum)
			{
				found = true;
			}
			break;
//		case 2:	// Case 2 - Date
//			month = this->dateAdded.substr(0,2);
//			day = this->dateAdded.substr(3,2);
//			year = this->dateAdded.substr(6,4);
//			date = atoi((year + month + day).c_str());
//
//			otherMonth = other_Foo.dateAdded.substr(0,2);
//			otherDay = other_Foo.dateAdded.substr(3,2);
//			otherYear = other_Foo.dateAdded.substr(6,4);
//			otherDate = atoi((otherYear + otherMonth + otherDay).c_str());
//
//			if(date <= otherDate)
//			{
//				found = true;
//			}
//			// original
////			if((strcmp(date.c_str(), otherDate.c_str())) >= 0)
////			{
////				found = true;
////			}
//			break;
		default:
			break;
		}	// end switch
	}

	return found;
}

//-------------------------------------------------------------------------------
// Function: operator==()
// overloading == operator
// Receives:
// Returns: bool found
//-------------------------------------------------------------------------------
bool Foo::operator==(const Foo& other_Foo) const
{
	bool found = false;

//	string day;
//	string month;
//	string year;
//	int date;
//	string otherDay;
//	string otherMonth;
//	string otherYear;
//	int otherDate;

	string thisFoo = this->getFoo();
	string otherFoo = other_Foo.getFoo();


	if (this != &other_Foo)
	{
		switch(this->sortCode)
		{
		case 0:	// Case 0 - String
			if(thisFoo.compare(otherFoo) == 0)
			{
				found = true;
			}
			break;
		case 1:	// Case 1 - Double
			if(this->fooNum == other_Foo.fooNum)
			{
				found = true;
			}
			break;
//		case 2:	// Case 2 - Date
//			month = this->dateAdded.substr(0,2);
//			day = this->dateAdded.substr(3,2);
//			year = this->dateAdded.substr(6,4);
//			date = atoi((year + month + day).c_str());
//
//			otherMonth = other_Foo.dateAdded.substr(0,2);
//			otherDay = other_Foo.dateAdded.substr(3,2);
//			otherYear = other_Foo.dateAdded.substr(6,4);
//			otherDate = atoi((otherYear + otherMonth + otherDay).c_str());
//
//			if (date == otherDate)
//			{
//				found = true;
//			}
////			if((strcmp(date.c_str(), otherDate.c_str())) == 0)
////			{
////				found = true;
////			}
//			break;
		default:
			break;
		}

	}

	return found;
}

//-------------------------------------------------------------------------------
// Function: operator!=()
// overloading != operator
// Receives:
// Returns: bool found
//-------------------------------------------------------------------------------
bool Foo::operator!=(const Foo& other_Foo) const
{
	bool found = false;

//	string day;
//	string month;
//	string year;
//	int date;
//	string otherDay;
//	string otherMonth;
//	string otherYear;
//	int otherDate;

	string thisFoo = this->getFoo();
	string otherFoo = other_Foo.getFoo();

	if (this != &other_Foo)
	{
		switch(this->sortCode)
		{
		case 0:	// Case 0 - String
			if(thisFoo.compare(otherFoo) == 0)
			{
				found = true;
			}
			break;
		case 1:	// Case 1 - Double
			if(this->fooNum == other_Foo.fooNum)
			{
				found = true;
			}
			break;
//		case 2:	// Case 2 - Date
//			month = this->dateAdded.substr(0,2);
//			day = this->dateAdded.substr(3,2);
//			year = this->dateAdded.substr(6,4);
//			date = atoi((year + month + day).c_str());
//
//			otherMonth = other_Foo.dateAdded.substr(0,2);
//			otherDay = other_Foo.dateAdded.substr(3,2);
//			otherYear = other_Foo.dateAdded.substr(6,4);
//			otherDate = atoi((otherYear + otherMonth + otherDay).c_str());
//
//			if(date == otherDate)
//			{
//				found = true;
//			}
////			if((strcmp(date.c_str(), otherDate.c_str())) == 0)
////			{
////				found = true;
////			}
//			break;
		default:
			break;
		}
	}

	return !found;
}

#endif /* FOO_H_ */
