#pragma once

class Book
{
public:
	Book();
	Book(const char* title, int pages);
	Book(const Book& other);
	Book& operator=(const Book& rhs);
	~Book();

	bool operator<(const Book& rhs);
	bool operator>(const Book& rhs);

	void setTitle(const char* title);
	void setPages(int pages);

	const char* getTitle() const;
	int getPages() const;
private:
	char* title;
	int pages;
};

std::istream& operator>>(std::istream& is, Book& book);
std::ostream& operator<<(std::ostream& os, const Book& book);
