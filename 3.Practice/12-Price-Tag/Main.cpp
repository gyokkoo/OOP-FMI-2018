#include <iostream>

#include "PriceTag.h"
#include "PriceCatalog.h"

int main()
{
	PriceTag<double> hlqb(0.79);

	PriceTag<double> sudzuk(25.34);
	sudzuk.discount(20);

	PriceTag<double> kashkaval;
	std::cin >> kashkaval;

	PriceCatalog<double> billa;
	billa += hlqb;
	billa += sudzuk;
	billa += kashkaval;

	std::cout << billa << "\n";
	return 0;
}