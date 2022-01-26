
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Name {

protected:
    string m_member1;
    int m_member2;
    float m_member3;
    static unsigned int m_count_all;

public:
    Name(string member1="", int member2=0, float member3=0.0f): m_member1{member1}, m_member2{member2}, m_member3{member3}
    {  ++m_count_all;  }

    virtual ~Name() { --m_count_all;  }

    static unsigned int get_countALL() {return m_count_all; }

    void setALL(string m1, int m2, float m3);
    void setm1(string m1) {m_member1 = m1; }
    void setm2(int m2) {m_member2 = m2; }
    void setm3(float m3) {m_member3 = m3; }

    string get_m1() {return m_member1; }
    int get_m2() {return m_member2; }
    float get_m3() {return m_member3; }

    virtual int pure_virtual_method() =0;

    virtual ostringstream print();
};

unsigned int Name::m_count_all=0;

void Name::setALL(string m1, int m2, float m3)
{
    m_member1 = m1;
    m_member2 = m2;
    m_member3 = m3; 
}

ostringstream Name::print()
{
    ostringstream os;
    //the details of class
    // os << "Member1: " << m_member1 << endl;
    return os;
}