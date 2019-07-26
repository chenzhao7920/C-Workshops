//student name: Chen Zhao
//student number:120122189
//section:SAA
#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "iAccount.h"
#include "Account.h"
namespace sict {
	class SavingsAccount : public Account{
		double InterestRate;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(std::ostream & out) const;
	};
}
#endif