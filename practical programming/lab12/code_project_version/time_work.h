

#pragma once
#include <iostream>
#include <string>
#include "work.h"
using namespace std;

class TimeWork : public Work {

private:
    int m_hours;
    float m_price_hour;

public:
    TimeWork(string d="", string n="", int hours=0, float cost_per_hour=0.0f): Work(d, n), m_hours{hours}, m_price_hour{cost_per_hour}
    {   }

    virtual ~TimeWork() {cout << "TimeWork has been destroyed " << endl; }

    void setALL(int h, int cost);
    int gethours(){return m_hours; }
    float getprice_perhour() {return m_price_hour; }

    float getCost() override {return m_hours*m_price_hour; }
};

void TimeWork::setALL(int h, int cost)
{
    m_hours = h;
    m_price_hour = cost;
}

