#pragma once

class Building
{
public:
	Building();
	Building(int height, double area, const char* address);
	Building(const Building& other);
	Building& operator=(const Building& rhs); // rhs refers to right hand side
	~Building();

	int getHeight() const;
	double getArea() const;
	const char* getAddress() const;

	void setHeight(int height);
	void setArea(double area);
	void setAddress(const char* address);

	void print() const;
private:
	int height;
	double area;
	char* address;
};