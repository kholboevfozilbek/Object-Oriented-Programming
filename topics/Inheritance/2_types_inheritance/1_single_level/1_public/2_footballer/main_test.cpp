

#include <iostream>
#include <string>
#include <stdexcept>
#include "Footballer_base.h"
#include "Derive_attacker_derived.h"

using namespace std;

int main(int argc, char* args[])
{
    Attacker Ronaldo("Cristiano", "Ronaldo", 7, "Real Madrid", "forward", 1.83, 75, 38);
    Ronaldo.setAll(96, 95, 99);
    cout << Ronaldo << endl;

    Ronaldo.run();
    Ronaldo.pass();
    Ronaldo.speedd(); cout << endl;
    Ronaldo.dribble(); cout << endl;
    Ronaldo.shoott();  cout << endl;

    cout << "\nName: " << Ronaldo.getname() << endl;

    puts("\n\n");
    return 0;
}