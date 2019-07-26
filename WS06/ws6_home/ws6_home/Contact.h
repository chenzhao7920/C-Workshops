//workshop 6 at_home
//Student Name: Chen Zhao
//Student No.: 120122189
//Section:SAA

//namespace 
namespace sict {
	const int max_name_size = 16;
	//class declaration
	class Contact
	{
		char name[max_name_size];
		long long int* phone;
		int amt;
		//private member funciton, use to check if phone nember is valid
		bool validphonenum(const long long int);

	public:
		Contact();
		Contact(const char*, const long long int*, int);
		Contact (const Contact&);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator= (const Contact&);
		Contact& operator+= (const long long int);
	};

}
#pragma once
