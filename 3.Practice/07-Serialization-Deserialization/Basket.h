#pragma once
#include "Egg.h"

const int INITIAL_CAPACITY = 2;

class Basket
{
public:
	Basket();
	Basket(const char* name);
	Basket(const Basket& basket);
	~Basket();

	Basket& operator=(const Basket& basket);

	void generateReport();

	void setName(const char* name);

	void addEgg(const char* eggName);

	void removeEgg(const char* eggName);
private:
	void resize();
	void shiftLeft(int index);
private:
	char* name;
	Egg* eggs;
	int size;
	int capacity;
};