#pragma once
#include <iostream>

class WritingInstrument
{
public:
	WritingInstrument();
	WritingInstrument(const WritingInstrument& other);
	WritingInstrument& operator=(const WritingInstrument& rhs);
	~WritingInstrument();

	const char* getBrand() const;
	int getProductionYear() const;

	void setBrand(const char* brand);
	void setProductionYear(int year);
private:
	char* brand;
	int productionYear;
};

std::ostream& operator<<(std::ostream& os, const WritingInstrument& instrument);
std::istream& operator>>(std::istream& is, WritingInstrument& instrument);