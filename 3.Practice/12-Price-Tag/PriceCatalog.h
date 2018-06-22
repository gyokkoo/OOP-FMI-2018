#pragma once
#include "PriceTag.h"

template<typename T>
class PriceCatalog
{
public:
	PriceCatalog();

	void operator+=(const PriceTag<T>& newTag);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const PriceCatalog<T> catalog)
	{
		for (int i = 0; i < catalog.length; i++)
		{
			os << catalog.catalog[i];
		}

		return os;
	}
private:
	PriceTag<T> catalog[200];
	int length;
};

template<typename T>
inline PriceCatalog<T>::PriceCatalog()
{
	this->length = 0;
}

template<typename T>
inline void PriceCatalog<T>::operator+=(const PriceTag<T>& newTag)
{
	if (this->length >= 200)
	{
		std::cout << "Catalog is full!\n";
		return;
	}

	this->catalog[this->length++] = newTag;
}
