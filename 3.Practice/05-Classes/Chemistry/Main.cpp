#include <iostream>
#include "Sensor.h"
#include "Lab.h"

int main()
{
	Sensor firstSensor;
	firstSensor.setId(125431);
	firstSensor.setDescription("Sensor near door");
	firstSensor.setTemperature(36);

	Sensor secondSensor(123122, "Sensor near window");
	secondSensor.setTemperature(56);

	Sensor thirdSensor(103543, "Sensor left corner");
	thirdSensor.setTemperature(43);

	Sensor fourthSensor(103543, "Sensor right corner");
	thirdSensor.setTemperature(140);

	Lab mainLab("Room 604");
	mainLab.addSensor(firstSensor);
	mainLab.addSensor(secondSensor);
	mainLab.addSensor(thirdSensor);
	mainLab.addSensor(fourthSensor);

	std::cout << "Average temperature: "
		<< mainLab.getAverageTemperature() << "\n";

	return 0;
}