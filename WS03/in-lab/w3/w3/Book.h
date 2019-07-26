#ifndef _SICT_BOOK_H_
#define _SICT_BOOK_H_
namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	class Book
	{
		char title[max_title_size+1];
		long long int ISBN;
		char familyName[max_name_size+1];
		char givenName[max_name_size+1];
	public:
		void set(const char*, const char*, const char*, long long int);
		bool isEmpty() const;
		void display() const;

	};

}
#endif
