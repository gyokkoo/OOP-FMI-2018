#pragma once
#include <string>

class Account
{
public:
	Account(const std::string& iban, long long ownerId, double amount);
	virtual ~Account();

	virtual Account* clone() const = 0;

	virtual void deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;
	virtual void display() const = 0;

	double getBalance() const;
	const std::string& getIban() const;
	long long getOwnerId() const;
protected:
	std::string iban;
	long long ownerId;
	double amount;
};