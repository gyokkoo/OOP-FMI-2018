#include "ElectricNet.h"

ElectricNet::ElectricNet(int maxConsumption)
{
	this->setMaxConsumption(maxConsumption);
	this->allocate(DEFAULT_CAPACITY);
}

ElectricNet::ElectricNet(const ElectricNet& other)
{
	this->copyFrom(other);
}

ElectricNet& ElectricNet::operator=(const ElectricNet& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

ElectricNet::~ElectricNet()
{
	this->clear();
}

ElectricNet& ElectricNet::operator+=(const ElectricDevice& rhs)
{
	if (this->getCurrentConsumption() + rhs.getkW() > this->maxConsumption)
	{
		std::cout << "Network overload!\n";
		return *this;
	}
	if (this->getDeviceIndexByName(rhs.getName()) != -1)
	{
		std::cout << "Error! Cannot add two devices with same name!\n";
		return *this;
	}

	if (this->count >= this->capacity)
	{
		this->resize(capacity * 2);
	}

	this->devices[count] = rhs;
	this->count++;

	return *this;
}

ElectricNet ElectricNet::operator+(const ElectricDevice& rhs)
{
	ElectricNet result(*this);
	return result += rhs;
}

ElectricNet& ElectricNet::operator-=(const ElectricDevice& rhs)
{
	int indexToRemove = this->getDeviceIndexByName(rhs.getName());
	if (indexToRemove == -1)
	{
		std::cout << "Device with name " << rhs.getName() << " does not exist!\n";
		return *this;
	}

	for (int i = indexToRemove; i < this->count - 1; i++)
	{
		this->devices[i] = this->devices[i + 1];
	}
	this->count--;

	return *this;
}

ElectricNet ElectricNet::operator-(const ElectricDevice& rhs)
{
	ElectricNet result(*this);
	return result -= rhs;
}

void ElectricNet::setMaxConsumption(int maxConsumption)
{
	if (maxConsumption < 0)
	{
		std::cout << "Error! Invalid consumption!\n";
		return;
	}

	this->maxConsumption = maxConsumption;
}


ElectricDevice& ElectricNet::operator[](const char* name)
{
	int index = this->getDeviceIndexByName(name);
	return this->devices[index];
}

bool ElectricNet::operator!()
{
	return this->getDevicesCount() > 0;
}

ElectricNet& ElectricNet::operator++()
{
	this->setMaxConsumption(this->maxConsumption * 2);
	return *this;
}

ElectricNet ElectricNet::operator++(int)
{
	ElectricNet result(*this);
	++(*this);             
	return result;
}

ElectricNet& ElectricNet::operator--()
{
	if (this->getMaxConsumption() / 2.0 < this->getCurrentConsumption())
	{
		std::cout << "Network Overload! Cannot decrease max consumption!\n";
		return *this;
	}

	this->setMaxConsumption(this->maxConsumption / 2);
	return *this;
}

ElectricNet ElectricNet::operator--(int)
{
	ElectricNet result(*this);
	--(*this);
	return result;
}

int ElectricNet::getCurrentConsumption() const
{
	int totalConsumption = 0;
	for (int i = 0; i < this->count; i++)
	{
		totalConsumption += this->devices[i].getkW();
	}
	return totalConsumption;
}

int ElectricNet::getMaxConsumption() const
{
	return this->maxConsumption;
}

int ElectricNet::getDevicesCount() const
{
	return this->count;
}

int ElectricNet::getCapacity() const
{
	return this->capacity;
}

void ElectricNet::print() const
{
	std::cout << "Consumption limit ->" << this->getMaxConsumption() << "\n";
	for (int i = 0; i < this->getDevicesCount(); i++) 
	{
		std::cout << this->devices[i];
	}
	std::cout << "Total ~ " << this->getCurrentConsumption() << "kW \n";
}

void ElectricNet::allocate(int size)
{
	this->devices = new ElectricDevice[size];
	this->capacity = size;
}

void ElectricNet::resize(int newCapacity)
{
	ElectricDevice* temp = this->devices;
	allocate(newCapacity);
	for (int i = 0; i < this->count; i++)
	{
		this->devices[i] = temp[i];
	}
	delete[] temp;
}

int ElectricNet::getDeviceIndexByName(const char* name)
{
	for (int i = 0; i < this->count; i++)
	{
		if (strcmp(this->devices[i].getName(), name) == 0)
		{
			return i;
		}
	}

	return -1;
}

void ElectricNet::clear()
{
	delete[] this->devices;
	this->devices = nullptr;
	this->maxConsumption = 0;
	this->capacity = 0;
	this->count = 0;
}

void ElectricNet::copyFrom(const ElectricNet& other)
{
	this->allocate(other.capacity);
	this->maxConsumption = other.maxConsumption;
	this->count = other.count;
	for (int i = 0; i < other.count; i++)
	{
		this->devices[i] = other.devices[i];
	}
}
