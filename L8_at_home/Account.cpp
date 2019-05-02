#include "Account.h"

using namespace std;

namespace ict{ 

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}
