//student name: Chen Zhao
//student number:120122189
//section:SAA
#include <iostream>
#include "Account.h"
namespace sict {
	//protected funciton
	/*double Account::balance() const {
		return Balance;
	}
	*/
	//public function
	//constructor
	Account::Account(double bal) {
		if (bal < 0) 
			Balance = 0.0f;
		else 
			Balance = bal;
	}

	bool Account::credit(double amount){
		bool valid = ( amount > 0);
		if (valid)  
			Balance = Balance + amount;
		return valid;
	}

	bool  Account::debit(double amount) {
		bool valid = (amount > 0 && amount <= Balance);
		if (valid) Balance -= amount;
		return valid;
	}
}

