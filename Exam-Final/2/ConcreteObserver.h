#pragma once
#include <string>

#include "Observer.h"

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(const std::string& name);

	virtual Observer* clone() const override;
	virtual void update(Currency* currency) const override;
private:
	std::string name;
};