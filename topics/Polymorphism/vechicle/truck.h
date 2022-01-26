
#pragma once
#include <iostream>
#include "vehicle.h"

using namespace std;

class Truck : public Vehicle {

public:
    void print() {
        cout << "Truck ";
    }
};