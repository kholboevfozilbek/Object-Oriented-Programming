

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "box.h"
#include "brick_box.h"
#include "tube_box.h"
#include "bubble_box.h"

using namespace std;

class Store {

private:

    string m_description;
    float m_totalCapacity;
    float m_available;
    std::list<Box*> box_list;

public:
    Store(string des="", float capacity=0.0f): m_description{des}, m_totalCapacity{capacity}, m_available{capacity}
    {

    }

    ~Store() {cout << "Store has been destroyed " << endl; }

    class CapacityError : public logic_error {
    public:
        CapacityError(string what): logic_error(what) {     }
    };

    class EmptyError : public logic_error {
    public:
        EmptyError(string what) : logic_error(what) {   }
    };

    class IndexError : public logic_error {
    public:
        IndexError(string what) : logic_error(what) {  }
    };

    void addFirst(Box* new_box) throw(CapacityError);
    void addLast(Box* new_box) throw(CapacityError);

    void remove_first() throw(EmptyError);
    void removeALL();

    float summaryVolume();

    friend ostream& operator<< (ostream& stream, Store& o);
    Box& operator[] (int index) throw(IndexError);

};

void Store::addFirst(Box* new_box) throw(CapacityError)
{
    if(new_box->getCapacity() > m_available)
    {
        delete new_box;
        throw CapacityError("NO PLACE FOR THAT BOX IN STORE!");
    }

    box_list.push_front(new_box);
    m_available -= new_box->getCapacity();
}

void Store::addLast(Box* new_box) throw(CapacityError)
{
    if(new_box->getCapacity() > m_available)
    {
        delete new_box;
        throw CapacityError("NO PLACE FOR THAT BOX IN STORE!");
    }

    box_list.push_back(new_box);
    m_available -= new_box->getCapacity();
}

void Store::remove_first() throw(EmptyError) {
    if(box_list.size() == 0)
        throw EmptyError("Store is EMPTY");

    auto it = box_list.begin();
    m_available += (*it)->getCapacity();
    delete *it;

    box_list.pop_front();
}

void Store::removeALL()
{
    for(auto it = box_list.begin(); it != box_list.end(); ++it)
    {
        delete *it;
    }
    box_list.clear();
    m_available = m_totalCapacity;
}

float Store::summaryVolume()
{
    float sum =0.0f;
    for(auto it = box_list.begin(); it != box_list.end(); ++it)
    {
        sum += (*it)->getCapacity();
    }

    return sum;
}

Box& Store::operator[] (int index) throw(IndexError)
{
    if(index < 1 || index >= box_list.size())
        throw IndexError("BAD INDEX ACCESS!");

    int loc_index = index - 1, i=0;

    for(auto it = box_list.begin(); it != box_list.end(); ++it)
    {
        if(i == loc_index)
        {
            return **it;
        }

        ++i;
    }
}

ostream& operator<< (ostream& stream, Store& o)
{
    stream << "STORE: " << endl;
    stream << "DESCRIPTION: " << o.m_description << endl;
    stream << "TOTAL CAP:   " << o.m_totalCapacity << endl;
    stream << "AVAILABLE CAP:   " << o.m_available << endl;
    stream << "CONTENTS:    \n\n";
    for(auto it = o.box_list.begin(); it != o.box_list.end(); ++it)
    {
        stream << ((*it)->print()).str() << endl;
    }

    return stream;
}
