#include <iostream>
#include "Egg.h"
#include "Basket.h"

int main()
{
	Basket gosho("gosho");

	gosho.addEgg("Jyltyka");
	gosho.addEgg("Beltycheto");
	gosho.addEgg("Smalcho");
	gosho.addEgg("Gigantsko");

	gosho.generateReport();

	return 0;
}