
#pragma once
#include "figure.h"
#include <iostream>
#include <cmath>
using namespace std;


class Circle : public Figure
{
private:
    int radius;

public:
    Circle(int r=0): radius{r}
    {   }
    ~Circle() {cout << "\nCircle has been destroyed" << endl; }

    void setradius(int r) {radius = r; }
    int getradius(){return radius; }

    float getArea() override { return 3.14 * pow(radius, 2); }
    int getPerimeter() override { return 2* 3.14 * radius; }  // periemter  = circumference
    string print() override {return "Circle: radius = " + to_string(radius);  }
    void getData() override;
};

void Circle::getData()
{
    cout << "Enter the radius of the Circle: "; cin >> radius;
}   