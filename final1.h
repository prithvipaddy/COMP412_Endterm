#ifndef FINAL_1_
#define FINAL_1_

class Vehicle
{
public:
    int choice;
    float speed, fuel, dist; //dist = distance covered by the car
    int gear,rpm;
    void distCovered();
    void displaySpeed();
    void upshiftGear();
    void fuelConsumption();
    void downshiftGear();
    bool checkRPM();
    void printVehicleGuidelines();

    Vehicle() : speed(0), fuel(100), gear(1), rpm(1), dist(0) {};
};

class Car : public Vehicle
{
public:
    void inputChoice();
    void brake();
    void accelerate();
};

#endif