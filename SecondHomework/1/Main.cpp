/**
*
* Solution to homework task
* Object-Oriented-Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 1
* @compiler VC
* @github https://github.com/Nezhdetov/
* @email gyokan.nezhdetov@gmail.com
*/

#include <iostream>
#include <cstring>
#include <assert.h>

#include "ElectricDevice.h"
#include "ElectricNet.h"

/*
* Function for testing Electric Device class with assertion
* Note: Do not change code, otherwise assertion may fail
*/
void testElectricDevice()
{
	// Test default constructor should have initial state
	ElectricDevice defaultDevice;
	assert(strcmp(defaultDevice.getName(), "Invalid name!\n") == 0);
	assert(defaultDevice.getkW() == 0);

	const char* deviceName = "Laptop";
	int devicekW = 55;

	// Test setters and getters should return correct value
	defaultDevice.setName(deviceName);
	defaultDevice.setkW(devicekW);
	assert(strcmp(defaultDevice.getName(), deviceName) == 0);
	assert(defaultDevice.getkW() == devicekW);

	// Test constructor with parameters should set correct values
	ElectricDevice deviceWithParams(deviceName, devicekW);
	assert(strcmp(deviceWithParams.getName(), deviceName) == 0);
	assert(deviceWithParams.getkW() == devicekW);

	// Test copy constructor should copy correctly
	ElectricDevice copyDevice(deviceWithParams);
	assert(strcmp(copyDevice.getName(), deviceName) == 0);
	assert(copyDevice.getkW() == devicekW);

	// Test assignment operator should assign correctly
	ElectricDevice assignmentDevice("TV", 900);
	assignmentDevice = deviceWithParams;
	assert(strcmp(assignmentDevice.getName(), deviceName) == 0);
	assert(assignmentDevice.getkW() == devicekW);

	// Test initializing with invalid state, should set to initial state
	ElectricDevice invalidDevice(nullptr, -1);
	assert(strcmp(invalidDevice.getName(), "Invalid name!\n") == 0);
	assert(invalidDevice.getkW() == 0);
}

/*
* Function for testing Electric Net class with assertion
* Note: Do not change code, otherwise assertion may fail
*/
void testElectricNet()
{
	int maxConsumption = 100;

	// Test constructor with parameters, should have correct initial state
	ElectricNet electricNet(maxConsumption);
	assert(electricNet.getMaxConsumption() == maxConsumption);
	assert(electricNet.getDevicesCount() == 0);
	assert(electricNet.getCurrentConsumption() == 0);
	assert(electricNet.getCapacity() == DEFAULT_CAPACITY);
	assert(!electricNet == false); // No devices in the net should be false

	// Test post-increment, pre-increment, post-decrement and pre-decrement operators
	// should manipulate max consumption correctly
	electricNet++;
	maxConsumption *= 2;
	assert(electricNet.getMaxConsumption() == maxConsumption);
	
	++electricNet;
	maxConsumption *= 2;
	assert(electricNet.getMaxConsumption() == maxConsumption);
	
	electricNet--;
	maxConsumption /= 2;
	assert(electricNet.getMaxConsumption() == maxConsumption);
	
	--electricNet;
	maxConsumption /= 2;
	assert(electricNet.getMaxConsumption() == maxConsumption);

	// Test adding device with operator+=, should add correctly
	const char* deviceName = "Air Conditioner";
	electricNet += ElectricDevice(deviceName, maxConsumption);
	
	assert(electricNet.getDevicesCount() == 1);
	assert(strcmp(electricNet[deviceName].getName(), deviceName) == 0);
	assert(electricNet[deviceName].getkW() == maxConsumption);
	assert(!electricNet == true);

	// Adding duplicate device, should not add
	electricNet += ElectricDevice(deviceName, maxConsumption);
	assert(electricNet.getDevicesCount() == 1);

	// Test copy constructor should copy correctly
	ElectricNet copyNet(electricNet);
	assert(copyNet.getDevicesCount() == 1);
	assert(strcmp(copyNet[deviceName].getName(), deviceName) == 0);
	assert(copyNet[deviceName].getkW() == maxConsumption);
	assert(!copyNet == true);
	
	// Test assignment operator, should assign correctly
	ElectricNet assignmentNet(0);
	assignmentNet = electricNet;
	assert(assignmentNet.getDevicesCount() == 1);
	assert(strcmp(assignmentNet[deviceName].getName(), deviceName) == 0);
	assert(assignmentNet[deviceName].getkW() == maxConsumption);
	assert(!assignmentNet == true);

	// Test operator+
	maxConsumption = 1000;
	ElectricDevice laptop("Laptop", 300);
	ElectricDevice oven("Oven", 400);
	ElectricDevice tv("TV", 300);
	ElectricNet house(maxConsumption);

	// Add three devices, should add and resize container correctly
	house = house + laptop;
	house = house + oven;
	house = house + tv;
	assert(house.getDevicesCount() == 3);
	assert(house.getCurrentConsumption() == (laptop.getkW() + oven.getkW() + tv.getkW()));
	assert(house.getMaxConsumption() == maxConsumption);
	assert(house.getCapacity() == DEFAULT_CAPACITY * 2); // Should resize the container by *2

	// Test operator[] should return correct device
	ElectricDevice houseDevice = house[laptop.getName()];
	assert(strcmp(houseDevice.getName(), laptop.getName()) == 0);
	assert(houseDevice.getkW() == laptop.getkW());

	// Test adding new device with overload net, should not add
	ElectricDevice charger("iPhone charger", 1);
	house += charger;
	assert(house.getDevicesCount() == 3);
	assert(house.getCurrentConsumption() == (laptop.getkW() + oven.getkW() + tv.getkW()));
	assert(house.getMaxConsumption() == maxConsumption);
	assert(house.getCapacity() == DEFAULT_CAPACITY * 2);

	// Test removing device with operator-=, should remove correctly
	house -= laptop;
	assert(house.getDevicesCount() == 2);
	assert(house.getCurrentConsumption() == (oven.getkW() + tv.getkW()));

	// Test removing device with operator-, should remove correctly
	house = house - tv;
	assert(house.getDevicesCount() == 1);
	assert(house.getCurrentConsumption() == oven.getkW());

	// Test removing invalid device, should not remove
	house -= tv;
	assert(house.getDevicesCount() == 1);
	assert(house.getCurrentConsumption() == oven.getkW());
}

int main()
{
	// Comment if assertion fails
	testElectricDevice();
	testElectricNet();

	std::cout << "__________________\n";
	std::cout << "All assertion passed!\n";
	std::cout << "__________________\n";

	ElectricDevice conditioner("Air Conditioner", 341);
	ElectricDevice laptop("Laptop Acer", 55);
	ElectricDevice refrigerator("Roper refrigerator", 200);

	ElectricNet smartHome(10000);
	smartHome += conditioner;
	smartHome += laptop;
	smartHome += refrigerator;
	smartHome += ElectricDevice("Charger for phone", 5);
	smartHome += ElectricDevice("Crypto Mining PC", 2000);
	smartHome += ElectricDevice("Heater", 900);
	smartHome += ElectricDevice("Neighborhood net", 8000); // Network overload, should not add!

	smartHome.print();
	std::cout << "-------------------------\n";

	smartHome -= conditioner;
	smartHome -= laptop;
	smartHome -= refrigerator;
	smartHome.print();

	return 0;
}