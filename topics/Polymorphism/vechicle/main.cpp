
#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "truck.h"
using namespace std;


void repair(Vehicle &v)
{
    v.print();
    cout << "  has been repaired " << endl;
}

int main()
{
    Vehicle veh;
    Car mycar;
    Truck mytruck;

    //repair(mycar); // upcasting by reference

    Vehicle* t[3]; // array of pointers to base class (Vehicle)
    t[0] = new Vehicle;
    t[1] = new Car; // pucasting by pointer
    t[2] = new Truck;

    t[0]->print();
    t[1]->print();
    t[2]->print();

    return 0;
}