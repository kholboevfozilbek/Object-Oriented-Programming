

#include <iostream>
#include "Entry.h"
#include "phonEntry.h"

using namespace std;

int main()
{
    ///Entry e; abstract class can not have objects
    PhoneEntry p("Muhammadqodir", "+48 532 312 690");

    cout << p.getContents();

    return 0;
}