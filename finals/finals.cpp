// ----------------------------------------------------------------------
// File name: finals.cpp
// Project name: Finals													-
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 05/21/2018											-
// Date of Last Modification: 05/22/2018								-
// ----------------------------------------------------------------------
// Purpose: 
// ----------------------------------------------------------------------
// -							DATA DICTIONARY							-
// - CONSTANTS															-
// -																	-
// - NAME					DATA TYPE				VALUE				-
// - --------------------   ----------				--------			-
// -
// -																	-
// - VARIABLES															-
// -																	-
// - NAME					DATA TYPE				INITIAL VALUE		-
// - --------------------   ----------				-------------		-
// - 
// - 
// - 
// ----------------------------------------------------------------------

#include "Foo.h"
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <limits>
#include <cstdlib>

void displayMenu();
void createNode(orderedLinkedList<Foo>& listString, orderedLinkedList<Foo>& listDouble);
void deleteNode(orderedLinkedList<Foo>& listString, orderedLinkedList<Foo>& listDouble);
void searchNode(orderedLinkedList<Foo>& listString, orderedLinkedList<Foo>& listDouble);

int main()
{
	// create list
	orderedLinkedList<Foo> listString;
	orderedLinkedList<Foo> listDouble;
	listString.initializeList();
	listDouble.initializeList();

	char choice = '\0';

	do
	{
		system("cls");

		displayMenu();
		cout << "Enter Choice: ";
		cin >> choice;
		if(cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = '0';
		}

		switch(choice)
		{
		case '1':	// clear screen
			break;
		case '2':	// create node
			createNode(listString, listDouble);
			break;
		case '3':	// delete node
			deleteNode(listString, listDouble);
			break;
		case '4':	// search
			searchNode(listString, listDouble);
			break;
		case '5':	// display linked list
			break;
		case '6':	// delete linked list
			break;
		case '7':	// quit
			break;
		default:
			cout << "Please enter choice 1 - 7.\n\n";
			system("pause");
		}	// end main menu switch


	} while (choice != '7');

	return 0;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void displayMenu()
{
	cout << "******************************" << '\n';
	cout << "*       Exam 3 Program       *" << '\n';
	cout << "******************************" << '\n';
	cout << "* <1> Clear Screen           *" << '\n';
	cout << "* <2> Create Node            *" << '\n';
	cout << "* <3> Delete Node            *" << '\n';
	cout << "* <4> Search                 *" << '\n';
	cout << "* <5> Display Linked List    *" << '\n';
	cout << "* <6> Delete Linked List     *" << '\n';
	cout << "* <7> Quit                   *" << '\n';
	cout << "******************************" << '\n';

	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void createNode(orderedLinkedList<Foo>& listString, orderedLinkedList<Foo>& listDouble)
{
	char choice = '\0';
	Foo * newNode;
	string stuffString;
	double stuffNum;

	do
	{
		system("cls");

		cout << "******************************" << '\n';
		cout << "*        Create Node         *" << '\n';
		cout << "******************************" << "\n\n";

		cout << "Word: ";
		getline(cin, stuffString);
		cout << "Number: ";
		cin >> stuffNum;
		while (cin.fail())
		{
			cout << "Error, re-enter: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> stuffNum;
			if (!cin.fail())
			{
				break;
			}
		}

		newNode = new Foo;

		// update node with values
		newNode->setFoo(stuffString);
		newNode->setFooNum(stuffNum);
		// insert node to list
		(*newNode).setSortCode(0);
		listString.insert(*newNode);
		(*newNode).setSortCode(1);
		listDouble.insert(*newNode);

		cout << "Create another node? (y/n): ";
		cin >> choice;
		if(cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = '0';
		}

	} while (tolower(choice) == 'y');

	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void deleteNode(orderedLinkedList<Foo>& listString, orderedLinkedList<Foo>& listDouble)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundFoo;
	linkedListIterator<Foo> myIterator;	// iterator

	do
	{
		system("cls");

		cout << "******************************" << '\n';
		cout << "*        Delete Node         *" << '\n';
		cout << "******************************" << "\n\n";

		// get search term
		cout << setw(13) << "Search: ";
		getline(cin, userSearch);
		// ignore caps on search term
		for (unsigned int i = 0; i < userSearch.length(); i++)
		{
			if (isupper(userSearch[i]))
			{
				userSearch[i] = tolower(userSearch[i]);
			}
		}

		myIterator = listString.begin();
		do
		{
			// ignore caps on target
			target = (*myIterator).getFoo();
			for (unsigned int i = 0; i < target.length(); i++)
			{
				if (isupper(target[i]))
				{
					target[i] = tolower(target[i]);
				}
			}

			// find user search in string foo
			foundFoo = target.find(userSearch);
			if (foundFoo != string::npos)
			{
				cout << "RESULT: " << (*myIterator).getFoo() << '\n';
				cout << "View this result? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					cout << '\n';
					(*myIterator).print();
					cout << '\n';
					cout << "DELETE? (Y/N): ";
					cin >> choice;
					break;
				}
			}

			// find user search in double foo
			if (target == (*myIterator).getFooNum())
			{
				cout << "RESULT: " << (*myIterator).getFooNum() << '\n';
				cout << "View this result? (Y/N): ";
				cin >> choice;
				if (tolower(choice) == 'y')
				{
					choice = '\0';
					cout << '\n';
					(*myIterator).print();
					cout << '\n';
					cout << "DELETE? (Y/N): ";
					cin >> choice;
					break;
				}
			}

			system("cls");

			cout << "******************************" << '\n';
			cout << "*        Delete Node         *" << '\n';
			cout << "******************************" << "\n\n";

			++myIterator;
		} while (myIterator != listString.end());		// end of database search

		// if search result is negative
		if(myIterator == listString.end() || (foundFoo == string::npos && target != (*myIterator).getFooNum()))
		{
			cout << setw(13) << "Result not found." << '\n';
			system("pause");
		}

		// delete node
		if (tolower(choice) == 'y')
		{
			listString.deleteNode(*myIterator);
			listDouble.deleteNode(*myIterator);

			cout << "Node Deleted.\n";
			cout << "Delete Another? (Y/N): ";
			cin >> choice;
			if(cin.get() != '\n')
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = '0';
			}
			cin.ignore();
		}
	} while(tolower(choice) == 'y');

	return;
}

