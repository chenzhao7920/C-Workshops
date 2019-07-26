#include <iostream>
#include <cstring>
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sict {

	void Book::set(const char* g_, const char* f_, const char* ti_, long long int isbn) {
		if (isbn >= 1000000000000ll && isbn <= 9999999999999ll) {
			strncpy(givenName, g_,strlen(g_));
			strncpy(familyName, f_,strlen(f_));
			strncpy(title, ti_,strlen(ti_));
			ISBN = isbn;
		}
		else {
			ISBN = 0;
			strcpy(givenName, "?");
			strcpy(familyName, "?");
			strcpy(title, "?");

		}
	}
	bool Book::isEmpty() const {
		bool isempty = ISBN == 0;	 
		return isempty;
	}
	void Book::display() const {
		if (ISBN == 0)
			cout << "The book object is empty!" << endl;
		else {
			cout << "Author: " << familyName << ", " << givenName << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << ISBN << endl;
		}
	}
}