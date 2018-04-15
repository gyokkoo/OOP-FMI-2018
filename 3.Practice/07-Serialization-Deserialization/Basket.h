#pragma once
#include "Egg.h"

const int INITIAL_CAPACITY = 2;

class Basket
{
public:
	Basket(const char* name);
	Basket(const Basket& basket);
	~Basket();
	
	Basket& operator=(const Basket& basket);

	void generateReport();
	void serialization();
	void deserialization();

	void setName(const char* name);
	void addEgg(const Egg& egg);
	void removeEgg(const Egg& egg);
private:
	void resize();
	int getEggIndex(const char* eggName);
private:
	char* name;
	Egg* eggs;
	int count;
	int capacity;
};