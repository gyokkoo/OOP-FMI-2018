#pragma once

template<typename T>
class PriceTag
{
public:
	PriceTag();
	PriceTag(const T& price);

	void setPrice(const T& price);
	T getPrice() const;

	void discount(double percentage);

	friend std::ostream& operator<<(std::ostream& os, const PriceTag<T>& priceTag)
	{
		os << "Price tag: " << priceTag.getPrice() << "\n";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, PriceTag<T>& priceTag)
	{
		T value;
		std::cout << "Enter price tag: ";
		is >> value;

		priceTag.setPrice(value);

		return is;
	}
private:
	T price;
};

template<typename T>
inline PriceTag<T>::PriceTag()
{
	this->price = 0;
}

template<typename T>
inline PriceTag<T>::PriceTag(const T & price)
{
	this->setPrice(price);
}

template<typename T>
inline void PriceTag<T>::setPrice(const T & price)
{
	this->price = price;
}

template<typename T>
inline T PriceTag<T>::getPrice() const
{
	return this->price;
}

template<typename T>
inline void PriceTag<T>::discount(double percentage)
{
	if (percentage < 0 || percentage > 100)
	{
		return;
	}

	double discount = (percentage * this->price) / 100.0;
	this->setPrice(this->price - discount);
}
