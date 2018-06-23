#include <iostream>
#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver(const std::string& name)
{
	this->name = name;
}

Observer* ConcreteObserver::clone() const
{
	return new ConcreteObserver(*this);
}

void ConcreteObserver::update(Currency* currency) const
{
	// Will call std::ostream& for currency class
	std::cout << "Update " << this->name << " " << *currency << "\n";
}
