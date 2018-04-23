#pragma once

struct HistoryEntry
{
public:
	HistoryEntry();
	HistoryEntry(int month, const char* url);
	HistoryEntry(const HistoryEntry&);
	HistoryEntry& operator=(const HistoryEntry&);
	~HistoryEntry();

	int getMonth() const;
	const char* getUrl() const;
	void setMonth(int month);
	void setUrl(const char* url);

	void printOnConsole() const;
private:
	int month;
	char* url;
};

std::ostream& operator<<(std::ostream & os, const HistoryEntry& entry);
std::istream& operator>>(std::istream & is, HistoryEntry& entry);

int myStrlen(const char* str);