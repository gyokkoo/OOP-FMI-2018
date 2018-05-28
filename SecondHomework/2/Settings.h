#pragma once
#include "Pair.h"

const int DEFAULT_CAPACITY = 2;

template<typename T>
class Settings
{
public:
	Settings();
	Settings(const Settings<T>& other);
	Settings<T>& operator=(const Settings<T>& rhs);
	~Settings();

	int getCount() const;
	bool get(const char* key, T& value) const;
	int getKeyIndex(const char* key) const;

	void set(const char* key, T value);
	void set(const Pair<T>& pair);

	void print() const;
private:
	void allocate(int size);
	void resize(int newSize);
	void copyPairArray(Pair<T>* pairArr, int length);
	void copyFrom(const Settings<T>& other);
	void clear();
private:
	int count;
	int capacity;
	Pair<T>* pairArr;
};

template<typename T>
Settings<T>::Settings() : pairArr(nullptr)
{
	this->allocate(DEFAULT_CAPACITY);
	this->count = 0;
}

template<typename T>
Settings<T>::Settings(const Settings<T>& other) : pairArr(nullptr)
{
	this->copyFrom(other);
}

template<typename T>
Settings<T>& Settings<T>::operator=(const Settings<T>& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

template<typename T>
Settings<T>::~Settings()
{
	this->clear();
}



template<typename T>
void Settings<T>::set(const char* key, T value)
{
	int keyIndex = this->getKeyIndex(key);
	if (keyIndex == -1) // The key does not exist
	{
		// Resize if container is full
		if (this->count >= this->capacity)
		{
			this->resize(this->count * 2);
		}

		this->pairArr[this->count] = Pair<T>(key, value);
		this->count++;
	}
	else
	{
		this->pairArr[keyIndex].setValue(value);
	}
}

template<typename T>
void Settings<T>::set(const Pair<T>& pair)
{
	this->set(pair.getKey(), pair.getValue());
}

template<typename T>
int Settings<T>::getCount() const
{
	return this->count;
}

template<typename T>
bool Settings<T>::get(const char* key, T& value) const
{
	int index = this->getKeyIndex(key);
	if (index == -1)
	{
		return false;
	}

	value = this->pairArr[index].getValue();
	return true;
}

template<typename T>
int Settings<T>::getKeyIndex(const char* key) const
{
	for (int i = 0; i < this->count; i++)
	{
		if (strcmp(this->pairArr[i].getKey(), key) == 0)
		{
			return i;
		}
	}

	return -1;
}

template<typename T>
void Settings<T>::print() const
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << this->pairArr[i].getKey() << " -> "
			<< this->pairArr[i].getValue() << "\n";
	}
}

template<typename T>
void Settings<T>::allocate(int size)
{
	this->pairArr = new Pair<T>[size];
	this->capacity = size;
}

template<typename T>
void Settings<T>::resize(int newSize)
{
	Pair<T>* temp = this->pairArr;
	this->pairArr = new Pair<T>[newSize];
	this->capacity = newSize;
	this->copyPairArray(temp, this->count);
	delete[] temp;
}

template<typename T>
void Settings<T>::copyPairArray(Pair<T>* pairArr, int length)
{
	for (int i = 0; i < length; i++)
	{
		this->pairArr[i] = pairArr[i];
	}
}

template<typename T>
void Settings<T>::copyFrom(const Settings<T>& other)
{
	this->allocate(other.capacity);
	this->copyPairArray(other);
}

template<typename T>
void Settings<T>::clear()
{
	delete[] this->pairArr;
	this->pairArr = nullptr;
	this->count = 0;
	this->capacity = 0;
}
