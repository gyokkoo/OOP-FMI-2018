#pragma once

const int DEFAULT_VALUE = 12;

class Temperature
{
public:
	Temperature();
	Temperature(int min, int avg, int max);
	
	void setTemperatures(int min, int avg, int max);

	int getMin() const;
	int getAvg() const;
	int getMax() const;

	int getAmplitude() const;

	void print() const;
private:
	bool isValidTemperature(int min, int avg, int max);
private:
	int min;
	int avg;
	int max;
};

bool operator<(const Temperature& lhs, const Temperature& rhs);
bool operator>(const Temperature& lhs, const Temperature& rhs);
bool operator<=(const Temperature& lhs, const Temperature& rhs);
bool operator>=(const Temperature& lhs, const Temperature& rhs);
bool operator==(const Temperature& lhs, const Temperature& rhs);
bool operator!=(const Temperature& lhs, const Temperature& rhs);