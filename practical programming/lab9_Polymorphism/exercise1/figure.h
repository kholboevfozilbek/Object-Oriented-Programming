

#pragma once
#ifndef FIGURE_H_KNOWN
#define FIGURE_H_KNOWN

#include <iostream>
using namespace std;

class Figure  // Abstract class
{
protected:
    static unsigned int count_figure; // for counting all Figures

public:
    Figure() {
        ++count_figure;
    } 
    virtual ~Figure() {cout << "\nFigure has been destroyed " << endl; }

    virtual float getArea() =0;   //pure virtual method
    virtual int getPerimeter() =0; //pure virtual method

    virtual string print() =0;
    virtual void getData() =0;

    static int get_figure_count() {return count_figure; }
};

unsigned int Figure::count_figure=0;

#endif