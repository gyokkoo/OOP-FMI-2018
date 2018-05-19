#include <cstring>
#include "WritingInstrument.h"

WritingInstrument::WritingInstrument() : brand(nullptr), productionYear(0)
{
}

WritingInstrument::WritingInstrument(const WritingInstrument& other)
{
	this->setBrand(other.brand);
	this->setProductionYear(other.productionYear);
}

WritingInstrument & WritingInstrument::operator=(const WritingInstrument & rhs)
{
	if (this != &rhs)
	{
		this->setBrand(rhs.brand);
		this->setProductionYear(rhs.productionYear);
	}

	return *this;
}

WritingInstrument::~WritingInstrument()
{
	delete[] brand;
}

const char* WritingInstrument::getBrand() const
{
	if (this->brand == nullptr)
	{
		return "No brand\n";
	}

	return this->brand;
}

int WritingInstrument::getProductionYear() const
{
	return this->productionYear;
}

void WritingInstrument::setBrand(const char* brand)
{
	if (brand == nullptr)
	{
		std::cout << "Invalid brand!\n";
		this->brand = nullptr;
		return;
	}

	delete[] this->brand;
	int length = strlen(brand) + 1;
	this->brand = new char[length];
	strcpy_s(this->brand, length, brand);
}

void WritingInstrument::setProductionYear(int year)
{
	if (year < 0)
	{
		std::cout << "Invalid year!\n";
		this->productionYear = 0;
		return;
	}

	this->productionYear = year;
}

std::ostream& operator<<(std::ostream& os, const WritingInstrument& instrument)
{
	os << "Brand: " << instrument.getBrand() << "\n"
		<< "Production year: " << instrument.getProductionYear() << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, WritingInstrument& instrument)
{
	char buffer[1000];
	int year = 0;

	std::cout << "Enter brand name: ";
	is.getline(buffer, 1000);
	std::cout << "Enter production year: ";
	is >> year;
	instrument.setBrand(buffer);
	instrument.setProductionYear(year);

	return is;
}
