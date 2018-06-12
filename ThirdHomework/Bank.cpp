#include <iostream>
#include <algorithm>

#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Bank.h"

Bank::Bank()
{
	this->name = "No name\n";
	this->address = "No address\n";
}

Bank::Bank(const std::string& name, const std::string& address)
{
	this->name = name;
	this->address = address;
}

Bank::Bank(const Bank& bank)
{
	this->copyFrom(bank);
}

Bank& Bank::operator=(const Bank& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

Bank::~Bank()
{
	this->clear();
}

const std::string& Bank::getName() const
{
	return this->name;
}

const std::string& Bank::getAddress() const
{
	return this->address;
}

void Bank::setName(const std::string& name)
{
	this->name = name;
}

void Bank::setAddress(const std::string& address)
{
	this->address = address;
}

void Bank::withdrawFromAccount(const std::string& iban, double amount)
{
	Account* accountToWithdraw = this->getAccountByIban(iban);
	if (accountToWithdraw == nullptr)
	{
		std::cout << "Account with iban " << iban << " does not exist!\n";
		return;
	}

	if (accountToWithdraw->withdraw(amount))
	{
		std::cout << amount << " euro successfully withdrawn from " << iban << "\n";
	}
	else
	{
		std::cout << iban << " account has not enough money to withdraw " << amount << " euro!\n";
	}
}

void Bank::depositToAccount(const std::string& iban, double amount)
{
	Account* accountToDeposit = this->getAccountByIban(iban);
	if (accountToDeposit == nullptr)
	{
		std::cout << "Account with iban " << iban << " does not exist!\n";
		return;
	}

	if (amount < 0)
	{
		std::cout << "Cannot deposit negative amount!\n";
		return;
	}

	accountToDeposit->deposit(amount);
	std::cout << amount << " euro successfully deposited for " << iban << "\n";
}

void Bank::addCustomer(long long customerId, const std::string& name, const std::string& address)
{
	if (this->getCustomerById(customerId) != nullptr)
	{
		std::cout << "\nCustomer with id: " << customerId << " already exists!\n";
		return;
	}
	
	Customer* customer = new Customer(customerId, name, address);
	this->customers.push_back(customer);
	std::cout << "\nCustomer " << name << " was successfully added!\n";
}

void Bank::listCustomers() const
{
	if (this->customers.size() == 0)
	{
		std::cout << "No customers in the bank!\n";
		return;
	}

	std::cout << "All customer in the bank:\n";
	for (size_t i = 0; i < this->customers.size(); i++)
	{
		std::cout << "|_____________________\n";
		this->customers[i]->display();
	}
}

void Bank::deleteCustomer(long long customerId)
{
	Customer* customerToDelete = this->getCustomerById(customerId);
	if (customerToDelete == nullptr)
	{
		std::cout << "Customer with id " << customerId << "does not exist!\n";
		return;
	}
		
	// Remove the customer pointer from the vector
	this->customers.erase(std::remove(customers.begin(), customers.end(), customerToDelete), customers.end());
	delete customerToDelete;

	// Remove customer all accounts
	Account* accountToDelete = this->getAccountByOwnerId(customerId);
	while (accountToDelete != nullptr)
	{
		this->accounts.erase(std::remove(accounts.begin(), accounts.end(), accountToDelete), accounts.end());
		delete accountToDelete;

		// Find next account
		accountToDelete = this->getAccountByOwnerId(customerId);
	}

	std::cout << "Customer with id " << customerId << " was deleted!\n";
}

void Bank::addAccount(const std::string& accountType, const std::string& iban, long long ownerId, double amount)
{
	if (this->getCustomerById(ownerId) == nullptr)
	{
		std::cout << "Error! Customer with id " << ownerId << " does not exist!\n";
		return;
	}

	if (this->getAccountByIban(iban) != nullptr)
	{
		std::cout << "Error! Account with iban " << iban << " already exists!\n";
		return;
	}

	Account* account = this->createAccount(accountType, iban, ownerId, amount);
	this->accounts.push_back(account);
	std::cout << "\nAccount with iban " << iban << " was successfully added!\n";
}

void Bank::deleteAccount(const std::string& iban)
{
	Account* accountToDelete = this->getAccountByIban(iban);
	if (accountToDelete == nullptr)
	{
		std::cout << "Account with iban " << iban << " does not exist!\n";
		return;
	}

	this->accounts.erase(std::remove(accounts.begin(), accounts.end(), accountToDelete), accounts.end());
	delete accountToDelete;
	std::cout << "Account with iban " << iban << " was deleted!\n";
}

void Bank::listAccounts() const
{
	if (this->accounts.size() == 0)
	{
		std::cout << "No accounts!\n";
		return;
	}

	for (size_t i = 0; i < this->accounts.size(); i++)
	{
		std::cout << "|_____________________\n";
		this->accounts[i]->display();
	}
}

void Bank::listCustomerAccount(long long customerId) const
{
	if (this->getCustomerById(customerId) == nullptr)
	{
		std::cout << "Customer with id " << customerId << "does not exist!\n";
		return;
	}

	for (size_t i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->getOwnerId() == customerId)
		{
			this->accounts[i]->display();
		}
	}
}

