#include <iostream>
#include "final1.h"

int main()
{
    Car* x[4];

    for(int i=0;i<4;i++){
        x[i] = new Car;
    }
    
    x[0]->printVehicleGuidelines();

    int j = 0;
    while(j < 10)
    {
        j++;
        for(int i=0;i<4;i++)
        {
            if(x[i]!=NULL){
            std::cout << "CAR " << (i+1) << ": " <<std::endl;
            x[i]->displaySpeed();
            x[i]->inputChoice();
            std::cout << "CAR " << (i+1) << ": " <<std::endl;
            x[i]->displaySpeed();
            
            if(x[i]->checkRPM()==false)
            x[i] = NULL;
        }}
        if(x[0]== NULL && x[1]==NULL && x[2]==NULL && x[3]==NULL)
        break;
    }
    for(int i=0;i<4;i++)
    {
        delete x[i];
    }

    return 1;
}