

#include <iostream>
#include "footballer_base.h"
#include "attacker_derived.h"

using namespace std;

int main()
{
    Attacker lewi("Robert", "Lewandowski", 7, "Bayern Munich", "forward", 1.80, 78, 39);

    cout << lewi << endl;
    cout << "name : " << lewi.getname_from_derived() << endl;
    return 0;
}