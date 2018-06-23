#include <iostream>
#include "CentralBank.h"

CentralBank::CentralBank()
{
	this->name = "No name";
}

CentralBank::CentralBank(const std::string & name)
{
	this->name = name;
}

CentralBank::CentralBank(const CentralBank & other)
{
	this->copyFrom(other);
}

CentralBank & CentralBank::operator=(const CentralBank & rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

CentralBank::~CentralBank()
{
	this->clear();
}

void CentralBank::addCurrency(Currency* currency)
{
	this->currencies.push_back(new Currency(*currency));
}

void CentralBank::addCurrency(const std::string & name, double rate)
{
	this->currencies.push_back(new Currency(name, rate));
}

void CentralBank::deleteCurrency(size_t index)
{
	if (index >= this->currencies.size())
	{
		std::cout << "Cannot delete, invalid index!\n";
		return;
	}

	Currency* currencyToDelete = this->currencies[index];
	this->currencies.erase(this->currencies.begin() + index);
	delete currencyToDelete;
}

void CentralBank::deleteCurrency(const std::string & name)
{
	size_t indexToDelete = this->getCurrencyByName(name);
	if (indexToDelete == -1)
	{
		std::cout << "Cannot find currency with name " << name << " \n";
		return;
	}

	this->deleteCurrency(indexToDelete);
}

void CentralBank::setRate(const std::string & name, double rate)
{
	size_t index = this->getCurrencyByName(name);
	if (index == -1)
	{
		std::cout << "The currency does not exist!\n";
		return;
	}

	Currency* currencyToUpdate = this->currencies[index];
	currencyToUpdate->setRate(rate);

	this->notify(currencyToUpdate);
}

void CentralBank::registerObserver(Observer * observer)
{
	// Adding copy pointer
	this->observers.push_back(observer->clone());
}

void CentralBank::unregister(size_t index)
{
	if (index >= this->observers.size())
	{
		std::cout << "Cannot delete, invalid index!\n";
		return;
	}

	Observer* observerToDelete = this->observers[index];
	this->observers.erase(this->observers.begin() + index);
	delete observerToDelete;
}

void CentralBank::notify(Currency * currency)
{
	for (size_t i = 0; i < this->observers.size(); ++i)
	{
		this->observers[i]->update(currency);
	}
}

void CentralBank::print() const
{
	std::cout << "Bank name: " << this->name << "\n";
	std::cout << "Currencies: \n";
	for (size_t i = 0; i < this->currencies.size(); ++i)
	{
		std::cout << " ---- " << *this->currencies[i] << "\n";
	}
}

size_t CentralBank::getCurrencyByName(const std::string& name) const
{
	for (size_t i = 0; i < this->currencies.size(); ++i)
	{
		if (name == this->currencies[i]->getName())
		{
			return i;
		}
	}

	return -1;
}

void CentralBank::copyFrom(const CentralBank & other)
{
	this->name = other.name;
	for (size_t i = 0; i < other.currencies.size(); ++i)
	{
		// Assume that in future there will no have currency derived classes
		// Create copy of currency 
		this->currencies.push_back(new Currency(*other.currencies[i]));
	}

	for (size_t i = 0; i < other.observers.size(); ++i)
	{
		// Clone observers
		this->observers.push_back(other.observers[i]->clone());
	}
}

void CentralBank::clear()
{
	// Delete currencies
	for (size_t i = 0; i < this->currencies.size(); ++i)
	{
		delete this->currencies[i];
	}
	this->currencies.clear();

	// Delete observers
	for (size_t i = 0; i < this->observers.size(); ++i)
	{
		delete this->observers[i];
	}
	this->observers.clear();
}
