#include <iostream>
#include "Store.h"

void printMenu()
{
	std::cout << "|--- Main Menu ---|\n";
	std::cout << "A - Add new product\n";
	std::cout << "X - Delete product\n";
	std::cout << "C - Change product\n";
	std::cout << "D - Display product\n";
	std::cout << "Q - Quit\n";
	std::cout << "Please choose: ";
}

void startMenu(Store& store)
{
	char choice;
	do
	{
		printMenu();
		int id = -1;
		std::cin >> choice;
		switch (choice)
		{
		case 'A':
			store.addProduct();
			break;
		case 'X':
			std::cout << "Enter Product SKU to delete:\n";
			std::cin >> id;
			store.deleteProduct(id);
			break;
		case 'C':
			std::cout << "Enter Product SKU to edit:\n";
			std::cin >> id;
			store.changeProduct(id);
			break;
		case 'D':
			store.printOnConsole();
			break;
		case 'Q':
			std::cout << "Quitting...\n";
			break;
		default:
			std::cout << "Invalid command!\n";
			break;
		}
	} while (choice != 'Q');
}

int main()
{
	Store store;

	startMenu(store);

	return 0;
}
