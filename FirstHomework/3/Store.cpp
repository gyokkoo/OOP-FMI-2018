#include <iostream>
#include "Store.h"

Store::Store() : capacity(DEFAULT_CAPACITY)
{
	this->products = new Product[DEFAULT_CAPACITY];
	this->count = 0;
	this->idGenerator = 1;
}

Store::Store(const Store& other)
{
	this->copyFrom(other);
}

Store & Store::operator=(const Store& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

Store::~Store()
{
	this->clear();
}

void Store::addProduct()
{
	if (this->count >= this->capacity)
	{
		this->resizeArr(this->capacity * 2);
	}

	Product* product = &this->products[this->count];
	this->count++;

	product->setSKU(this->idGenerator++);
	this->readProductInput(product);

	std::cout << "Product was successfully added!\n";
}

void Store::deleteProduct(int sku)
{
	int indexToRemove = -1;
	for (int i = 0; i < this->count; i++)
	{
		if (this->products[i].getSKU() == sku)
		{
			indexToRemove = i;
		}
	}

	if (indexToRemove == -1)
	{
		std::cout << "The product with SKU " << sku << " does not exist!\n";
		return;
	}

	this->removeFromArray(indexToRemove);
	std::cout << "The product was removed!\n";

}

void Store::changeProduct(int sku)
{
	int indexToEdit = -1;
	for (int i = 0; i < this->count; i++)
	{
		if (this->products[i].getSKU() == sku)
		{
			indexToEdit = i;
		}
	}

	if (indexToEdit == -1)
	{
		std::cout << "The product with SKU " << sku << " does not exist!\n";
		return;
	}

	Product* product = &this->products[indexToEdit];
	this->readProductInput(product);

	std::cout << "The product was editted!\n";
}

void Store::printOnConsole() const
{
	std::cout << "-------Store-------\n";
	std::cout << "Total products: " << this->count << "\n";
	if (this->count == 0)
	{
		std::cout << "No products in the store!\n";
		return;
	}

	std::cout << "Products in the store:\n";
	for (int i = 0; i < this->count; i++)
	{
		this->products[i].printOnConsole();
	}
}

void Store::clear()
{
	delete[] this->products;
	this->products = nullptr;
	this->count = 0;
}

void Store::copyFrom(const Store& store)
{
	this->products = new Product[store.capacity];
	this->count = store.count;
	for (int i = 0; i < this->count; i++)
	{
		this->products[i] = store.products[i];
	}
}

void Store::resizeArr(int newCapacity)
{
	Product* temp = this->products;
	this->products = new Product[newCapacity];
	for (int i = 0; i < this->count; i++)
	{
		this->products[i] = temp[i];
	}
	delete[] temp;
}

void Store::readProductInput(Product* product)
{
	int count = 0;
	double price = 0.0;
	char* brand = nullptr;
	char* model = nullptr;
	char* category = nullptr;

	std::cout << "Enter brand (text): ";
	brand = this->readInput();
	product->setBrand(brand);
	delete[] brand;

	std::cout << "Enter product price (number): ";
	std::cin >> price;
	product->setPrice(price);

	std::cout << "Enter model (text): ";
	model = this->readInput();
	product->setModel(model);
	delete[] model;

	std::cout << "Enter product count (number): ";
	std::cin >> count;
	product->setCount(count);

	std::cout << "To add/edit category press C... ";
	char symbol;
	std::cin >> symbol;
	if (symbol == 'C' || symbol == 'c')
	{
		std::cout << "Enter category (text): ";
		category = this->readInput();
		product->setCategory(category);
		delete[] category;
	}
}

char* Store::readInput()
{
	int urlMaxSize = 10;
	char* inputStr = new char[urlMaxSize];
	int strIndex = 0;
	char c;
	std::cin.ignore();
	while (std::cin.get(c) && c != '\n')
	{
		if (strIndex >= urlMaxSize)
		{
			// Resize
			urlMaxSize *= 2;
			char* temp = inputStr;
			inputStr = new char[urlMaxSize];
			for (int i = 0; i < strIndex; i++)
			{
				inputStr[i] = temp[i];
			}
			delete[] temp;
		}

		inputStr[strIndex] = c;
		strIndex++;
	}
	inputStr[strIndex] = '\0';

	return inputStr;
}

void Store::removeFromArray(int index)
{
	if (index < 0 || index >= this->count)
	{
		std::cout << "Error! Invalid index!\n";
		return;
	}

	// shifting left
	int writeIndex = index;
	int readIndex = index + 1;
	while (readIndex < this->count)
	{
		this->products[writeIndex] = this->products[readIndex];
		writeIndex++;
		readIndex++;
	}
	this->count--;
}
