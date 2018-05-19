#pragma once
#include "WritingInstrument.h"

class Pencil : public WritingInstrument
{
public:
	int getHardness() const;
	void setHardness(int hardness);
private:
	int hardness;
};

std::istream& operator>>(std::istream& is, Pencil& pencil);
std::ostream& operator<<(std::ostream& os, const Pencil& pencil);