#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
namespace sict {
	ChequingAccount::ChequingAccount(double balance, double transfee, double monthlyfee) : Account::Account(balance) {
		this->TransFee = (transfee > 0) ? transfee : 0.0;
		this->MonthlyFee = (monthlyfee > 0) ? monthlyfee : 0.0;
	}
	bool ChequingAccount::credit(double amount) {
		 
		return Account::credit(amount) && Account::debit(TransFee);
	}
	bool ChequingAccount::debit(double amount) {
		 
		return Account::debit(amount + TransFee);
	}
	void ChequingAccount::monthEnd() {
		Account::debit(MonthlyFee);
	}
	void ChequingAccount::display(std::ostream & out) const {
		out << "Account type: Chequing\n"
			<< "Balance: $";
	 
		out<< std::setprecision(2)
		   << Balance << '\n' << "Per Transaction Fee: " << TransFee << '\n'
			<< "Monthly Fee: " << MonthlyFee <<'\n';
	}
}
