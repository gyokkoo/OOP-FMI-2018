#pragma once
#include "Device.h"

class Laptop : public Device
{
public:
    Laptop();
    Laptop(const char* maker, int speed);

    int getPerformance() const override;

    void print() const;
private:
    int speed;
};