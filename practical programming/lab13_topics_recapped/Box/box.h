

#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Box {

protected:
    string m_label;
    int m_number;
    static int count_boxes;

public:
    Box(string label="", int number=0): m_label{label}, m_number{number}
    {
        ++count_boxes;
    }

    virtual ~Box() { /*cout << "Box has been destroyed" << endl;*/ --count_boxes; }

    static int get_countBoxes() {return count_boxes; }

    virtual float getCapacity() =0;

    virtual ostringstream print();
};

int Box::count_boxes=0;

ostringstream Box::print()
{
    ostringstream os;
    os << "BOX: \n" << endl;
    os << "-------------------\n";
    os << "LABEL: " << m_label << endl;
    os << "NUMBER: " << m_number << endl;
    return os;
}
