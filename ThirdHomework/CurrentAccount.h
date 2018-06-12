#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(std::string iban, long long ownerId, double amount);
	virtual ~CurrentAccount();

	virtual CurrentAccount* clone() const override;

	virtual void deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void display() const override;
};