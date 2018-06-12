#pragma once
#include <string>
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(const std::string& iban, long long ownerId, double amount, double interestRate);
	virtual ~SavingsAccount();

	virtual SavingsAccount* clone() const override;

	virtual void deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void display() const override;

	double getInterestRate() const;
	void setInterestRate(double interestRate);
private:
	double interestRate;
};