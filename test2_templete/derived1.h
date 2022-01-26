

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "abstract.h"

using namespace std;

class Derived1 : public Name {

private:
    string m1n;
    int m2n;
    float mn3;


public:
    Derived1(string member1="", int member2=0, float member3=0.0f, string new_m1="", int new_m2=0, float new_m3=0.0f): Name(member1, member2, member3), m1n{new_m1}, m2n{new_m2}, mn3{new_m3} {     }

    ~Derived1() {  }

    void setm1n(string m1) {m1n = m1; }
    void setm2n(int m2) {m2n = m2; }
    void setm3n(float m3) {mn3 = m3; }

    string get_m1n() {return m1n; }
    int get_m2n() {return m2n; }
    float get_m3n() {return mn3; }

    int pure_virtual_method() override;
    ostringstream print() override;

};

int Derived1::pure_virtual_method() {

}

ostringstream Derived1::print() 
{
    ostringstream os;

    return os;
}