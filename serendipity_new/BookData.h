#ifndef BOOKDATA_H_
#define BOOKDATA_H_

#include <iostream>
#include <string>
using namespace std;

class BookData
{
public:
	BookData();
	BookData(string bookTitle, string isbn, string author, string publisher,
			string dateAdded, int qtyOnHand, double wholesale, double retail);
	~BookData();

	void setTitle(string bookTitle);
	void setIsbn(string isbn);
	void setAuthor(string author);
	void setPub(string pubilsher);
	void setDateAdded(string dateAdded);
	void setQty(int qty);
	void setWholesale(double wholesale);
	void setRetail(double retail);

	void removeBook();

	string getTitle();
	string getIsbn();
	string getAuthor();
	string getPub();
	string getDateAdded();
	int getQty();
	double getWholesale();
	double getRetail();

private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	double wholesale;
	double retail;
};

#endif /* BOOKDATA_H_ */
