/**
*
* Solution to homework task
* Object-Oriented-Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 1
* @compiler VC
* @github https://github.com/Nezhdetov/
* @email gyokan.nezhdetov@gmail.com
*/

#include <iostream>

#include "Bank.h"
#include "ConsoleMenu.h"

void addInitialValues(Bank& bank)
{
	bank.addCustomer(1, "Ivan Ivanov", "Hristo Botev 154 blok 8");
	bank.addCustomer(2, "Dragan Draganov", "Dunav 4");
	bank.addCustomer(3, "Peter Smith", "Waterfall street 45");
	bank.addCustomer(10, "Georgi Georgiev", "Chinar 243");
	bank.addCustomer(11, "Peter Smith", "Kokiche 1");

	bank.addAccount("Current", "BG123", 1, 100.00);
	bank.addAccount("Current", "BG456", 10, 6005.99);
	bank.addAccount("Current", "BG789", 1, 10400.00);
}

int main()
{
	Bank bank("FMI Bank", "James Baucher 5");
	addInitialValues(bank);

	Bank copyBank(bank);
	ConsoleMenu menu(copyBank);
	menu.readInput();

	return 0;
}