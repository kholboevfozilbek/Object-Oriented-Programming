

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include "box.h"

using namespace std;


class BubbleBox : public Box {

private:

    float m_radius;


public:
    BubbleBox(string label="", int number=0, float radius=0.0f): Box(label, number), m_radius{radius}
    {     }

    virtual ~BubbleBox() {  }


    void setALL(float radius) { m_radius = radius; }


    float get_radius() {return m_radius; }

    float getCapacity() override;
    ostringstream print() override;

};

ostringstream BubbleBox::print()
{
    ostringstream os;

    os << "BOX: - > BUBBLE BOX\n";
    os << "----------------\n";
    os << "NUMBER: " << m_number << endl;
    os << "LABEL:  " << m_label << endl;
    os << "CAPACITY: " << getCapacity() << endl;
    os << "RADIUS: " << m_radius << endl;

    return os;
}

float BubbleBox::getCapacity() {

    return (2.0/3.0) * 3.14 * pow(m_radius, 3);

}
