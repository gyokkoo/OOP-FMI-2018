#include "Pencil.h"

int Pencil::getHardness() const
{
	return this->hardness;
}

void Pencil::setHardness(int hardness)
{
	if (hardness < 0 || hardness > 14)
	{
		std::cout << "Invalid hardness!\n";
		this->hardness = 0;
	}

	this->hardness = hardness;
}

std::istream& operator>>(std::istream& is, Pencil& pencil)
{
	int temp;
	is >> (WritingInstrument&) pencil;
	std::cout << "Enter hardness: ";
	is >> temp;
	pencil.setHardness(temp);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Pencil& pencil)
{
	os << (const WritingInstrument&)pencil;
	os << "Hardness: " << pencil.getHardness() << "\n";
	return os;
}
