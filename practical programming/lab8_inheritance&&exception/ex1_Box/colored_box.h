

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "box.h"

using namespace std;


class ColoredBox : public Box {

private:
    string m_color;

public:
    ColoredBox(float length=0.0f, float width=0.0f, float height=0.0f, string color="white"): Box(length, width, height), m_color{color}
    {   }

    ~ColoredBox() {cout << "ColoredBox has been destroyed" << endl; }

    string get_color() {return m_color; }
    void set_color(string color) {m_color = color; }
    friend ostream& operator<< (ostream& stream, ColoredBox &o);
};

ostream& operator<< (ostream& stream, ColoredBox &o)
{
    stream << "\nBox Details:  " << endl;
    stream << "--------------------------" << endl;
    stream << "Color: " << o.get_color() << endl;
    stream << "Contents: " << o.m_content_description << endl;
    if(o.getCapacity() == 0)
        stream << "Volume: " << o.getCapacity() << endl;
    else
        stream << "Remaining free volume: " << o.get_free_volume() << endl;
    
    stream << "original volume: " << o.getCapacity() << endl;
    stream << "Length: " << o.m_length << endl;
    stream << "Width: " << o.m_width << endl;
    stream << "Height: " << o.m_height << endl;
    return stream;
}