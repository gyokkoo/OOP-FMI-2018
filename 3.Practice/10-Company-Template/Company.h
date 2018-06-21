#pragma once
#include <iostream>

struct Company
{
public:
	Company();
	Company(const char* name, long long bulstat);

	const char* getName() const;
	long long getBulstat() const;
private:
	char name[100];
	long long bulstat;
};

std::ostream& operator<<(std::ostream& os, const Company& company);