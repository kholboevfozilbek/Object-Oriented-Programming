#pragma once

#ifndef SHAPE_H_KNOWN
#define SHAPE_H_KNOWN

#include <iostream>

using namespace std;

class Shape
{

protected:
    int number_sides;
    float area;
    float circumference;

public:

    Shape(int n_s=0, float ar=0.0f, float cir=0.0f): number_sides{n_s}, area{ar}, circumference{cir}
    {   }
    Shape(): number_sides{0}, area{0.0f}, circumference{0.0f}
    {   }
    ~Shape();
    //Shape(const Shape& o);


    Shape& operator= (const Shape &o);
    friend ostream& operator<< (ostream& stream, const Shape &o);

};

Shape::~Shape()
{
    cout << "\n shape has been removed " << endl;
}

ostream& operator<< (ostream& stream, const Shape &o)
{
    stream << "\nShape: \n" << "Number of sides: " << o.number_sides  << endl;
    stream << "Area:  " << o.area << "\nPerimeter: " << o.circumference << endl;
    return stream;
}

#endif
