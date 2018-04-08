#include <cstring>
#include <fstream>
#include "Egg.h"

Egg::Egg() : name(nullptr), size(0)
{
}

Egg::Egg(const char* name) : name(nullptr)
{
	this->size = strlen(name);
	this->setName(name);
}

Egg::Egg(const char* name, int size) : name(nullptr)
{
	this->size = size;
	this->setName(name);
}

Egg::Egg(const Egg& egg) : name(nullptr)
{
	this->size = egg.size;
	this->setName(egg.name);
}

Egg::~Egg()
{
	delete[] this->name;
}

Egg &Egg::operator=(const Egg& egg)
{
	if (this != &egg)
	{
		this->size = egg.size;
		this->name = new char[egg.size + 1];
		strcpy_s(this->name, this->size + 1, egg.name);
	}

	return *this;
}

bool Egg::serialization(std::ofstream &os) const
{
	os.write((const char*)& this->size, sizeof(this->size));
	os.write(this->name, this->size);

	return true;
}	

const char* Egg::getName() const
{
	return this->name;
}

int Egg::getSize() const
{
	return this->size;
}

void Egg::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < this->size; i++)
	{
		this->name[i] = name[i];
	}
	this->name[strlen(name)] = '\0';
}
