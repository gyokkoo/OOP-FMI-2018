#include <iostream>
#include "BrowserHistory.h"

BrowserHistory::BrowserHistory(int n) : topIndex(0)
{
	this->setLimit(n);
	this->arr = new HistoryEntry[n];
}

BrowserHistory::BrowserHistory(const BrowserHistory& other)
{
	this->topIndex = other.topIndex;
	this->setLimit(other.nLimit);
	this->copyFrom(other.arr);
}

BrowserHistory::~BrowserHistory()
{
	this->clear();
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& other)
{
	if (this != &other)
	{
		this->clear();
		this->topIndex = other.topIndex;
		this->setLimit(other.nLimit);
		this->copyFrom(other.arr);
	}

	return *this;
}

void BrowserHistory::readHistoryEntry()
{
	if (this->topIndex >= nLimit)
	{
		std::cout << "Error! Cannot add more entries!\n";
		return;
	}

	HistoryEntry newEntry;
	std::cin >> newEntry;

	this->arr[topIndex] = newEntry;
	topIndex++;
	std::cout << "Entry added!\n";
}

void BrowserHistory::addHistoryEntry(const HistoryEntry & entry)
{
	if (this->topIndex >= nLimit)
	{
		std::cout << "Error! Cannot add more entries!\n";
		return;
	}

	this->arr[topIndex] = entry;
	std::cout << "Entry added!\n";
	topIndex++;
}

BrowserHistory BrowserHistory::operator+(const BrowserHistory& rhs)
{
	int limit = this->nLimit + rhs.nLimit;
	BrowserHistory result(limit);

	int size = this->topIndex + rhs.topIndex;
	if (size >= limit)
	{
		std::cout << "Invalid operation! No space for concatenating operation!\n";
		return result;
	}
	
	int resultIndex = 0;
	for (int i = 0; i < this->topIndex; i++)
	{
		result.arr[resultIndex] = this->arr[i];
		resultIndex++;
	}
	for (int j = 0; j < rhs.topIndex; j++)
	{
		result.arr[resultIndex] = rhs.arr[j];
		resultIndex++;
	}

	result.topIndex = resultIndex;
	return result;
}

int BrowserHistory::getSitesCountByMonth(int month) const
{
	if (month < 1 || month > 12)
	{
		std::cout << "Invalid month! Return -1\n";
		return -1;
	}

	int urlCounter = 0;
	for (int i = 0; i < this->topIndex; i++)
	{
		if (this->arr[i].getMonth() == month)
		{
			urlCounter++;
		}
	}

	return urlCounter;
}

int BrowserHistory::getMostPopularMonth() const
{
	int mostPopularMonth = 0;
	int mostUrlsCount = 0;
	int currentUrlsCount = 0;
	for (int month = 1; month <= 12; month++)
	{
		currentUrlsCount = 0;
		for (int i = 0; i < this->topIndex; i++)
		{
			if (this->arr[i].getMonth() == month)
			{
				currentUrlsCount++;
			}
		}

		if (currentUrlsCount > mostUrlsCount)
		{
			mostUrlsCount = currentUrlsCount;
			mostPopularMonth = month;
		}
	}

	if (mostPopularMonth == 0)
	{
		std::cout << "Error! There is no entries!\n";
	}

	return mostPopularMonth;
}

void BrowserHistory::removeLastEntry()
{
	if (this->topIndex <= 0)
	{
		std::cout << "Error! Cannot remove from empty history!\n";
		return;
	}

	this->topIndex--;
	std::cout << "Last entry removed!\n";
}

void BrowserHistory::printOnConsole() const
{
	std::cout << "N = " << this->nLimit << "\n";
	for (int i = 0; i < this->topIndex; i++)
	{
		this->arr[i].printOnConsole();
		// or 
		// std::cout << arr[i];
	}
}

// private methods:
void BrowserHistory::setLimit(int n)
{
	if (n < 0)
	{
		std::cout << "Error! Invalid size n!\n";
		return;
	}

	this->nLimit = n;
}

void BrowserHistory::copyFrom(HistoryEntry* arr)
{
	this->arr = new HistoryEntry[this->nLimit];
	for (int i = 0; i < this->topIndex; i++)
	{
		this->arr[i] = arr[i];
	}
}

void BrowserHistory::clear()
{
	delete[] this->arr;
	this->arr = nullptr;
	this->topIndex = 0;
}
