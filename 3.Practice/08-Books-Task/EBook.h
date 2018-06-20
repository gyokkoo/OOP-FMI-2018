#pragma once
#include "Book.h"

class EBook : public Book
{
public:
	EBook();
	EBook(const char* title, int pages, int bytes, int openedCounter);

	double getRating() const;

	int getBookBytes() const;
	int getOpenedCount() const;
	
	void setBytes(int bytes);
	void setOpenedCounter(int count);
private:
	int bytes;
	int openedCounter;
};

std::istream& operator>>(std::istream& is, EBook& book);
std::ostream& operator<<(std::ostream& os, const EBook& book);