#pragma once
#include "Product.h"

const int DEFAULT_CAPACITY = 25;

class Store
{
public:
	Store();
	Store(const Store& other);
	Store& operator=(const Store& rhs);
	~Store();

	void addProduct();
	void deleteProduct(int sku);
	void changeProduct(int sku);
	void printOnConsole() const;
private:
	void clear();
	void copyFrom(const Store& store);
	void resizeArr(int newCapacity);
	char* readInput();
	void readProductInput(Product* product);
	void removeFromArray(int indexToRemove);
private:
	int count;
	int capacity;
	Product* products;
	int idGenerator;
};