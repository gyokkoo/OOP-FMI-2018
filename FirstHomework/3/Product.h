#pragma once

class Product
{
public:
	Product();
	Product(const Product& other);
	Product& operator=(const Product& rhs);
	~Product();
	
	int getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const char* getCategory() const;
	double getPrice() const;
	int getCount() const;

	void setSKU(int id);
	void setBrand(const char* brand);
	void setModel(const char* model);
	void setCategory(const char* category);
	void setPrice(double price);
	void setCount(int count);

	void printOnConsole() const;
private:
	void clear();
	void copy(const Product&);
	void copyString(char*& destination, const char* source);
	int strlen(const char* str);
private:
	int sku; // unique product id
	char* brand;
	char* model;
	int count;
	double price;
	char* category; // optional product category
};

