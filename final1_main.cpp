#include <iostream>
#include "final1.h"

int main()
{
    Car* x = new Car;
    x->printVehicleGuidelines();

    x->inputChoice();

    std::cout << "Total distance covered: " << x->dist << "km" << std::endl;

    delete x;

    return 1;
}