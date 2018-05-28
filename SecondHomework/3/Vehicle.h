#pragma once
#include <iostream>
#include "Color.h"

class Vehicle
{
public:
	Vehicle();
	Vehicle(const char* make, const char* model, Color color, int year, int mileage);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& rhs);
	virtual ~Vehicle();

	const char* getMake() const;
	const char* getModel() const;
	Color getColor() const;
	int getYear() const;
	int getMileage() const;

	void setMake(const char* make);
	void setModel(const char* model);
	void setColor(Color color);
	void setYear(int year);
	void setMileage(int mileage);

	virtual void details() const;
private:
	void setString(char*& destination, const char* source);
	void copyFrom(const Vehicle& other);
	void clear();
private:
	char* make;
	char* model;
	Color color;
	int year;
	int mileage;
};