// ----------------------------------------------------------------------
// File name: main.cpp, BookData.h, BookData.cpp
// Project name: Serendipity
// ----------------------------------------------------------------------
// Creator's name and email: Yujin Chung ychung23@ivc.edu				-
// Course-Section: CS 1B Ticket# 18185									-
// Creation Date: 04/23/2018
// Date of Last Modification: 04/25/2018
// ----------------------------------------------------------------------
// Purpose: 
// ----------------------------------------------------------------------
// Algorithm:															-
// Step 1: 
// Step 2: 
// Step 3: 
// Step 4: 
// Step 5: 
// ----------------------------------------------------------------------
// -							DATA DICTIONARY							-
// - CONSTANTS															-
// -																	-
// - NAME					DATA TYPE				VALUE				-
// - --------------------   ----------				--------			-
// - BookData				class
// - InventoryBook			class
// - SoldBook				class
// -																	-
// - VARIABLES															-
// -																	-
// - NAME					DATA TYPE				INITIAL VALUE		-
// - --------------------   ----------				-------------		-
// - 
// - 
// - 
// ----------------------------------------------------------------------

#include "BookData.h"
#include "InventoryBook.h"
#include "SoldBook.h"
#include "linkedList.h"
#include "orderedLinkedList.h"

#include <cstdlib>

const float SALES_TAX = 0.06;
const int DBSIZE = 1;

int main()
{

	orderedLinkedList<InventoryBook> list1; //create linked list
	list1.initializeList(); // initialize list

	InventoryBook *book1 = new InventoryBook ("Star Wars", "0345260791", "George Lucas", "Del Rey", "10/18/2017", 5, 59.95, 100.00);
	InventoryBook *book2 = new InventoryBook ("The Empire Strikes Back (Star Wars)", "034529209X", "George Lucas", "Ballantine", "04/01/2017", 2, 179.58, 185.00);
	InventoryBook *book3 = new InventoryBook ("Splinter of the Mind's Eye (Star Wars)", "0345320239", "George Lucas", "Del Rey", "11/08/2017", 3, 24, 26.50);
	InventoryBook *book4 = new InventoryBook ("Return of the Jedi (Star Wars)", "0345307674", "George Lucas", "Del Rey", "10/09/2017", 4, 2.94, 6.50);
	InventoryBook *book5 = new InventoryBook ("Heir to the Empire (Star Wars: The Thrawn Trilogy, Vol. 1)", "0553296124", "Timothy Zahn", "Bantam", "11/01/2017", 10, 25.38, 27.00);

	// insert books into the linked list
	list1.insert(*book1);
	list1.insert(*book2);
	list1.insert(*book3);
	list1.insert(*book4);
	list1.insert(*book5);

	linkedListIterator<InventoryBook> myIterator; // create an iterator to iterate through the linked list

	for (myIterator = list1.begin(); myIterator != list1.end(); ++myIterator)
	{
		cout << (*myIterator).getTitle() << endl;
	}

	system("pause");
	return 0;
}
