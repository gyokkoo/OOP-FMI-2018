#pragma once
#include <string>
#include <vector>

#include "Customer.h"
#include "Account.h"

class Bank
{
public:
	Bank();
	Bank(const std::string& name, const std::string& address);
	Bank(const Bank& bank);
	Bank& operator=(const Bank& bank);
	~Bank();

	const std::string& getName() const;
	const std::string& getAddress() const;

	void setName(const std::string& name);
	void setAddress(const std::string& address);

	void withdrawFromAccount(const std::string& iban, double amount);
	void depositToAccount(const std::string& iban, double amount);

	void addCustomer(long long customerId, const std::string& name, const std::string& address);
	void listCustomers() const;
	void deleteCustomer(long long customerId);
	void addAccount(const std::string& accountType, const std::string& iban, long long ownerId, double amount);
	void deleteAccount(const std::string& iban);
	void listAccounts() const;
	void listCustomerAccount(long long customerId) const;
	void transfer(const std::string& fromIBAN, const std::string& toIBAN, double amount);
	void display() const;

private:
	Customer* getCustomerById(long long customerId) const;
	Account* getAccountByIban(const std::string& iban) const;
	Account* getAccountByOwnerId(long long ownerId) const;

	Account* createAccount(const std::string& accountType, const std::string& iban, long long ownerId, double amount) const;
private:
	void copyFrom(const Bank& other);
	void clear();
private:
	std::string name;
	std::string address;
	std::vector<Customer*> customers;
	std::vector<Account*> accounts;
};