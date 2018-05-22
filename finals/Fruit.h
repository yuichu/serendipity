#ifndef FRUIT_H_
#define FRUIT_H_

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//struct Fruit
//{
//	string name;
//	string color;
//	double weight;
//};
// in main:
//Fruit fruitStruct[SIZE];
//Fruit fruitClass[SIZE];

class Fruit
{
private:
	string name;
	string color;
	double weight;
	int sortCode; // 0 = name, 1 = color, 2 = weight
public:
	// constructors
	Fruit();
	Fruit(string name, string color, double weight);
	~Fruit();

	void convert();
	void print();

	// setters
	void setName(string name);
	void setColor(string color);
	void setWeight(double weight);

	// getters
	string getName() const;
	string getColor() const;
	double getWeight() const;

	// overload operators
	bool operator>=(const Fruit& otherFruit) const;
	bool operator==(const Fruit& otherFruit) const;
	bool operator!=(const Fruit& otherFruit) const;

};

//																	CONSTRUCTORS
//-------------------------------------------------------------------------------
// Function: Fruit()
// default constructor
// Receives: none
// Returns: none
//-------------------------------------------------------------------------------
Fruit::Fruit()
{
	setName("Not Set");
	setColor("Not Set");
	setWeight(0.0);
}

//-------------------------------------------------------------------------------
// Function: Fruit()
// overload constructor
// Receives: string name, string color, double weight
// Returns: none
//-------------------------------------------------------------------------------
Fruit::Fruit(string name, string color, double weight)
{
	setName(name);
	setColor(color);
	setWeight(weight);
}

//-------------------------------------------------------------------------------
// Function: ~Fruit()
// destructor
// Receives: none
// Returns: none
//-------------------------------------------------------------------------------
Fruit::~Fruit(){}

//																		CONVERT
//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
void Fruit::convert()
{
	// create an addition method for the fruit class that
	// accepts a pointer to an existing fruit struct that
	// copies the values of the struct members to the class members

	//i.e. this method will be used to copy/convert a fruit structure to a fruit class
}

//																		PRINT
//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
void Fruit::print()
{
	cout << "Fruit: " << getName() << '\n';
	cout << "Color: " << getColor() << '\n';
	cout << "Weight: " << fixed << setprecision(2) << getWeight() << setprecision(0) << '\n';
}

//																		SETTERS
//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
void Fruit::setName(string name)
{
	this->name = name;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
void Fruit::setColor(string color)
{
	this->color = color;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
void Fruit::setWeight(double weight)
{
	this->weight = weight;
}

//																		GETTERS
//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
string Fruit::getName() const
{
	return name;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
string Fruit::getColor() const
{
	return color;
}

//-------------------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//-------------------------------------------------------------------------------
double Fruit::getWeight() const
{
	return weight;
}

//														OVERLOAD OPERATOR
//----------------------------------------------------------------------
// Function: operator>=()
// overloading >= operator
// Receives:
// Returns: bool found
//----------------------------------------------------------------------
bool Fruit::operator>=(const Fruit& otherFruit) const
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

	string thisName = this->getName();
	string otherName = otherFruit.getName();
	string thisColor = this->getColor();
	string otherColor = otherFruit.getColor();


	if (this != &otherFruit)
	{
		switch (this->sortCode)
		{
		case 0:	// Case 0 - Name
			if(thisName.compare(otherName) >= 0)
			{
				found = true;
			}
			break;
		case 1:	// Case 1 - Color
			if(thisColor.compare(otherColor) >= 0)
			{
				found = true;
			}
			break;
		case 2:	// Case 2 - Weight
			if(this->weight <= otherFruit.weight)
			{
				found = true;
			}
			break;
//		case 3:
//			// Case 3 - Date
//			month = this->dateAdded.substr(0,2);
//			day = this->dateAdded.substr(3,2);
//			year = this->dateAdded.substr(6,4);
//			date = atoi((year + month + day).c_str());
//
//			otherMonth = other_Book.dateAdded.substr(0,2);
//			otherDay = other_Book.dateAdded.substr(3,2);
//			otherYear = other_Book.dateAdded.substr(6,4);
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

//----------------------------------------------------------------------
// Function: operator==()
// overloading == operator
// Receives:
// Returns: bool found
//----------------------------------------------------------------------
bool Fruit::operator==(const Fruit& otherFruit) const
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

	string thisName = this->getName();
	string otherName = otherFruit.getName();
	string thisColor = this->getColor();
	string otherColor = otherFruit.getColor();

	if (this != &otherFruit)
	{
		switch(this->sortCode)
		{
		case 0:	// Case 0 - Name
			if(thisName.compare(otherName) == 0)
			{
				found = true;
			}
			break;
		case 1:	// Case 1 - Color
			if(thisColor.compare(otherColor) == 0)
			{
				found = true;
			}
			break;
		case 2:	// Case 2 - Weight
			if(this->weight == otherFruit.weight)
			{
				found = true;
			}
			break;
//		case 3:
//			// Case 3 - Date
//			month = this->dateAdded.substr(0,2);
//			day = this->dateAdded.substr(3,2);
//			year = this->dateAdded.substr(6,4);
//			date = atoi((year + month + day).c_str());
//
//			otherMonth = other_Book.dateAdded.substr(0,2);
//			otherDay = other_Book.dateAdded.substr(3,2);
//			otherYear = other_Book.dateAdded.substr(6,4);
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

//----------------------------------------------------------------------
// Function: operator!=()
// overloading != operator
// Receives:
// Returns: bool found
//----------------------------------------------------------------------
bool Fruit::operator!=(const Fruit& otherFruit) const
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

	string thisName = this->getName();
	string otherName = otherFruit.getName();
	string thisColor = this->getColor();
	string otherColor = otherFruit.getColor();


	if (this != &otherFruit)
	{
		switch(this->sortCode)
		{
		case 0:	// Case 0 - Name
			if(thisName.compare(otherName) == 0)
			{
				found = true;
			}
			break;
		case 1:	// Case 1 - Color
			if(thisColor.compare(otherColor) == 0)
			{
				found = true;
			}
			break;
		case 2:	// Case 2 - Weight
			if(this->weight == otherFruit.weight)
			{
				found = true;
			}
			break;
//		case 3:
//			// Case 3 - Date
//			month = this->dateAdded.substr(0,2);
//			day = this->dateAdded.substr(3,2);
//			year = this->dateAdded.substr(6,4);
//			date = atoi((year + month + day).c_str());
//
//			otherMonth = other_Book.dateAdded.substr(0,2);
//			otherDay = other_Book.dateAdded.substr(3,2);
//			otherYear = other_Book.dateAdded.substr(6,4);
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

#endif /* FRUIT_H_ */
