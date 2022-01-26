
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <math.h>
#include "shape_base.h"

using namespace std;

class Triangle : public Shape
{
    protected:

        int a, b, c; //sides

    public:
        Triangle(int _a, int _b, int _c);

        float areaa();
        float perimeter();

        bool isTriangle(int a, int b, int c);
        friend ostream& operator<< (ostream& stream, const Triangle &o);

        
};

float Triangle::areaa()
{
    float s = (a+b+c) / 2;
    return sqrt(s*(s-a) * (s-b) * (s - c));

}

float Triangle::perimeter()
{
    return (a + b + c);
}

Triangle::Triangle(int _a, int _b, int _c): Shape(3, 0.0f, 0.0f)
        { 
            if(isTriangle(_a, _b, _c) == true)
            {
                a=_a; b = _b; c = _c;
                area = areaa();
                circumference = perimeter();
            }
            else
                throw runtime_error("\nWith given sides, you can not create a triangle\n");
         
        }

ostream& operator<< (ostream& stream, const Triangle &o)
{
    stream << Shape(o) << "Sides: a=" << o.a << "  b=" << o.b << "  c=" << o.c << endl;;
    
    return stream;
}

bool Triangle::isTriangle(int a, int b, int c)
{
    if(a+b <= c || a+c <= b || b+c <= a)
        return false;
    return true;
}