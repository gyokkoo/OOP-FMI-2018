#pragma once
#include <iostream>

class Egg
{
public:
	Egg();
	Egg(const char* name);
	Egg(const char* name, int size);
	Egg(const Egg& egg);
	~Egg();

	Egg& operator=(const Egg& egg);
	
	bool serialization(std::ofstream& os) const;

	// bool deserialization(std::ifstream& is);

	const char* getName() const;
	int getSize() const;

	void setName(const char* name);
private:
	char* name;
	int size;
};