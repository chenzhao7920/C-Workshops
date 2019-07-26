#ifndef _SICT_BOOK_H_
#define _SICT_BOOK_H_
namespace sict{
	const int max_title_size = 33;
	const int max_name_size = 17;
	class Book
	{
		char title[max_title_size];
		long long int ISBN;
		char familyName[max_name_size];
		char givenName[max_name_size];
	public:
		void set(const char*, const char*, const char*, long long int );
		bool isEmpty() const;
		void display() const;
	
	};

}
#endif