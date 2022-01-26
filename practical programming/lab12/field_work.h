

#pragma once
#ifndef FIELD_WORK_H_KNOWN
#define FIELD_WORK_H_KNOWN
#include <iostream>
#include <string>
#include "work.h"
using namespace std;

class FieldWork : public Work {

private:
    float m_width, m_height;
    float m_price_per_square;

public:
    FieldWork(string d="", string n="", float w=0.0f, float h=0.0f, float cost_square=0.0f): Work(d, n), m_width{w}, m_height{h}, m_price_per_square{cost_square}
    {   }
    virtual ~FieldWork() {cout << "FieldWork has been destroyed " << endl; }

    void setALL(int w, int h, float cost);
    float getwidth() {return m_width; }
    float getheight() {return m_height; }
    float getcost() {return m_price_per_square; }

    float getCost() override {return m_price_per_square*(m_width*m_height);  }
};

void FieldWork::setALL(int w, int h, float cost)
{
    m_width =w;
    m_height = h;
    m_price_per_square = cost; 
}


#endif  