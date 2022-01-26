#pragma once

#ifndef SHAPE_BASE_H_KNOWN
#define SHAPE_BASE_H_KNOWN

#include <iostream>

using namespace std;

class Shape
{

protected:
    int number_sides;
    float area;
    float circumference;

public:

    Shape(int n_s, float ar, float cir): number_sides{n_s}, area{ar}, circumference{cir}
    {   }
    Shape(): number_sides{0}, area{0.0f}, circumference{0.0f}
    {   }
    ~Shape();
    //Shape(const Shape& o);
    float getarea() {return area; }
    float getperimeter() {return circumference; }

    Shape& operator= (const Shape &o);
    friend ostream& operator<< (ostream& stream, const Shape &o);

};

Shape::~Shape()
{
    cout << "\n shape has been removed " << endl;
}

ostream& operator<< (ostream& stream, const Shape &o)
{
    stream << "Area:  " << o.area << "\nPerimeter: " << o.circumference << endl;
    return stream;
}

#endif