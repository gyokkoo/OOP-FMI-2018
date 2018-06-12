#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& iban, long long ownerId, double amount, double interestRate)
	: Account(iban, ownerId, amount)
{
	this->setInterestRate(interestRate);
}

SavingsAccount::~SavingsAccount()
{
}

SavingsAccount* SavingsAccount::clone() const
{
	return new SavingsAccount(*this);
}

void SavingsAccount::deposit(double amount)
{
	Account::deposit(amount);
}

bool SavingsAccount::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void SavingsAccount::display() const
{
	std::cout << "|Savings account\n";
	Account::display();
	std::cout << "|Interest rate: " << this->getInterestRate() << "%\n";
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::setInterestRate(double interestRate)
{
	this->interestRate = interestRate;
}
