#include <iostream>
#include <assert.h>

#include "Forecast.h"

int main()
{
	Temperature defaultTemperature;
	defaultTemperature.print();
	Temperature temperatureA(15, 19, 26);
	temperatureA.print();
	Temperature temperatureB(15, 19, 26);
	temperatureB.print();

	if (temperatureA == temperatureB)
	{
		std::cout << "Temp A and Temp B are equal! \n";
	}

	Forecast capitalCity("Grad Sofia", temperatureA);
	std::cout << capitalCity;
	Forecast hotDay("Grad Sofia", Temperature(26, 33, 38));
	Forecast coldDay("Grad Sofia", Temperature(-10, -5, 0));

	capitalCity.updateIfHotter(hotDay);
	std::cout << capitalCity;

	capitalCity.updateIfHotter(coldDay);
	std::cout << capitalCity;

	Forecast emptyForecast;
	std::cout << emptyForecast;
	
	std::cout << "\nUser input: \n";
	std::cin >> emptyForecast;
	std::cout << emptyForecast;

	return 0;
}