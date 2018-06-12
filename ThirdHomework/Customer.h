#pragma once
#include <string>

class Customer
{
public:
	Customer(long long id, std::string name, std::string address);

	void display() const;

	long long getId() const;
	std::string getName() const;
	std::string getAddress() const;
private:
	long long id;
	std::string name;
	std::string address;
};