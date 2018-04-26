#ifndef SOLDBOOK_H_
#define SOLDBOOK_H_

#include "InventoryBook.h"

class SoldBook: public InventoryBook
{
public:
	SoldBook();
	SoldBook(string bookTitle, string isbn, string author, string publisher, string dateAdded, int qtyOnHand, double wholesale, double retail, double taxRate, int qtySold, double tax);
	~SoldBook();

	void print();

	void setTaxRate(double taxRate);
	void setQtySold(int qtySold);
	void setTax(double tax);

	const double getTaxRate();
	const int getQtySold();
	const double getTax();

private:
	double taxRate;
	int qtySold;
	double tax;
	double subTotal;
	double total;
};



#endif /* SOLDBOOK_H_ */
