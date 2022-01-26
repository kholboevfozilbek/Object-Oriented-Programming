


#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Box {

protected:
    string m_label;
    int m_number;
    static unsigned int m_count_boxes;

public:
    Box(string label="", int number=0): m_label{label}, m_number{number}
    {  ++m_count_boxes;  }

    virtual ~Box() { --m_count_boxes;  }

    static unsigned int get_countBoxes() {return m_count_boxes; }

    void setALL(string label, int number);
    void setlabel(string label) {m_label = label; }
    void setnumber(int number) {m_number = number; }


    string get_label() {return m_label; }
    int get_number() {return m_number; }

    virtual float getCapacity() =0;

    virtual ostringstream print();
};

unsigned int Box::m_count_boxes=0;

void Box::setALL(string label, int number)
{
    m_label = label;
    m_number = number;
}

ostringstream Box::print()
{
    ostringstream os;
    os << "BOX:\n";
    os << "----------------\n";
    os << "NUMBER: " << m_number << endl;
    os << "LABEL:  " << m_label << endl;

    return os;
}
