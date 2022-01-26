


#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "box.h"

using namespace std;

class BrickBox : public Box {

private:

    float m_length;
    float m_width;
    float m_height;


public:
    BrickBox(string label="", int number=0, float length=0.0f, float width=0.0f, float height=0.0f): Box(label, number), m_length{length}, m_width{width}, m_height{height}
    {     }

    virtual ~BrickBox() {  }


    void setALL(float length, float width, float height);

    float get_length() {return m_length; }
    float get_width() {return m_width; }

    float getCapacity() override;
    ostringstream print() override;

};

void BrickBox::setALL(float length, float width, float height)
{
    m_length = length;
    m_width = width;
    m_height = height;
}

float BrickBox::getCapacity()
{
    return m_length * m_width * m_height;
}

ostringstream BrickBox::print()
{
    ostringstream os;

    os << "BOX: - >BRICKBOX\n";
    os << "----------------\n";
    os << "NUMBER: " << m_number << endl;
    os << "LABEL:  " << m_label << endl;
    os << "CAPACITY: " << getCapacity() << endl;
    os << "LENGTH: " << m_length << endl;
    os << "WIDTH:  " << m_width << endl;
    os << "HEIGHT: " << m_height << endl;

    return os;
}
