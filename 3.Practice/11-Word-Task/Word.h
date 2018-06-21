#pragma once
#include <iostream>

const int MAX_LENGTH = 20;

class Word
{
public:
	Word();
	Word(const char* word);

	char operator[](int index) const;
	Word& operator+=(char symbol);
	Word operator+(char symbol);

	bool operator<(const Word& other);
	bool operator==(const Word& other);

	void setWord(const char* word);

	const char* getWord() const;
	int getLength() const;
private:
	char word[MAX_LENGTH + 1];
	int length;
};