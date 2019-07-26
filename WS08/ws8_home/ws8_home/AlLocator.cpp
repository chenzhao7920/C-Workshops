//student name: Chen Zhao
//student number:120122189
//section:SAA
#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h" 
#include <iostream>
namespace sict {
	const double interest_Rate = 0.05;
	const double trans_Fee = 0.5;
	const double month_Fee = 2.0;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount * tmp = nullptr;
		if (type[0] == 'S') {	
			tmp = new SavingsAccount(balance, interest_Rate);
		}
		else if (type[0] == 'C') {
			tmp = new ChequingAccount(balance, trans_Fee, month_Fee);
		}
	    return tmp;
	}

}