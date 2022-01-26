


#pragma once

#include <iostream>
#include <string>
#include "work.h"
#include "piece_work.h"
#include "field_work.h"
#include "time_work.h"
#include <iomanip>
#include <list>
#include <vector>
using namespace std;

class Schedule
{

private:
    string m_description;
    double m_budget;
    std::list<Work*> works;

public:
    Schedule(string des="", double budget=0.0): m_description{des}, m_budget{budget}
    {   }

    ~Schedule() {cout << "Shedule has been completed" << endl; }
    void setALL(string d, double b);

    class EmptyError : public runtime_error {
    public:
        EmptyError(string what) : runtime_error(what)
        {   }
    };

    void insert(int location, Work* new_work);
    void remove_first() throw(EmptyError);
    void clear();

    friend ostream& operator<< (ostream& stream, const Schedule &o);
};

void Schedule::setALL(string d, double b)
{
    m_description = d;
    m_budget = b;
}

void Schedule::insert(int location, Work* new_work)
{
    if(location < 1)
        throw invalid_argument("Bad index!");

    int index_location = location - 1;

    if(index_location > works.size()-1)
        works.push_back(new_work);
    else if (index_location == works.size()-1)
    {
        auto it_j = works.rbegin();
        works.push_back(new PieceWork());
        auto it_i = works.rbegin();
        *it_i = *it_j;
        *it_j = new_work;
    }
    else {
        std::vector<Work*> vektor;
        for(auto copy_it = works.begin(); copy_it != works.end(); ++copy_it)
            vektor.push_back(*copy_it);
        int it_j = vektor.size()-1;
        int k = vektor.size()-1;
        vektor.push_back(new PieceWork());
        int it_i = vektor.size()-1;

        while(k > index_location)
        {
            vektor[it_i] = vektor[it_j];

            --it_j; --it_i; --k;
        }
        vektor[it_i] = vektor[it_j];
        vektor[it_j] = new_work;

        works.clear();

        for(auto it_vektor = vektor.begin(); it_vektor != vektor.end(); ++it_vektor)
            works.push_back(*it_vektor);
    }
}


ostream& operator<< (ostream& stream, const Schedule &o)
{
    int i=1;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    for(auto it = o.works.begin(); it != o.works.end(); ++it)
    {
        cout << i << ". " << (*it)->get_description() << " (" << (*it)->get_WorkerName() << ") cost: " << (*it)->getCost() << endl;
        ++i;
    }
    return stream;
}

void Schedule::remove_first() throw(EmptyError)
{
    if(works.size() == 0)
        throw EmptyError("There is no elements to remove!");
    auto it = works.begin();
    if(*it != nullptr)
        delete *it;

    works.pop_front();

}

void Schedule::clear()
{
    for(auto it = works.begin(); it != works.end(); ++it)
    {
        if(*it != nullptr)
            delete *it;
        works.pop_front();
    }
}
