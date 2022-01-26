

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Box {

protected:
    float m_length;
    float m_width;
    float m_height;
    float m_free_volume;
    string m_content_description;
    static int count_boxes;

public:
    Box(float length=0.0f, float width=0.0f, float height=0.0f): m_length{length}, m_width{width}, m_height{height}
    {   }

    ~Box() {cout << "\nBox has been destroyed" << endl; }

    class EmptyError : public logic_error {
    public:
        EmptyError(string what): logic_error(what) {    }
    };

    class CapacityError : public logic_error {
    public:
        CapacityError(string what): logic_error(what) {     }
    };

    float getCapacity() {return m_length * m_width * m_height; }

    void setContents(string content="", float volume_content=0.0f) throw(CapacityError);

    string getContents() throw(EmptyError);

    float get_free_volume() {return m_free_volume; }

    static int get_BoxCount() {return count_boxes; }

    friend ostream& operator<< (ostream& stream, Box &o);
};

int Box::count_boxes=0;

void Box::setContents(string content, float volume_content) throw(CapacityError)
{
    if(volume_content > getCapacity())
        throw CapacityError("Volume of the content is LARGER than Box supports!!!");
    m_content_description = content;
    m_free_volume = getCapacity() - volume_content; 
}

string Box::getContents() throw(EmptyError)
{
    if(getCapacity() == 0)
        throw EmptyError("Box is EMPTY");
    return m_content_description;
}

ostream& operator<< (ostream& stream, Box &o)
{
    stream << "\nBox Details:  " << endl;
    stream << "--------------------------" << endl;
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