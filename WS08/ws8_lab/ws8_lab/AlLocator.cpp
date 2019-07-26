#include "iAccount.h"
#include "Account.h"
//student name: Chen Zhao
//student number:120122189
//section:SAA
#include "SavingsAccount.h"
#include <iostream>
namespace sict {
	const double interest_Rate = 0.05;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount * tmp = nullptr;
		if (type[0] == 's' || type[0] == 'S') {	
			tmp = new SavingsAccount(balance, interest_Rate);	 
		}
	    return tmp;
	}

}