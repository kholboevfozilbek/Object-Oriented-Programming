
#include <iostream>
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{

    public:
        Triangle(int n_s): Shape(n_s, 0.0f, 0.0f)
        {   }
        friend ostream& operator<< (ostream& stream, const Triangle &o);

};

ostream& operator<< (ostream& stream, const Triangle &o)
{
    stream << Shape(o) << endl;
    return stream;
}

int main(int argc, char* args[])
{
    Triangle t{3};
    cout << t << endl;
    return 0;
}

