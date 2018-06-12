#include <iostream>
#include "ConsoleMenu.h"

ConsoleMenu::ConsoleMenu(const Bank& bank)
{
	this->bank = bank;
	this->isRunning = true;
}

void ConsoleMenu::printMenu()
{
	std::cout << "\n---------------MENU---------------\n";
	std::cout << "|1     List customers            |\n";
	std::cout << "|2     Add new customer          |\n";
	std::cout << "|3     Delete customer           |\n";
	std::cout << "|4     List all accounts         |\n";
	std::cout << "|5     List customer accounts    |\n";
	std::cout << "|6     Add new account           |\n";
	std::cout << "|7     Delete account            |\n";
	std::cout << "|8     Withdraw from account     |\n";
	std::cout << "|9     Deposit to account        |\n";
	std::cout << "|10    Transfer                  |\n";
	std::cout << "|11    Display info for the bank |\n";
	std::cout << "|12    Quit                      |\n";
	std::cout << "----------------------------------\n";
}

void ConsoleMenu::readInput()
{
	while (this->isRunning)
	{
		this->printMenu();
		std::cout << "|Enter a command between 1 and 12|\n";
		int command = (int)this->readValidId();
		std::cout << "\n";
		interpretCommand(command);
		std::cout << "\n";
	}
}

void ConsoleMenu::interpretCommand(int command)
{
	switch (command)
	{
	case 1:
		this->listCustomersCommand();
		break;
	case 2:
		this->addNewCustomerCommand();
		break;
	case 3:
		this->deleteCustomerCommand();
		break;
	case 4:
		this->listAllAccountsCommand();
		break;
	case 5:
		this->listCustomerAccountsCommand();
		break;	
	case 6:
		this->addNewAccountCommand();
		break;
	case 7:
		this->deleteAccountCommand();
		break;
	case 8:
		this->withdrawFromAccountCommand();
		break;
	case 9:
		this->depositToAccountCommand();
		break;
	case 10:
		this->transferCommand();
		break;
	case 11:
		this->displayInfoForTheBankCommand();
		break;
	case 12:
		this->quitCommand();
		break;
	default:
		std::cout << "Invalid command!\n";
		break;
	}
}

void ConsoleMenu::listCustomersCommand() const
{
	this->bank.listCustomers();
}

void ConsoleMenu::addNewCustomerCommand()
{
	long long customerId;
	std::string name;
	std::string address;
	
	std::cout << "Please enter:\n";
	std::cout << "Customer ID (number): ";
	customerId = this->readValidId();
	std::cout << "Customer name: ";
	std::getline(std::cin, name);
	std::cout << "Customer address: ";
	std::getline(std::cin, address);

	this->bank.addCustomer(customerId, name, address);
}

void ConsoleMenu::deleteCustomerCommand()
{
	long long customerId = 0;
	std::cout << "Please enter customer id to delete:\n";
	std::cout << "Customer id:";
	std::cin >> customerId;
	this->bank.deleteCustomer(customerId);
}

void ConsoleMenu::listAllAccountsCommand() const
{
	this->bank.listAccounts();
}

void ConsoleMenu::listCustomerAccountsCommand() const
{
	std::cout << "Enter customer ID: ";
	long long customerId = this->readValidId();
	this->bank.listCustomerAccount(customerId);
}

void ConsoleMenu::addNewAccountCommand()
{
	std::string accountType;
	std::string iban;
	long long ownerId;
	double amount;
	
	std::cout << "Enter account type [Current, Privilege or Savings]: ";
	std::getline(std::cin, accountType);
	std::cout << "Enter account iban: ";
	std::getline(std::cin, iban);
	std::cout << "Enter ownerId (number) : ";
	ownerId = this->readValidId();
	std::cout << "Enter amount in euro: ";
	amount = this->readValidDouble();

	this->bank.addAccount(accountType, iban, ownerId, amount);
}

void ConsoleMenu::deleteAccountCommand()
{
	std::string iban;
	std::cout << "Enter iban to delete:\n";
	std::getline(std::cin, iban);
	this->bank.deleteAccount(iban);
}

void ConsoleMenu::withdrawFromAccountCommand()
{
	std::string iban;
	std::cout << "Enter account IBAN\n";
	std::getline(std::cin, iban);

	double amount = this->readValidDouble();
	while (amount < 0)
	{
		std::cout << "Enter amount: \n";
		amount = this->readValidDouble();
		if (amount < 0)
		{
			std::cout << "Cannot withdraw negative amount, please re-enter!\n";
		}
	}

	this->bank.withdrawFromAccount(iban, amount);
}

void ConsoleMenu::depositToAccountCommand()
{
	std::string iban;
	std::cout << "Enter account IBAN\n";
	std::getline(std::cin, iban);

	double amountToDeposit = this->readValidDouble();

	this->bank.depositToAccount(iban, amountToDeposit);
}

void ConsoleMenu::transferCommand()
{
	std::string sender;
	std::string reciever;
	double amount = 0;
	std::cout << "Enter sender account IBAN\n";
	std::getline(std::cin, sender);

	std::cout << "Enter receiver account IBAN\n";
	std::getline(std::cin, reciever);

	std::cout << "Enter amount in euro: ";
	amount = this->readValidDouble();

	this->bank.transfer(sender, reciever, amount);
}

void ConsoleMenu::displayInfoForTheBankCommand() const
{
	this->bank.display();
}

void ConsoleMenu::quitCommand()
{
	this->isRunning = false;
	std::cout << "Qutting...\n";
}

long long ConsoleMenu::readValidId() const
{
	long long id = 0;
	while (true)
	{
		std::cin >> id;
		if (std::cin.good())
		{
			std::cin.get();
			return id;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input! Please re-enter.\n";
	}
}

double ConsoleMenu::readValidDouble() const
{
	double amount = 0;
	while (true)
	{
		std::cin >> amount;
		if (std::cin.good() && amount >= 0)
		{
			std::cin.get();
			return amount;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid amount! Please re-enter.\n";
	}
}
