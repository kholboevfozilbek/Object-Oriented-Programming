

#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    Triangle t{4, 5, 6};
    cout << t << endl;

    cout << "\n\nArea:  " << t.getArea() << endl;
    return 0;
}