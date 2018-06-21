#include "Sentence.h"

Sentence::Sentence() : symbols(nullptr)
{
	this->length = 0;
}

Sentence::Sentence(const char* symbols) : symbols(nullptr)
{
	this->setSentence(symbols);
}

Sentence::Sentence(const Sentence& other) : symbols(nullptr)
{
	this->setSentence(symbols);
}

Sentence & Sentence::operator=(const Sentence & rhs)
{
	if (this != &rhs)
	{
		this->setSentence(rhs.symbols);
		this->length = rhs.length;
	}

	return *this;
}

Sentence::~Sentence()
{
	delete[] this->symbols;
}

void Sentence::setSentence(const char* symbols)
{
	if (symbols == nullptr)
	{
		std::cout << "Invalid symbol! \n";
		return;
	}

	int length = strlen(symbols) + 1;
	
	delete[] this->symbols;
	this->symbols = new char[length + 1];
	strcpy_s(this->symbols, length, symbols);
	this->length = length;
}

const char* Sentence::getSentence() const
{
	return this->symbols;
}

std::ostream& operator<<(std::ostream & os, const Sentence & sentence)
{
	os << sentence.getSentence();
	return os;
}