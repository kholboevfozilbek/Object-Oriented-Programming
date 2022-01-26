

#include "bombers_derived_Military.h"
#include "military_derived_derived.h"
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    Bombers f12(850.96, 89.78, "petrol", 4, 5, 600, "atomic bomb", 3);
    cout << f12 << endl;

    cout << "\n\n-----------------------\n";
    cout << "Speed: " << f12.getspeed() << "  km/h" << endl;
    cout << "Engine: " << f12.getengine() << " power " << endl;
    cout << "Fuel:  " << f12.getgas_type() << endl;
    f12.move();
    f12.stop();
    cout << "\n----------------------------\n";
    cout << "Number of engines: " << f12.getnum_engine() << endl;
    cout << "number of crews:  " << f12.get_number_crews() << endl;
    cout << "kg support: " << f12.getkg_support() << endl;
    f12.fly();
    f12.take_off();
    f12.land();

    Bombers dushbacks[10];


    system("CLS");

    cout << "\n\ntotal air force:  " << Military::get_airforce() << endl;
    
    return 0;
}