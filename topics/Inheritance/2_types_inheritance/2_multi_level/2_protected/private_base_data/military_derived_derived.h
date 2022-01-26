
#pragma once

#include "air_derived.h"
#include <iostream>

using namespace std;

class Military : protected Air
{

protected:
    static unsigned int count_airforce;

public:

    Military(float s=0.0f, float e=0.0f, std::string gas="petrol", int n_e=0, int n_c=0, float k_s=0.0f):
        Air(s, e, gas, n_e, n_c, k_s) {   ++count_airforce; cout << "\nMilitary Air vehicle has been created " << endl; }
    ~Military();
    //Military(Military &o);

    static unsigned int get_airforce() {return count_airforce; }
    friend ostream& operator<< (ostream& stream, const Military &o);

};

unsigned int Military::count_airforce=0;

Military::~Military()
{
    cout << "Military is destroyed " << endl;
    --count_airforce;
}



ostream& operator<< (ostream& stream, const Military &o)
{
    stream << Air(o);
    return stream;
}