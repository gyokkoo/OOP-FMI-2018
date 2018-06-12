#include <iostream>
#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(std::string iban, long long ownerId, double amount)
	: Account(iban, ownerId, amount)
{
}
 
CurrentAccount::~CurrentAccount()
{
}

CurrentAccount* CurrentAccount::clone() const
{
	return new CurrentAccount(*this);
}

void CurrentAccount::deposit(double amount)
{
	Account::deposit(amount);
}

bool CurrentAccount::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void CurrentAccount::display() const
{
	std::cout << "|Current Account \n";
	Account::display();
}
