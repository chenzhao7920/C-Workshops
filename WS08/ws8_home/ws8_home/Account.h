//student name: Chen Zhao
//student number:120122189
//section:SAA
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"
namespace sict {
	class Account : public iAccount{
	    protected:
		     double Balance;
	//		 double balance() const;
	     public:
			 Account(double balance=0.0f);
			 bool credit(double);
			 bool debit(double);
			 
	};
//	iAccount* CreateAccount(const char* type, double balance);
}
#endif 