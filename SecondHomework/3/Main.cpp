/**
*
* Solution to homework task
* Object-Oriented-Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 3
* @compiler VC
* @github https://github.com/Nezhdetov/
* @email gyokan.nezhdetov@gmail.com
*/

#include <iostream>
#include <assert.h>

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

void testVehicleClass()
{
	// Test default constructor, should have initial state
	Vehicle vehicle;
	assert(strcmp(vehicle.getMake(), "No Make") == 0);
	assert(strcmp(vehicle.getModel(), "No Model") == 0);
	assert(vehicle.getYear() == 0);
	assert(vehicle.getColor() == -1);
	assert(vehicle.getMileage() == 0);

	// Test setters, should set values properly
	const char* make = "Mercedes-benz";
	const char* model = "E20";
	int year = 2003;
	Color color = Color::WHITE;
	int mileage = 120000;
	
	vehicle.setMake(make);
	vehicle.setModel(model);
	vehicle.setColor(color);
	vehicle.setYear(year);
	vehicle.setMileage(mileage);

	assert(strcmp(vehicle.getMake(), make) == 0);
	assert(strcmp(vehicle.getModel(), model) == 0);
	assert(vehicle.getYear() == year);
	assert(vehicle.getColor() == color);
	assert(vehicle.getMileage() == mileage);

	// Test constructor with parameters, should set values properly
	Vehicle mercedes(make, model, color, year, mileage);
	assert(strcmp(mercedes.getMake(), make) == 0);
	assert(strcmp(mercedes.getModel(), model) == 0);
	assert(mercedes.getYear() == year);
	assert(mercedes.getColor() == color);
	assert(mercedes.getMileage() == mileage);

	// Test copy constructor, should copy correctly
	Vehicle copyMercedes(mercedes);
	assert(strcmp(copyMercedes.getMake(), make) == 0);
	assert(strcmp(copyMercedes.getModel(), model) == 0);
	assert(copyMercedes.getYear() == year);
	assert(copyMercedes.getColor() == color);
	assert(copyMercedes.getMileage() == mileage);

	// Test assignment operator, should assign properly
	Vehicle assignMercedes;
	assignMercedes = mercedes;
	assert(strcmp(assignMercedes.getMake(), make) == 0);
	assert(strcmp(assignMercedes.getModel(), model) == 0);
	assert(assignMercedes.getYear() == year);
	assert(assignMercedes.getColor() == color);
	assert(assignMercedes.getMileage() == mileage);
}

int main()
{
	testVehicleClass();

	Vehicle* audiA8 = new Car("Audi", "A8", Color::BLACK, 2009, 40000);
	audiA8->details();
	delete audiA8;

	Vehicle* mercedesTruck = new Truck("Mercedes", "Actros 1844", Color::WHITE, 2008, 500000, 6);
	mercedesTruck->details();
	delete mercedesTruck;

	Vehicle* ducatiMotorcycle = new Motorcycle("Ducati", "Multistrada enduro", Color::GREY, 2016, 100, "Touring");
	ducatiMotorcycle->details();
	delete ducatiMotorcycle;

	return 0;
}