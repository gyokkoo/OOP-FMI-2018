#pragma once
#include <iostream>
#include "Word.h"

class Sentence
{
public:
	Sentence();
	Sentence(const char* symbols);
	Sentence(const Sentence& other);
	Sentence& operator=(const Sentence& rhs);
	~Sentence();

	void setSentence(const char* symbols);
	const char* getSentence() const;

	// void addWord(const Word& word);
private:
	char* symbols;
	int length;
};

std::ostream& operator<<(std::ostream& os, const Sentence& sentence);

