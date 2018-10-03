#include "Laptop.h"
#include "Device.h"

Laptop::Laptop() : Device(), speed(0)
{
}

Laptop::Laptop(const char* maker, int speed) : Device(maker)
{
    this->speed = speed;
}

int Laptop::getPerformance() const
{
    return this->speed;
}

void Laptop::print() const
{
    Device::print();
    std::cout << this->getPerformance() << " GHz";
}