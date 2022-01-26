

#include "bombers_derived_Military.h"
#include "military_derived_derived.h"
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    Bombers suv(970, 88.63, "petrol", 6, 7, 640.75, "evacuvators", 0);

    cout << suv << endl;

    cout << "\n*****************************\n";
    cout << "Speed:  " << suv.getspeed_derived() << endl;
    cout << "Engine: " << suv.getengine_derived() << endl;
    suv.move_derived();

    cout << "\n------------------------------\n";
    cout << "Num engine:  " << suv.getnum_engine_derived() << endl;
    cout << "Num crews: " << suv.getnum_engine_derived() << endl;
    suv.fly_derived();
    suv.takeoff_derived();
    suv.land_derived();

    return 0;
}