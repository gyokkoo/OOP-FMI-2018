#include <iostream>
#include "Product.h"

// Initializing static field

Product::Product()
{
	this->sku = 0;
	this->brand = nullptr;
	this->model = nullptr;
	this->price = 0;
	this->count = 0;
	this->category = nullptr;
}

Product::Product(const Product& other)
{
	this->copy(other);
}

Product::~Product()
{
	this->clear();
}

Product& Product::operator=(const Product& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copy(rhs);
	}

	return *this;
}

int Product::getSKU() const
{
	return this->sku;
}

const char* Product::getBrand() const
{
	if (this->brand == nullptr)
	{
		return "Not Available";
	}

	return this->brand;
}

const char* Product::getModel() const
{
	if (this->model == nullptr)
	{
		return "Model not available";
	}

	return this->model;
}

const char* Product::getCategory() const
{
	if (this->category == nullptr)
	{
		return "Category not available";
	}

	return this->category;
}

double Product::getPrice() const
{
	return this->price;
}

int Product::getCount() const
{
	return this->count;
}

void Product::setSKU(int id)
{
	this->sku = id;
}

void Product::setBrand(const char* brand)
{
	this->copyString(this->brand, brand);
}

void Product::setModel(const char* model)
{
	this->copyString(this->model, model);
}

void Product::setCategory(const char* category)
{
	this->copyString(this->category, category);
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setCount(int count)
{
	this->count = count;
}

void Product::printOnConsole() const
{
	if (this->brand == nullptr || this->model == nullptr)
	{
		std::cout << "Error! Invalid product!\n";
	}

	std::cout << "---->Product ID: ->[" << this->sku << "]<-\n"
		<< "--------> Brand: " << this->brand << "\n"
		<< "--------> Model: " << this->model << "\n"
		<< "--------> Price: " << this->price << " leva\n"
		<< "--------> Count: " << this->count << "\n";

	if (this->category != nullptr)
	{
		std::cout << "--------> Category: " << this->category << "\n";
	}

	std::cout << "------------------------------\n";
}

void Product::clear()
{
	delete[] this->brand;
	this->brand = nullptr;
	
	delete[] this->model;
	this->model = nullptr;

	delete[] this->category;
	this->category = nullptr;
}

void Product::copy(const Product& other)
{
	this->sku = other.sku;
	this->copyString(this->brand, other.brand);
	this->copyString(this->model, other.model);
	this->price = other.price;
	this->count = other.count;
	this->copyString(this->category, other.category);
}

void Product::copyString(char*& destination, const char* source)
{
	if (source == nullptr)
	{
		return;
	}

	int length = this->strlen(source);
	destination = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}

	destination[length] = '\0';
}

int Product::strlen(const char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	int index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return index;
}
