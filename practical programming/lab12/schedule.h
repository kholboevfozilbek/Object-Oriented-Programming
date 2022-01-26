


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
    double original;
    std::list<Work*> works;

public:
    Schedule(string des="", double budget=0.0): m_description{des}, m_budget{budget}, original{budget}
    {   }

    ~Schedule() {cout << "Shedule has been completed" << endl; clear(); }
    void setALL(string d, double b);

    class EmptyError : public runtime_error {
    public:
        EmptyError(string what) : runtime_error(what)
        {   }
    };

    class DeficitError : public runtime_error {
    public:
        DeficitError(string what): runtime_error(what)
        {   }
    };

    class IndexError : public out_of_range {
    public:
        IndexError(string what): out_of_range(what)
        {   }
    };

    double get_budget() {return m_budget;  }
    void remove_first() throw(EmptyError);
    void clear();
    void insert( Work* new_work, int location=-1) throw(DeficitError);
    double summaryCost();

    friend ostream& operator<< (ostream& stream, const Schedule &o);
    Work*& operator[] (unsigned int location) throw(IndexError);
};

void Schedule::setALL(string d, double b)
{
    m_description = d;
    m_budget = b;
}


void Schedule::insert(Work* new_work, int location) throw(DeficitError)
{
    if(location == -1){  //push to end of the list if the position doesn't exist.
        if(new_work->getCost() > m_budget)
            throw DeficitError(new_work->get_description() + " is too expensive, only " + to_string(m_budget) + " free money!!!");
        works.push_back(new_work);
        m_budget = m_budget - new_work->getCost();
    }
    else {
        int index_location = location-1;
        int size = works.size();
        
        if(index_location > size - 1) {
            if(new_work->getCost() > m_budget)
                throw DeficitError(new_work->get_description() + " is too expensive, only " + to_string(m_budget) + " free money!!!");
            works.push_back(new_work);
            m_budget = m_budget - new_work->getCost();
        }
        else if(index_location == size-1)
        {
            if(new_work->getCost() > m_budget)
                throw DeficitError(new_work->get_description() + " is too expensive, only " + to_string(m_budget) + " free money!!!");
            std::vector<Work*> vektor;
            for(auto copy_it = works.begin(); copy_it != works.end(); ++copy_it)
                vektor.push_back(*copy_it);
            int it_j = vektor.size()-1;
            vektor.push_back(new PieceWork());
            delete vektor[vektor.size() - 1];
            int it_i = vektor.size()-1;

            vektor[it_i] = vektor[it_j];
            vektor[it_j] = new_work;
            m_budget -= new_work->getCost();
            works.clear();

            for(auto it_vektor = vektor.begin(); it_vektor != vektor.end(); ++it_vektor)
                works.push_back(*it_vektor);
        }
        else {
            if(new_work->getCost() > m_budget)
                throw DeficitError(new_work->get_description() + " is too expensive, only " + to_string(m_budget) + " free money!!!");
            std::vector<Work*> vektor;
            for(auto copy_it = works.begin(); copy_it != works.end(); ++copy_it)
                vektor.push_back(*copy_it);
            int it_j = vektor.size()-1;
            int k = vektor.size()-1;
            vektor.push_back(new PieceWork());
            delete vektor[vektor.size() - 1]; // we have to delete for reason our static member got incremented on e additionlay
            int it_i = vektor.size()-1;

            while(k > index_location)
            {
                vektor[it_i] = vektor[it_j];
                
                --it_j; --it_i; --k;
            }
            vektor[it_i] = vektor[it_j];
            vektor[it_j] = new_work;
            m_budget -= new_work->getCost();
            works.clear();

            for(auto it_vektor = vektor.begin(); it_vektor != vektor.end(); ++it_vektor)
                works.push_back(*it_vektor);
        }

    }

}   

ostream& operator<< (ostream& stream, const Schedule &o)
{
    int i=1;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    stream << endl << o.m_description << " : " << o.original << " , remaining money: " << o.m_budget << endl;
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
        delete *it;
        works.pop_front();
    }
}

double Schedule::summaryCost()
{
    double sum = 0.0;

    for(auto it = works.begin(); it != works.end(); ++it)
        sum += (*it)->getCost();
    return sum;
}

Work*& Schedule::operator[] (unsigned int location) throw(IndexError)
{
    int index = location - 1;

    if(index < 0 || index >= works.size())
        throw IndexError("Bad index!!!");
    
    int i=0;
    for(auto it = works.begin(); it != works.end(); ++it)
    {
        if(i == index)
            return *it;
        ++i;
    }

}


