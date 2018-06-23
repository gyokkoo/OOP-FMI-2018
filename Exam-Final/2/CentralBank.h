#pragma once
#include <string>
#include <vector>

#include "Currency.h"
#include "Observer.h"

class CentralBank
{
public:
	CentralBank();
	CentralBank(const std::string& name);
	CentralBank(const CentralBank& other);
	CentralBank& operator=(const CentralBank& rhs);
	~CentralBank();

	void addCurrency(Currency* currency);
	void addCurrency(const std::string& name, double rate);

	void deleteCurrency(size_t index); // By index
	void deleteCurrency(const std::string& name); // By name

	void setRate(const std::string& name, double rate);

	void registerObserver(Observer* observer);
	void unregister(size_t index);
	void notify(Currency* currency);

	void print() const; // for testing
private:
	size_t getCurrencyByName(const std::string& name) const;
	void copyFrom(const CentralBank& other);
	void clear();
private:
	std::string name;
	std::vector<Currency*> currencies;
	std::vector<Observer*> observers;
};