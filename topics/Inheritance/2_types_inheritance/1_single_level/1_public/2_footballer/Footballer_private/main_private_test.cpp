
#include <iostream>
#include "Footballer_base_private_data.h"
#include "Attacker_derived.h"

using namespace std;

int main()
{
    Attacker Messi("Lionel", "Messi", 10, "Barcelona", "forward", 1.70, 68, 39);

    cout << Messi << endl;

    cout << "Get name from derived when the base has all date private! " << endl;
    cout << Messi.getname_derived() << endl;  
    return 0;
}