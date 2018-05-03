#include <cstring>
#include <iostream>
#include "Path.h"

Path::Path() : name(nullptr), top(0)
{
	this->points = new Point[MAX_SIZE];
}

Path::Path(const char* name, int size) : name(nullptr)
{
	this->setName(name);
	this->points = new Point[size];
	this->top = 0;
}

Path::Path(const Path& path)
{
	this->copyPath(path);
}

Path & Path::operator=(const Path & rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyPath(rhs);
	}

	return *this;
}

Path::~Path()
{
	this->clear();
}

void Path::operator+=(const Point& point)
{
	if (this->top >= MAX_SIZE)
	{
		std::cout << "The container is full!\n";
	}
	this->points[top] = point;
	this->top++;
}


const char* Path::getName() const
{
	if (this->name == nullptr) 
	{
		return "No Name\n";
	}

	return this->name;
}

void Path::setName(const char* name)
{
	delete[] this->name;
	int length = strlen(name);
	this->name = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}
	this->name[length] = '\0';
}

void Path::deletePoint(int index)
{
	if (index < 0 || index >= this->top)
	{
		std::cout << "Invalid index!\n";
	}

	this->top--;
	shiftLeft(index);
}

void Path::print() const
{
	std::cout << "Path " << this->getName() << "\n";
	for (int i = 0; i < this->top; i++)
	{
		this->points[i].print();
	}
}

int Path::getLength() const
{
	return this->top;
}

void Path::copyPath(const Path& path)
{
	this->setName(path.name);
	this->top = path.top;
	this->points = new Point[MAX_SIZE];
	for (int i = 0; i < path.top; i++)
	{
		this->points[i] = path.points[i];
	}
}

void Path::clear()
{
	delete[] this->name;
	this->name = nullptr;
	delete[] this->points;
	this->points = nullptr;
	this->top = 0;
}

void Path::shiftLeft(int index)
{
	Point* temp = this->points;
	this->points = new Point[MAX_SIZE];
	int j = 0;
	for (int i = 0; i <= this->top; i++)
	{
		if (i == index)
		{
			continue;
		}

		this->points[j] = temp[i];
		j++;
	}

	delete[] temp;
}
