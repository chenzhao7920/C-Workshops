#ifndef _SICT_BOOK_H_
#define _SICT_BOOK_H_
namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const int isbn_size = 13;
	const long long int min_isbn_value = 1000000000000;
	const long long int max_isbn_value = 9999999999999;
	class Book
	{
		int  year;
		double price;
		char title[max_title_size+1];
		long long int ISBN;
		char familyName[max_name_size+1];
		char givenName[max_name_size+1];
	public:
		void set(int, double);
		void set(const char*, const char*, const char*, long long int);
		bool isEmpty() const;
		void display(bool = false) const;

	};

}
#endif
