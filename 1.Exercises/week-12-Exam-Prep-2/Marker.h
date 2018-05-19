#pragma once
#include "WritingInstrument.h"

class Marker : public WritingInstrument
{
public:
	Marker();
	Marker(const Marker& other);
	Marker& operator=(const Marker& rhs);
	~Marker();

	const char* getColor() const;
	void setColor(const char* color);
private:
	char* color;
};

std::istream& operator>>(std::istream& is, Marker& marker);
std::ostream& operator<<(std::ostream& os, const Marker& marker);