//----------------------------------------------------------------------
// Function:
//
// Receives:
// Returns:
//----------------------------------------------------------------------
void searchNode(orderedLinkedList<Foo>& listString, orderedLinkedList<Foo>& listDouble)
{
	char choice = '\0';
	string userSearch;
	string target;
	size_t foundFoo;
	linkedListIterator<Foo> myIterator;	// iterator

	system("cls");

	cout << "******************************" << '\n';
	cout << "*           Search           *" << '\n';
	cout << "******************************" << "\n\n";

	// get search term
	cout << setw(13) << "Search: ";
	getline(cin, userSearch);
	// ignore caps on search term
	for (unsigned int i = 0; i < userSearch.length(); i++)
	{
		if (isupper(userSearch[i]))
		{
			userSearch[i] = tolower(userSearch[i]);
		}
	}

	myIterator = listString.begin();
	do
	{
		// ignore caps on target
		target = (*myIterator).getFoo();
		for (unsigned int i = 0; i < target.length(); i++)
		{
			if (isupper(target[i]))
			{
				target[i] = tolower(target[i]);
			}
		}

		// find user search in string foo
		foundFoo = target.find(userSearch);
		if (foundFoo != string::npos)
		{
			cout << "RESULT: " << (*myIterator).getFoo() << '\n';
			cout << "View this result? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				cout << '\n';
				(*myIterator).print();
				cout << '\n';
				cout << "DELETE? (Y/N): ";
				cin >> choice;
				break;
			}
		}

		// find user search in double foo
		if (target == (*myIterator).getFooNum())
		{
			cout << "RESULT: " << (*myIterator).getFooNum() << '\n';
			cout << "View this result? (Y/N): ";
			cin >> choice;
			if (tolower(choice) == 'y')
			{
				choice = '\0';
				cout << '\n';
				(*myIterator).print();
				cout << '\n';
				cout << "DELETE? (Y/N): ";
				cin >> choice;
				break;
			}
		}

		system("cls");

		cout << "******************************" << '\n';
		cout << "*           Search           *" << '\n';
		cout << "******************************" << "\n\n";

		++myIterator;
	} while (myIterator != listString.end());		// end of database search

	// if search result is negative
	if(myIterator == listString.end() || (foundFoo == string::npos && target != (*myIterator).getFooNum()))
	{
		cout << setw(13) << "Result not found." << '\n';
		system("pause");
	}

	return;
}
