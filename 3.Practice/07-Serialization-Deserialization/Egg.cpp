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

Egg &Egg::operator=(const Egg& rhs)
{
	if (this != &rhs)
	{
		delete[] this->name;
		this->size = rhs.size;
		this->name = new char[rhs.size + 1];
		strcpy_s(this->name, this->size + 1, rhs.name);
	}

	return *this;
}

void Egg::eggPrint(std::ofstream & os) const
{
	os << this->name << " " << this->size << "\n";
}

void Egg::eggSerialization(std::ofstream & os) const
{
	os.write((const char*)& this->size, sizeof(this->size));
	os.write(this->name, this->size);
}

void Egg::eggDeserialization(std::ifstream & is)
{
	is.read((char *)& this->size, sizeof(this->size));
	this->name = new char[this->size + 1];
	is.read(this->name, this->size);
	this->name[this->size] = '\0';
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
	int nameLength = strlen(name);
	this->name = new char[nameLength + 1];
	for (int i = 0; i < this->size; i++)
	{
		this->name[i] = name[i];
	}
	this->name[nameLength] = '\0';
}
