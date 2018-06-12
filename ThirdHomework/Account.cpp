#include <iostream>
#include "Account.h"

Account::Account(const std::string& iban, long long ownerId, double amount)
{
	this->iban = iban;
	this->ownerId = ownerId;
	this->amount = amount;
}

Account::~Account()
{
}

void Account::deposit(double amount)
{
	this->amount += amount;
}

bool Account::withdraw(double amount)
{
	if (this->amount < amount)
	{
		return false;
	}

	this->amount -= amount;
	return true;
}

void Account::display() const
{
	std::cout 
		<< "| Iban        : " << iban << "\n"
		<< "| OwnerId     : " << ownerId << "\n"
		<< "| Amount      : " << amount << " euro\n";
}

double Account::getBalance() const
{
	return this->amount;
}

const std::string& Account::getIban() const
{
	return this->iban;
}

long long Account::getOwnerId() const
{
	return this->ownerId;
}
