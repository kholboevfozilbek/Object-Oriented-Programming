#pragma once
#include <iostream>
#include "vehicle.h"

using namespace std;

class Car : public Vehicle {

public:
    void print() {
        cout << "Car ";
    }
};