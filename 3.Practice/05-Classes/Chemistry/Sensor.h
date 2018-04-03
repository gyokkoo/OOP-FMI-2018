#pragma once

class Sensor
{
public:
	Sensor();
	Sensor(const char* description);
	Sensor(const Sensor& sensor);
	~Sensor();

	Sensor & operator=(const Sensor& s); //assignment operator

	int getId() const;
	double getTemperature() const;
	const char* getDescription() const;

	void setTemperature(double temperature);
	void setDescription(const char* description);
private:
	int id;
	double temperature;
	char* description;
};