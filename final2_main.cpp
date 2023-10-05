#include <iostream>
#include "final1.h"

int main()
{
    Car* x[4];

    for(int i=0;i<4;i++){
        x[i] = new Car;
    }
    
    x[0]->printVehicleGuidelines();

    while(true)
    for(int i=0;i<4;i++)
    {
        std::cout << "CAR " << (i+1) << ": " <<std::endl;
        x[i]->displaySpeed();
        x[i]->inputChoice();
        std::cout << "CAR " << (i+1) << ": " <<std::endl;
        x[i]->displaySpeed();
    }

    for(int i=0;i<4;i++)
    {
        delete x[i];
    }

    return 1;
}