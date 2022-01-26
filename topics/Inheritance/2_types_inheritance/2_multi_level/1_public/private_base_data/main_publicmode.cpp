

#include "bombers_derived_Military.h"
#include "military_derived_derived.h"
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    Bombers gtx1(900.87, 36, "petrol", 1, 1, 200, "Jet", 50);
    cout << gtx1 << endl;

    cout <<"\n------------------------------\n";
    cout << "Speed: " << gtx1.getspeed() << " km/h" << endl;
    cout << "Engine: " << gtx1.getengine() <<  " p/m" << endl;
    cout << "Fuel:  " << gtx1.getgas_type() << endl;
    gtx1.move();
    gtx1.stop();
    cout << "\n-----------------------------\n";
    cout << "Numebr engine: " << gtx1.getnum_engine() << endl;
    cout << "Number crew:  " << gtx1.get_number_crews() << endl;
    gtx1.fly();
    gtx1.take_off();
    gtx1.land();
    
    return 0;
}