#ifndef BOOKDATA_H_
#define BOOKDATA_H_

#include <iostream>
#include <string>
using namespace std;

class BookData
{
public:
	BookData();
	BookData(string bookTitle, string isbn, string author, string publisher);
	~BookData();

	virtual void print();

	void setTitle(string bookTitle);
	void setIsbn(string isbn);
	void setAuthor(string author);
	void setPub(string pubilsher);


	void removeBook();

	string getTitle();
	string getIsbn();
	string getAuthor();
	string getPub();


private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;

};

#endif /* BOOKDATA_H_ */
