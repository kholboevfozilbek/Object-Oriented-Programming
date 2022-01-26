

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "box.h"
#include "brick_box.h"
#include "tube_box.h"
#include "bubble_box.h"
#include <list>
#include <stdexcept>

using namespace std;

class Store {

private:
    string m_description;
    float m_total_capacity;
    float m_avalable_space_left;
    std::list<Box*> box_list;
public:
    Store(string des="", float capacity=0.0f): m_description{des}, m_total_capacity{capacity}, m_avalable_space_left{capacity}
    {

    }

    virtual ~Store() { clear(); cout << "Store has been destroyed" << endl; }

    class CapacityError : public logic_error {
    public:
        CapacityError(string what): logic_error(what) { }
    };

    class EmptyError : public logic_error {
    public:
        EmptyError(string what): logic_error(what){  }
    };

    class IndexError : public logic_error {
    public:
        IndexError(string what): logic_error(what) {    }
    };

    void addFirst(Box* new_box) throw(CapacityError);
    void addLast(Box* new_box) throw(CapacityError);
    void removeFirst() throw(EmptyError);

    float summaryVolume();

    Box*& operator[] (unsigned int index) throw(IndexError);

    friend ostream& operator<< (ostream& stream, Store &o);

    void clear();
};

float Store::summaryVolume()
{
    return m_total_capacity  - m_avalable_space_left;
}

void Store::addFirst(Box* new_box) throw(CapacityError)
{
    if(new_box->getCapacity() > m_avalable_space_left)
    {
        delete new_box;
        throw CapacityError("WE DO NOT HAVE ENOUGH SPACE FOR THAT BOX IN THE SHOP!");
    }
    box_list.push_front(new_box);
    m_avalable_space_left = m_avalable_space_left - new_box->getCapacity();
}

void Store::addLast(Box* new_box) throw(CapacityError)
{
    if(new_box->getCapacity() > m_avalable_space_left)
    {
        delete new_box;
        throw CapacityError("WE DO NOT HAVE ENOUGH SPACE FOR THAT BOX IN THE SHOP!");
    }
    box_list.push_back(new_box);
    m_avalable_space_left = m_avalable_space_left - new_box->getCapacity();
}

void Store::removeFirst() throw(EmptyError)
{
    if(box_list.size() == 0)
        throw EmptyError("STORE IS EEMPTY, NO BOX TO REMOVE");

    auto it = box_list.begin();

    m_avalable_space_left += (*it)->getCapacity();
    delete *it;
    box_list.pop_front();
}

ostream& operator<< (ostream& stream, Store &o)
{
    stream << "STORE:   " << o.m_description << endl;
    stream << "TOTAL CAPACITY: " << o.m_total_capacity << endl;
    stream << "AVAILABLE CAPACITY: " << o.m_avalable_space_left << endl;
    for(auto it = o.box_list.begin(); it != o.box_list.end(); ++it)
    {
        stream << ((*it)->print()).str() << endl;
    }
    return stream;
}

void Store::clear()
{
    for(auto it = box_list.begin(); it != box_list.end(); ++it)
    {
        delete *it;
    }
    box_list.clear();
}

Box*& Store::operator[] (unsigned int index) throw(IndexError)
{
    if(index - 1 < 0 || index - 1 >= box_list.size())
        throw IndexError("BAD INDEX!!!");
    int i=0;

    for(auto it = box_list.begin(); it != box_list.end(); ++it)
    {
        if(i == index-1)
            return *it;
    }
}
