#include <iostream>
#include <cstring>

const int MAX_LENGHT = 100;

class Battery
{
private:
	char model[MAX_LENGHT];
	int useTime;
public:
	Battery() : model("N/A"), useTime(0)
	{
	}

	Battery(const char* model, int useTime)
	{
		strcpy_s(this->model, model);
		this->useTime = useTime;
	}

	void print()
	{
		std::cout
			<< "--Battery:\n"
			<< "----Model: " << model << "\n"
			<< "----Use time: " << useTime << " hours \n";
	}
};

class Display
{
private:
	double sizeInches;
	long long colors;
public:
	Display() : sizeInches(0), colors(0)
	{
	}

	Display(double sizeInches, long long colors)
	{
		this->sizeInches = sizeInches;
		this->colors = colors;
	}

	void print()
	{
		std::cout
			<< "--Display info:\n"
			<< "----Inches " << sizeInches << "\n"
			<< "----Colors " << colors << "\n";
	}	
};

class MobilePhone 
{
private:
	char model[MAX_LENGHT];
	char manufacturer[MAX_LENGHT];
	double price;
	Battery battery;
	Display display;
public:
	MobilePhone(): model("N/A"), manufacturer("N/A"), price(0), battery(), display()
	{
	}

	MobilePhone(
		const char* model, const char* manufacturer, double price,
		const char* batteryModel, int useTime,
		double displaySize, long long colors) 
		: battery(batteryModel, useTime), display(displaySize, colors)
	{
		strcpy_s(this->model, model);
		strcpy_s(this->manufacturer, manufacturer);
		this->price = price;
	}

	void print()
	{
		std::cout 
			<< "______________\n" 
			<< "Phone info:\n"
			<< "--Model " << model << "\n"
			<< "--Manufacturer " << manufacturer << "\n"
			<< "--Price " << price << " leva \n";
		battery.print();
		display.print();
	}
};


int main()
{
	MobilePhone defaultPhone;
	defaultPhone.print();

	MobilePhone samsungPhone(
		"Galaxy S8", "Samsung", 1200, "EB-L1G6LLUCSTD", 52, 5.8, 160000000);
	samsungPhone.print();

	MobilePhone iphone(
		"iPhone 7", "Apple", 1000, "Non-removable Li-Ion 1960 mAh battery", 61, 4.9, 320000000);
	iphone.print();

}