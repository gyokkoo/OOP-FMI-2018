#pragma once
#include "HistoryEntry.h"

class BrowserHistory
{
public:
	BrowserHistory(int n);
	BrowserHistory(const BrowserHistory&);
	BrowserHistory& operator=(const BrowserHistory&);
	~BrowserHistory();

	void readHistoryEntry();
	void addHistoryEntry(const HistoryEntry&);

	BrowserHistory operator+(const BrowserHistory&);

	int getSitesCountByMonth(int month) const;
	int getMostPopularMonth() const;
	void removeLastEntry();

	void printOnConsole() const;
private:
	void setLimit(int n);
	void copyFrom(HistoryEntry* arr);
	void clear();
private:
	int topIndex;
	int nLimit;
	HistoryEntry* arr;
};