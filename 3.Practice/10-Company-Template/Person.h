#pragma once
#include <iostream>
#include <cstring>

template<typename T>
class Person
{
public:
	Person(const char* name, long long UCN, T* insurer);
	Person(const Person<T>& other);
	Person<T>& operator=(const Person<T>& rhs);
	~Person();

	void setName(const char* name);
	void setUCN(long long UCN);
	void setInsurer(T* insurer);

	const char* getName() const;
	long long getUCN() const;
	const T* getInsurer() const;
private:
	T* insurer;
	char* name;
	long long UCN; // Unique Citizenship Number or EGN
};


template<typename T>
inline Person<T>::Person(const char* name, long long UCN, T* insurer) : name(nullptr), UCN(0), insurer(nullptr)
{
	this->setName(name);
	this->setUCN(UCN);
	this->setInsurer(insurer);
}

template<typename T>
inline Person<T>::Person(const Person & other)
{
	this->setName(other.name);
	this->setUCN(other.UCN);
	this->setInsurer(other.insurer);
}

template<typename T>
inline Person<T>& Person<T>::operator=(const Person<T>& rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.name);
		this->setUCN(rhs.UCN);
		this->setInsurer(rhs.insurer);
	}

	return *this;
}

template<typename T>
inline Person<T>::~Person()
{
	delete[] this->name;
}

template<typename T>
inline void Person<T>::setName(const char* name)
{
	if (name == nullptr)
	{
		std::cout << "Invalid name!\n";
		this->name = nullptr;
	}

	int length = strlen(name) + 1;
	delete[] this->name;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

template<typename T>
inline void Person<T>::setUCN(long long UCN)
{
	// Assume that all 10 digit numbers are valid UCN
	if (UCN < 1000000000 || UCN > 9999999999)
	{
		std::cout << "Invalid UCN!\n";
		this->UCN = 0;
	}

	this->UCN = UCN;
}

template<typename T>
inline void Person<T>::setInsurer(T* insurer)
{
	if (insurer == nullptr)
	{
		std::cout << "Invalid insurer!\n";
	}

	this->insurer = insurer;
}

template<typename T>
inline const char* Person<T>::getName() const
{
	if (this->name == nullptr)
	{
		return "No name";
	}

	return this->name;
}

template<typename T>
inline long long Person<T>::getUCN() const
{
	return this->UCN;
}

template<typename T>
inline const T* Person<T>::getInsurer() const
{
	return this->insurer;
}
