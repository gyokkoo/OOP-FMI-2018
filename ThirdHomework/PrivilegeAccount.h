#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount(const std::string& iban, long long ownerId, double amount, double overdraft);
	virtual ~PrivilegeAccount();

	virtual PrivilegeAccount* clone() const override;

	virtual void deposit(double amount) override;
	virtual bool withdraw(double amount) override;
	virtual void display() const override;

	double getOverdraft() const;
	void setOverdraft(double overdraft);
private:
	double overdraft;
};