

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "box.h"

using namespace std;

class WeightBox : public Box {

private:
    float m_wieght_support, free_left=0.0f; //kg

public:
    WeightBox(float length=0.0f, float width=0.0f, float height=0.0f, float weight=0.0f) : Box(length, width, height), m_wieght_support{weight}
    {   }

    ~WeightBox() {cout << "WeightBox has been destroyed" << endl; }

    class WeightError : public logic_error {
    public:
        WeightError(string what) : logic_error(what) {    }
    };
    void setContents(string contents, float content_measure) throw(WeightError);
    float get_weight_support() {return m_wieght_support; }
    friend ostream& operator<< (ostream& stream, WeightBox &o);
};

void WeightBox::setContents(string contents, float content_measure) throw(WeightError)
{
    if(content_measure > m_wieght_support)
        throw WeightError("Contents has bigger load(mass) than supported amount!!!");
    m_content_description = contents;
    free_left = m_wieght_support - content_measure;
}

ostream& operator<< (ostream& stream, WeightBox &o)
{
    
    stream << "\nBox Details:  " << endl;
    stream << "--------------------------" << endl;
    stream << "Contents: " << o.m_content_description << endl;
    if(o.free_left == 0)
        stream << "Weight supported: " << o.get_weight_support() << " (tons)" << endl;
    else
        stream << "Remaining free weight : " << o.free_left << " (tons)" << endl;
    
    //stream << "original volume: " << o.getCapacity() << endl;
    stream << "Length: " << o.m_length << endl;
    stream << "Width: " << o.m_width << endl;
    stream << "Height: " << o.m_height << endl;
    return stream;
}