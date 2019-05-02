// Name: Gayane Babayan
// Date: 20-March-2017
// File: workshop8-inLab


#include "SavingsAccount.h"
#include <iomanip>

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here

	// constructors
	SavingsAccount::SavingsAccount(double initialBal, double initialIntRate)
	:Account(initialBal) {
		
		if (initialIntRate < 0)
			interestRate = 0;
		else
			interestRate = initialIntRate;
	}

	double SavingsAccount::calculateInterest() {
		return interestRate * getBalance();
	}

	void SavingsAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Saving" << endl;
		ostr << "Balance: $ " << fixed << setprecision(2) << getBalance() << endl;
		ostr << "Interest Rate (%): " << fixed << setprecision(2) << interestRate * 100 << endl;	
	};

}
