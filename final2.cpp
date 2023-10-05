#include <iostream>
#include "final1.h"

void Vehicle :: printVehicleGuidelines()
{
    std::cout << "The vehicle will start with fuel set to 100. Driving at high RPM will cause higher fuel consumption.\n\n" <<
    "For the vehicle to run the RPM must be between 1000 and 8000. " <<
    "If it goes below 1000, the vehicle will stall and the engine needs to be restarted. " <<
    "If it goes above 8000, the engine will fail and the vehicle will not be drivable.\n\n" <<
    "Upshifting will cause the RPM to reduce by 3000. Downshifting will cause it to increase by 2000. There are only 5 gears and no reverse gear.\n\n" <<
    "Each iteration is counted as one minute, distance covered will be measured accordingly. \n\n" <<
    "The program will run till the fuel runs out." << std::endl;
}

void Car::inputChoice()
{
        try{
            std::cout << "Enter which option you would like to choose: \n" <<
            "1. Accelerate \n" <<
            "2. Brake \n" <<
            "3. Upshift \n" <<
            "4. Downshift" << std::endl;

            std::cin >> choice;

            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                throw std::runtime_error("Invalid input, please enter a number.\n");
            }
            else if(choice==1)
            accelerate();
            else if(choice==2)
            brake();
            else if(choice==3)
            upshiftGear();
            else if(choice==4)
            downshiftGear();
            else
            throw std::runtime_error("Invalid input, please enter a choice between 1 and 4.\n");
        }
        catch (const std::exception& e){
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
}  


void Vehicle::displaySpeed()
{
    std::cout << "Current speed: " << speed << " km/h" << std::endl;
    std::cout << "Current RPM: " << rpm * 1000 << std::endl;
    std::cout << "Current gear: " << gear << std::endl;
    std::cout << "Fuel level: " << fuel << "/100" << std::endl;
    std::cout << "Distance covereed: " << dist << "km" << std::endl;
}

void Vehicle::distCovered()
{
    dist = dist + speed/60;
}

void Car::accelerate()
{
    speed = speed + (5 * rpm);
    rpm++;
    checkRPM();
}

void Car::brake()
{
    if((speed - (10 / gear))<0)
    {speed = 0;
    rpm =1;}
    else{
    speed = speed - (10 / gear);
    rpm--;
    checkRPM();
}}

void Vehicle::fuelConsumption()
{
    fuel = fuel - rpm;
}

void Vehicle::upshiftGear()
{
    if(gear==5)
        std::cout << "You can't upshift as the gear is already at the highest level." << std::endl;
    else
    {
        gear++;
        rpm = rpm - 3;
    }
    checkRPM();
}

void Vehicle::downshiftGear()
{
    if(gear==1)
        std::cout << "You can't downshift as the gear is already at the lowest level." << std::endl;
    else
    {
        gear--;
        rpm = rpm + 2;
    }
    checkRPM();
}

bool Vehicle::checkRPM()
{
    if(rpm < 1)
    {
        std::cout << "Vehicle stalled due to low RPM. Accelerate again to restart the vehicle." << std::endl;
        rpm = 1;
        speed =0;
        gear = 1;
        return true;
    }
    else if (rpm > 8)
    {
        std::cout << "Vehicle stopped due to engine failure from high RPM." << std::endl;
        return false;
    }
    else
    {
        distCovered();
        fuelConsumption();
    }
    return true;
}

