#pragma once
#include "Bank.h"

class ConsoleMenu
{
public:
	ConsoleMenu(const Bank& bank);

	void printMenu();
	void readInput();
private:
	void interpretCommand(int command);
	
	void listCustomersCommand() const;
	void addNewCustomerCommand();
	void deleteCustomerCommand();
	void listAllAccountsCommand() const;
	void listCustomerAccountsCommand() const;
	void addNewAccountCommand();
	void deleteAccountCommand();
	void withdrawFromAccountCommand();
	void depositToAccountCommand(); 
	void transferCommand();
	void displayInfoForTheBankCommand() const;
	void quitCommand();

	long long readValidId() const;
	double readValidDouble() const;
private:
	Bank bank;
	bool isRunning;
};