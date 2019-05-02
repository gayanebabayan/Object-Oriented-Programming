#include "CheckingAccount.h"
#include <iomanip>

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here     
   CheckingAccount::CheckingAccount(double initialBal, double transFee)
   :Account(initialBal) {
      if (transFee < 0)
         transactionFee = 0;
      else
         transactionFee = transFee;
   }

   void CheckingAccount::chargeFee() {
      setBalance(getBalance() - transactionFee);  // Is this correct ???
   }

   // override debit & credit




   // override the display
   void CheckingAccount::display(std::ostream & ostr) const {
      ostr << "Account type: Checking" << endl;
      ostr << "Balance: $ " << fixed << setprecision(2) << getBalance() << endl;
      ostr << "Transaction Fee: " << fixed << setprecision(2) << transactionFee << endl;
   }



}