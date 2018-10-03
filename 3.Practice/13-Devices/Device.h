#pragma once

#include <iostream>

class Device
{
public:
    Device();
    Device(const char* maker);
    Device(const Device& other);
    Device& operator=(const Device& rhs);
    ~Device();

    const char* getMaker() const;

    virtual int getPerformance() const = 0;

    void print() const;

private:
    void setMaker(const char* maker);

private:
    char* maker;
};
