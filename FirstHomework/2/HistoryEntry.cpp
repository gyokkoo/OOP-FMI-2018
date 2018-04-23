#include <iostream>
#include <string.h>
#include "HistoryEntry.h"

HistoryEntry::HistoryEntry() : month(0), url(nullptr)
{
}

HistoryEntry::HistoryEntry(int month, const char* url) : url(nullptr)
{
	this->setMonth(month);
	this->setUrl(url);
}

HistoryEntry::HistoryEntry(const HistoryEntry& other) : url(nullptr)
{
	this->setMonth(other.month);
	this->setUrl(other.url);
}

HistoryEntry::~HistoryEntry()
{
	delete[] this->url;
}

HistoryEntry& HistoryEntry::operator=(const HistoryEntry& other)
{
	if (this != &other)
	{
		this->setMonth(other.month);
		this->setUrl(other.url);
	}

	return *this;
}

int HistoryEntry::getMonth() const
{
	return this->month;
}

const char* HistoryEntry::getUrl() const
{
	return this->url;
}

void HistoryEntry::setMonth(int month)
{
	if (month < 1 || month > 12)
	{
		std::cout << "Error! Invalid month!\n";
		this->month = 0;
		return;
	}

	this->month = month;
}

void HistoryEntry::setUrl(const char* url)
{
	delete[] this->url;
	int length = myStrlen(url);
	this->url = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->url[i] = url[i];
	}
	this->url[length] = '\0';
}

void HistoryEntry::printOnConsole() const
{
	std::cout << "Month: " << this->getMonth() << " -> " << this->getUrl() << "\n";
}

std::ostream& operator<<(std::ostream & os, const HistoryEntry& entry)
{
	os << "Month: " << entry.getMonth() << " -> " << entry.getUrl() << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, HistoryEntry& entry)
{
	int month;
	std::cout << "Enter Month: \n";
	is >> month;
	entry.setMonth(month);

	int urlMaxSize = 25;
	char* inputUrl = new char[urlMaxSize];
	int index = 0;
	char c;
	
	// To Ignore \n from previous input
	is.ignore();

	std::cout << "Enter URL: \n";
	while (is.get(c) && c != '\n')
	{
		if (index >= urlMaxSize)
		{
			// Resize
			urlMaxSize *= 2;
			char* temp = inputUrl;
			inputUrl = new char[urlMaxSize];
			for (int i = 0; i < index; i++)
			{
				inputUrl[i] = temp[i];
			}
			delete[] temp;
		}

		inputUrl[index] = c;
		index++;
	}
	inputUrl[index] = '\0';
	
	entry.setUrl(inputUrl);
	return is;
}

int myStrlen(const char* str)
{
	int index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return index;
}
