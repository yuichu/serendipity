#ifndef SOLDBOOK_H_
#define SOLDBOOK_H_

#include "InventoryBook.h"

class SoldBook: public InventoryBook
{
public:
	SoldBook();
	SoldBook();
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
