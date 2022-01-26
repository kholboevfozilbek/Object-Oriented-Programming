

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "box.h"
#include <sstream>

using namespace std;


class TubeBox : public Box {

private:
    float m_radius;
    float m_height;

public:
    TubeBox(string label="", int number=0, float radius=0.0f, float height=0.0f): Box(label, number),
        m_radius{radius}, m_height{height} { }
    virtual ~TubeBox(){ /*cout << "TubeBox has been destroyed " << endl;*/  }

    void setALL(float radius, float height);
    float get_radius() {return m_radius; }
    float get_height() {return m_height; }

    float getCapacity() override;
    ostringstream print() override;
};

void TubeBox::setALL(float radius, float height)
{
     m_radius = radius;
     m_height = height;
}

float TubeBox::getCapacity() {
    return  3.14 * pow(m_radius, 2) * m_height;
}

ostringstream TubeBox::print() {

    ostringstream os;
    os << "BOX: -> TUBE BOX" << endl;
    os << "-------------------\n";
    os << "LABEL: " << m_label << endl;
    os << "NUMBER: " << m_number << endl;
    os << "CAPACITY: " << getCapacity() << endl;
    os << "RADIUS: " << m_radius << endl;
    os << "HEIGHT: " << m_height << endl;

    return os;
}
