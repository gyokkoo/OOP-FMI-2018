#pragma once
#include "Currency.h"

class Observer
{
public:
	virtual ~Observer()
	{
	}

	virtual Observer* clone() const = 0;

	virtual void update(Currency* currency) const = 0;
};