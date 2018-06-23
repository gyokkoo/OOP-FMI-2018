#include <iostream>
#include <string>

#include "Currency.h"
#include "CentralBank.h"
#include "ConcreteObserver.h"

int main()
{
	// Currency class that has name and rate
	Currency* lev = new Currency("Leva", 0.53);
	Currency* euro = new Currency("Euro", 1.34);
	Currency* paund = new Currency("Paund", 2.21);
	Currency* dolar = new Currency("Dolar", 1);

	CentralBank bnb("BNB");

	bnb.addCurrency(lev);
	bnb.addCurrency(euro);
	bnb.addCurrency(paund);
	bnb.addCurrency(dolar);

	
	Observer* novaTV = new ConcreteObserver("Nova TV");
	Observer* vestnikDnes = new ConcreteObserver("Vestnik dnes");
	Observer* europeTV = new ConcreteObserver("Europe TV");

	bnb.registerObserver(novaTV);
	bnb.registerObserver(vestnikDnes);
	bnb.registerObserver(europeTV);

	bnb.print();

	bnb.setRate("Leva", 0.56);

	std::cout << "Removed vestnik dnes from observers!\n";

	bnb.unregister(1); // Remove second observer

	bnb.deleteCurrency(dolar->getName()); // Remove dollars from currency

	bnb.setRate("Paund", 2.43);
	bnb.setRate("Leva", 0.76);

	// Clear memory
	delete lev;
	delete euro;
	delete paund;
	delete dolar;
	delete novaTV;
	delete vestnikDnes;
	delete europeTV;

	return 0;
}