

#include <iostream>
#include "Triangle_derived.h"

using namespace std;

int main()
{
    Triangle t{4, 5, 6};
    cout << "\n\nSHape: Triangle \n";
    cout << t << endl;

    //try to access data parts

    cout << t.getarea() << endl;

    return 0;
}