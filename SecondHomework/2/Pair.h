#pragma once
#include <iostream>
#include <cstring>

template<typename T>
class Pair
{
public:
	Pair();
	Pair(const char* key, T value);
	Pair(const Pair<T>& other);
	Pair<T>& operator=(const Pair<T>& other);
	~Pair();

	const char* getKey() const;
	T getValue() const;

	void setKey(const char* key);
	void setValue(T value);
private:
	char* key;
	T value;
};

template<typename T>
Pair<T>::Pair() : key(nullptr), value(T())
{
}

template<typename T>
Pair<T>::Pair(const char* key, T value) : key(nullptr)
{
	this->setKey(key);
	this->setValue(value);
}

template<typename T>
Pair<T>::Pair(const Pair<T>& other) : key(nullptr)
{
	this->setKey(other.key);
	this->setValue(other.value);
}

template<typename T>
Pair<T>& Pair<T>::operator=(const Pair<T>& rhs)
{
	if (this != &rhs)
	{
		this->setKey(rhs.key);
		this->setValue(rhs.value);
	}

	return *this;
}

template<typename T>
Pair<T>::~Pair()
{
	delete[] this->key;
}

template<typename T>
const char* Pair<T>::getKey() const
{
	if (this->key == nullptr)
	{
		return "Invalid Key\n";
	}

	return this->key;
}

template<typename T>
T Pair<T>::getValue() const
{
	return this->value;
}

template<typename T>
void Pair<T>::setKey(const char* key)
{
	if (key == nullptr)
	{
		std::cout << "Invalid key!\n";
		this->key = nullptr;
		return;
	}

	delete[] this->key;
	int length = strlen(key) + 1;
	this->key = new char[length];
	strcpy_s(this->key, length, key);
}

template<typename T>
void Pair<T>::setValue(T value)
{
	this->value = value;
}
