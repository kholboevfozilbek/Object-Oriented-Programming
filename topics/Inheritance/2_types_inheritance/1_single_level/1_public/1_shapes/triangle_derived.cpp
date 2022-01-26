
#include <iostream>
#include <stdexcept>
#include "shape_base.h"
#include "triangle_derived.h"

using namespace std;


int main(int argc, char* args[])
{
    Triangle t{4, 5, 6};
    cout << t << endl;

    cout << "Area:  " << t.getarea() << endl;
    return 0;
}
