#include <iostream>

#include "Device.h"
#include "Laptop.h"

int main()
{
    Laptop lenovo;
    Laptop macbook("Apple", 3);

    Laptop macFromChina;
    macFromChina = macbook;

    macFromChina.print();

    return 0;
}