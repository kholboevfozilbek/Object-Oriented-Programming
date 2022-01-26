
#pragma once
#include "figure.h"
#include <iostream>
using namespace std;


class Rectangle : public Figure 
{
private:
    int height;
    int width;

public:
    Rectangle(int h=0, int w=0):
        height{h}, width{w}
    {   }
    ~Rectangle(){cout << "\nRectangle has been destroyed " << endl; }

    void setALL(int h, int w);
    int getheight() {return height; }
    int getwidth() {return width; }

    float getArea() override {return height*width; }
    int getPerimeter() override {return  2*(height+width);  }
    string print() override;
    void getData() override;
};

void Rectangle::setALL(int h, int w)
{
    height = h;
    width = w;
}

string Rectangle::print()
{
    return "Rectangle: \nHieght = " + to_string(height) + "\nwidth = " + to_string(width);
}

void Rectangle::getData()
{
    cout << "Enter height of rectangle:  "; cin >> height;
    cout << "Enter length of width: "; cin >> width;
}
