
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "box.h"

using namespace std;

class BrickBox : public Box {

private:
    float m_length;
    float m_width;
    float m_height;

public:
    BrickBox(string label="", int number=0, float length=0, float width=0, float height=0): Box(label, number), m_length{length}, m_width{width}, m_height{height}
    {

    }

    virtual ~BrickBox() {/*cout << "BrickBox has been destroyed" << endl; */ }

    void setALL(float length, float width, float height);

    float get_length() {return m_length; }
    float get_width() {return m_width; }
    float get_height() {return m_height; }

    float getCapacity() override;

    ostringstream print() override;

};

void BrickBox::setALL(float length, float width, float height)
{
    m_length =length;
    m_width = width;
    m_height =height;

}

float BrickBox::getCapacity()
{
    return (float)m_length * m_width * m_height;
}

ostringstream BrickBox::print()
{
    ostringstream os;
    os << "BOX: -> BRICK BOX" << endl;
    os << "-------------------\n";
    os << "LABEL: " << m_label << endl;
    os << "NUMBER: " << m_number << endl;
    os << "CAPACITY: " << getCapacity() << endl;
    os << "LENGTH: " << m_length << endl;
    os << "WIDTH: " << m_width << endl;
    os << "HEIGHT: " << m_height << endl;
    return os;
}

