// Name: Gayane Babayan
// Date: 20-March-2017
// File: workshop8-inLab


#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage)
		public:

			// TODO: put prototypes here
			SavingsAccount(double initialBal, double initialIntRate);
			double calculateInterest();
			void display(std::ostream& ostr) const;

   };
};
#endif
