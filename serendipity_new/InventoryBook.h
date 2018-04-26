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

	string getDateAdded();
	int getQty();
	double getWholesale();
	double getRetail();

//	void removeBook();
//	bool isEmpty();

private:
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
};



#endif /* INVENTORYBOOK_H_ */
