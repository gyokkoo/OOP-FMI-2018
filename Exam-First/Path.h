#pragma once
#include "Point.h"

const int MAX_SIZE = 100;

class Path
{
public:
	Path();
	Path(const char* name, int size = MAX_SIZE);
	Path(const Path& path);
	Path& operator=(const Path& rhs);
	~Path();

	void operator+=(const Point& point);

	const char* getName() const;
	void setName(const char* name);

	void deletePoint(int index);

	void print() const;
	int getLength() const; 
private:
	void copyPath(const Path& path);
	void clear();
	void shiftLeft(int index);
private:
	Point* points;
	char* name;
	int top;
};