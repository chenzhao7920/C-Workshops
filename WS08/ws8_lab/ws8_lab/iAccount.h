//student name: Chen Zhao
//student number:120122189
//section:SAA
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>
namespace sict{
	class iAccount{
	public:
		//a destructor and pure virtual public member function
		virtual ~iAccount() {};
		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount)  = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& out) const  = 0;
	};	 
	iAccount* CreateAccount(const char* type, double balance);
}
#endif 