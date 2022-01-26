
#pragma once
#include <iostream>
#include <string>
#include "work.h"
using namespace std;


class PieceWork : public Work {

private:
    int m_repetitions;
    float m_price_single_action;
    
public:
    PieceWork(string d="unknown", string n="unknown", int rep=0, float price_per=0.0f): Work(d, n), m_repetitions{rep}, m_price_single_action{price_per}
    {   }
    virtual ~PieceWork() {cout << "PieceWork has been destroyed " << endl; }

    void setALL(int rep, float price_per);
    int getrepetitions() {return m_repetitions; }
    float get_price_per() {return m_price_single_action; }

    float getCost() override {return m_repetitions*m_price_single_action;  }
   
};

void PieceWork::setALL(int rep, float price_per)
{
    m_repetitions = rep;
    m_price_single_action = price_per; 
}


