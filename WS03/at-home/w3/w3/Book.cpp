#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
namespace sict {
	void Book::set(int y_, double p_) {
		if (!isEmpty()) {
			year = y_;
			price = p_;
		}
	}
	void Book::set(const char* g_, const char* f_, const char* ti_, long long int isbn) {
		bool valid = isbn >= min_isbn_value && isbn <= max_isbn_value; 
		if (valid) {
			int digit[isbn_size] = {0};
			int count = 0;
			long long int counter = isbn;
			for (int i = 0; i < isbn_size; i++) {
				digit[i] = counter % 10;
				counter = (counter - digit[i]) / 10;
			}
  			for (int i = 1; i < 13; i++) {
				if (i % 2 == 1)
					count += 3*digit[i];
				else
					count += digit[i];
			}
			if (((count + digit[0]) % 10) == 0) {
				    givenName[max_name_size]= '\0';
				    familyName[max_name_size]='\0';
				    title[max_title_size]= '\0';
					strncpy(givenName, g_,max_name_size);
					strncpy(familyName, f_,max_name_size);
					strncpy(title, ti_,max_title_size);
					ISBN = isbn;
			}
			else {
				ISBN = 0;;
				strcpy(givenName, "?");
				strcpy(familyName, "?");
				strcpy(title, "?");
			}
		}
		else {
				ISBN = 0;;
				strcpy(givenName, "?");
				strcpy(familyName, "?");
				strcpy(title, "?");
		}
		 
	}
	bool Book::isEmpty() const {
		bool isempty = ISBN==0;	 
		return isempty;
	}
	void Book::display(bool table) const {
		if (table) {
			if (isEmpty()) {
				cout << "|";
				cout.width(92);
				cout.setf(ios::left);
				cout << "The book object is empty!" << "|" << endl;
				cout.unsetf(ios::left);
			}
			else {
				cout << "|";
				cout.width(max_name_size);
				cout << familyName << "|";
				cout.width(max_name_size);
				cout << givenName << "|";
				cout.width(max_title_size);
				cout.setf(ios::left);
				cout<< title << "|";
				cout.unsetf(ios::left);
				cout.width(13);
				cout << ISBN << "|"; 
				cout.width(4);
				cout << year << "|";
				cout.setf(ios::fixed);
				cout.precision(2);
				cout.width(6);
				cout << price <<"|" << endl;
				cout.unsetf(ios::fixed);
				cout.precision(6);
			};

		}else {
			if (isEmpty()) {
				cout << "The book object is empty!" << endl;
			}
			else {
				cout << "Author: " << familyName << ", " << givenName << endl
				     << "Title: " << title << endl
				     << "ISBN-13: " << ISBN << endl
			         << "Publication Year: " << year << endl
					 << "Price: " << price << endl;
			};
		}
	}
}