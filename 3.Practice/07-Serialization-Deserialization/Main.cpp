#include <iostream>
#include "Egg.h"
#include "Basket.h"

int main()
{
	Basket gosho("gosho");

	gosho.addEgg(Egg("Jyltyka"));
	gosho.addEgg(Egg("Beltycheto"));
	gosho.addEgg(Egg("Smalcho"));
	gosho.addEgg(Egg("Gigantsko"));
	
	gosho.removeEgg(Egg("Smalcho"));
	
	gosho.serialization();
	gosho.deserialization();

	gosho.generateReport();

	return 0;
}