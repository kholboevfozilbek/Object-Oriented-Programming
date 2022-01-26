

#include "Footballer_base.h"
#include "Attacker_derived.h"
#include <iostream>

using namespace std;

int main()
{
    Attacker lewandowski("Robert", "Lewandowski", 7, "Bayern-Munich", "forward", 1.78, 78, 38);

    cout << "\n\nname: " << lewandowski.getname_derived_protected_mode();
    puts("\n\n");
    return 0;
}