#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account(double initialBal) {
		if (initialBal >= 0)
         setBalance(initialBal);
		else
         setBalance(-1);
	}

	// credit (add) an amount to the account balance
	void Account::credit(int amount){
		balance = balance + amount;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(int amount) {
		if (amount <= balance)
			setBalance(balance - amount);
		return (amount <= balance);
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}
