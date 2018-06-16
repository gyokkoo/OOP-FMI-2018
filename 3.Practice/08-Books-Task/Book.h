#pragma once

class Book
{
public:
	Book(const char* title, int page);
	Book(const Book& other);
	Book& operator=(const Book& rhs);
	~Book();

	void setTitle(const char* title);
	void setPage(int pages);

	const char* getTitle() const;
	int getPages() const;
private:
	char* title;
	int pages;
};