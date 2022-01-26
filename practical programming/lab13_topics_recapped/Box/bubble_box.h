

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "box.h"

using namespace std;

class BubbleBox : public Box {

private:
    float m_radius;

public:
    BubbleBox(string label="", int number=0, float radius=0.0f): Box(label, number), m_radius{radius}
    {

    }

    virtual ~BubbleBox() { /*cout << "BubbleBox has been destroyed" << endl; */ }

    void setradius(float radius) {m_radius=radius; }
    float get_radius() {return m_radius; }

    float getCapacity() override;

    ostringstream print() override;

};

float BubbleBox::getCapacity()
{
    return  (float)(2.0/3.0) * 3.14 * m_radius;
}

ostringstream BubbleBox::print() {
    ostringstream os;
    os << "BOX: -> heisphere" << endl;
    os << "-------------------\n";
    os << "LABEL: " << m_label << endl;
    os << "NUMBER: " << m_number << endl;
    os << "CAPACITY: " << getCapacity() << endl;
    os << "RADIUS: " << m_radius << endl;

    return os;
}
