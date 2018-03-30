#pragma once

class Sensor
{
public:
	Sensor();
	Sensor(int id, const char* description);
	Sensor(const Sensor& sensor);
	~Sensor();

	Sensor & operator=(const Sensor& s); //assignment operator

	int getId() const;
	double getTemperature() const;
	const char* getDescription() const;

	void setId(int id);
	void setTemperature(double temperature);
	void setDescription(const char* description);
private:
	int id;
	double temperature;
	char* description;
};