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
	
	void eggPrint(std::ofstream& os) const;
	void eggSerialization(std::ofstream& os) const;
	void eggDeserialization(std::ifstream& is);

	const char* getName() const;
	int getSize() const;

	void setName(const char* name);
private:
	char* name;
	int size;
};