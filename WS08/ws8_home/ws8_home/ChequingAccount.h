//student name: Chen Zhao
//student number:120122189
//section:SAA
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H
#include "Account.h"
namespace sict {
	class ChequingAccount : public Account
	{
		double TransFee;
		double MonthlyFee;
	public:
		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream & out) const;
	};
}
#endif
