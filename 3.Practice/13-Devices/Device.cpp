#include <cstring>
#include "Device.h"

Device::Device() : maker(nullptr)
{
}

Device::Device(const char* maker) : maker(nullptr)
{
    this->setMaker(maker);
}

Device::Device(const Device& other) : Device()
{
    this->setMaker(other.maker);
}

Device& Device::operator=(const Device& rhs)
{
    if (this != &rhs)
    {
        this->setMaker(rhs.maker);
    }

    return *this;
}

Device::~Device()
{
    delete[] this->maker;
}

const char* Device::getMaker() const
{
    if (this->maker == nullptr)
    {
        return "No maker!";
    }

    return this->maker;
}

void Device::setMaker(const char* maker)
{
    if (maker == nullptr)
    {
        std::cout << "Provided maker name is invalid(nullptr)! \n";
        this->maker = nullptr;
        return;
    }

    size_t length = strlen(maker);

    delete[] this->maker;
    this->maker = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
        this->maker[i] = maker[i];
    }

    this->maker[length] = '\0';
}

void Device::print() const
{
    std::cout << this->getMaker() << "\n";
}