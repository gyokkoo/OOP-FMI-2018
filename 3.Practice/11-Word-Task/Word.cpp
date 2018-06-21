#include "Word.h"
#include <iostream>
#include <cstring>

Word::Word()
{
	this->length = 0;
}

Word::Word(const char* word)
{
	this->setWord(word);
	this->length = strlen(word);
}

char Word::operator[](int index) const
{
	if (index < 0 || index >= this->length)
	{
		std::cout << "Error! Invalid index!\n";
		return '\0';
	}

	return this->word[index];
}

Word& Word::operator+=(char symbol)
{
	if (this->length >= MAX_LENGTH)
	{
		std::cout << "Cannot add the symbol, array is full!\n";
		return *this;
	}

	this->word[this->length++] = symbol;
	this->word[this->length] = '\0';

	return *this;
}

Word Word::operator+(char symbol)
{
	Word result(*this);
	return result += symbol;
}

bool Word::operator<(const Word & other)
{
	return strcmp(this->getWord(), other.getWord()) < 0;
}

bool Word::operator==(const Word& other)
{
	return strcmp(this->getWord(), other.getWord()) == 0;
}

void Word::setWord(const char * word)
{
	if (word == nullptr)
	{
		std::cout << "Invalid word!\n";
		return;
	}

	int wordLength = strlen(word);
	if (wordLength > MAX_LENGTH)
	{
		wordLength = MAX_LENGTH;
	}

	int i = 0;
	for (i = 0; i < wordLength; i++)
	{
		this->word[i] = word[i];
	}
	this->word[i] = '\0';
}

const char * Word::getWord() const
{
	return this->word;
}

int Word::getLength() const
{
	return this->length;
}