void Bank::transfer(const std::string& fromIBAN, const std::string& toIBAN, double amount)
{
	Account* sender = this->getAccountByIban(fromIBAN);
	Account* reciever = this->getAccountByIban(toIBAN);

	if (sender == nullptr || reciever == nullptr)
	{
		std::cout << "Transfer failed! Invalid sender or reciever IBAN\n";
		return;
	}

	bool isWithdrawn = sender->withdraw(amount);
	if (isWithdrawn)
	{
		reciever->deposit(amount);
		std::cout << "Successfully transfered from " << fromIBAN << " to " << toIBAN << " - " << amount << " euro.\n";
	}
	else
	{
		std::cout << "Transfer failed! Sender " << sender << " has not enough money\n";
	}
}

void Bank::display() const
{
	std::cout << "-----Bank-----\n"
		<< "Name: " << this->getName() << "\n"
		<< "Address: " << this->getAddress() << "\n";
	this->listCustomers();
	this->listAccounts();

}

Customer* Bank::getCustomerById(long long customerId) const
{
	for (size_t i = 0; i < this->customers.size(); i++)
	{
		if (this->customers[i]->getId() == customerId)
		{
			return this->customers[i];
		}
	}

	return nullptr;
}

Account* Bank::getAccountByIban(const std::string& iban) const
{
	for (size_t i = 0; i < this->accounts.size(); i++)
	{
		if (!this->accounts[i]->getIban().compare(iban))
		{
			return this->accounts[i];
		}
	}

	return nullptr;
}

Account* Bank::getAccountByOwnerId(long long ownerId) const
{
	for(size_t i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->getOwnerId() == ownerId)
		{
			return this->accounts[i];
		}
	}

	return nullptr;
}

Account* Bank::createAccount(const std::string& accountType, const std::string& iban, long long ownerId, double amount) const
{
	double overdraft = 0;
	double interestRate = 0;
	switch (accountType[0])
	{
		case 'p':
		case 'P':
			std::cout << "Enter overdraft (number): ";
			std::cin >> overdraft;
			return new PrivilegeAccount(iban, ownerId, amount, overdraft);
		case 's':
		case 'S':
			std::cout << "Enter interest rate (number): ";
			std::cin >> interestRate;
			return new SavingsAccount(iban, ownerId, amount, interestRate);
		case 'c':
		case 'C':
			return new CurrentAccount(iban, ownerId, amount);
		default:
			std::cout << "Invalid account type!\n";
			return nullptr;
	}
}

void Bank::copyFrom(const Bank& other)
{
	this->name = other.name;
	this->address = other.address;

	for (size_t i = 0; i < other.customers.size(); ++i)
	{
		Customer* temp = other.customers[i];
		this->customers.push_back(new Customer(*temp));
	}

	for (size_t i = 0; i < other.accounts.size(); ++i)
	{
		this->accounts.push_back(other.accounts[i]->clone());
	}
}

void Bank::clear()
{
	for (size_t i = 0; i < this->accounts.size(); i++)
	{
		delete accounts[i];
	}
	this->accounts.clear();

	for (size_t i = 0; i < this->customers.size(); i++)
	{
		delete customers[i];
	}
	this->customers.clear();
}
