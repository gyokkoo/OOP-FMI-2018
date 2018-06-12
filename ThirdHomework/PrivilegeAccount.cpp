#include <iostream>
#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const std::string& iban, long long ownerId, double amount, double overdraft)
	: Account(iban, ownerId, amount)
{
	this->overdraft = overdraft;
}

PrivilegeAccount::~PrivilegeAccount()
{
}

PrivilegeAccount* PrivilegeAccount::clone() const
{
	return new PrivilegeAccount(*this);
}

void PrivilegeAccount::deposit(double amount)
{
	Account::deposit(amount);
}

bool PrivilegeAccount::withdraw(double amount)
{
	if (this->amount + this->overdraft < amount)
	{
		return false;
	}

	this->amount -= amount;
	return true;
}

void PrivilegeAccount::display() const
{
	std::cout << "| Privilege account\n";
	Account::display();
	std::cout << "| Overdraft   : " << this->overdraft << "\n";
}

double PrivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}

void PrivilegeAccount::setOverdraft(double overdraft)
{
	this->overdraft = overdraft;
}
