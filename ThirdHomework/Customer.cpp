#include <iostream>
#include "Customer.h"

Customer::Customer(long long id, std::string name, std::string address)
{
	this->id = id;
	this->name = name;
	this->address = address;
}

void Customer::display() const
{
	std::cout 
		<< "| ID      : " << id << "\n"
		<< "| Name    : " << name << "\n"
		<< "| Address : " << address << "\n";
}

long long Customer::getId() const
{
	return this->id;
}

std::string Customer::getName() const
{
	return this->name;
}

std::string Customer::getAddress() const
{
	return this->address;
}
