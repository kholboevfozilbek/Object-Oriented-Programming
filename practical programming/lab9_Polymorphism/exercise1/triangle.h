

#pragma once

#include "figure.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;

class Sides_Error : public runtime_error
{

public:
    Sides_Error(string what="We can not create triangle with sides given"): runtime_error(what)
    {   }
};


class Triangle : public Figure
{
private:
    int a, b, c; // 3 sides of the triangle

public:
    Triangle(int _a=0, int _b=0, int _c=0);

    ~Triangle() {cout << "\nTriangle as been destroyed" << endl; }

    void setALL(int _a, int _b, int _c);
    int geta() {return a; }
    int getb() {return b; }
    int getc() {return c; }

    float getArea() override;
    int getPerimeter() override {return a+b+c; } 

    string print() override;
    void getData() override;
};

void Triangle::setALL(int _a, int _b, int _c)
{
    a = _a; b = _b; c = _c; 
}

string Triangle::print()
{
    return "Triangle: \na = " + to_string(a) + "  b = " + to_string(b) + "  c = " + to_string(c);
}

Triangle::Triangle(int _a, int _b, int _c)
{
    a = _a; b = _b; c = _c;
}

float Triangle::getArea()
{
    float s = (a+b+c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void Triangle::getData()
{   
    int side1, side2, side3;
    cout << "Enter side a: "; cin >> side1;
    cout << "Enter side b: "; cin >> side2;
    cout << "Enter side c: "; cin >> side3;

    if(side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
        throw Sides_Error("Given 3 sides can NOT be triangle");
    a= side1;
    b = side2;
    c= side3;
}


