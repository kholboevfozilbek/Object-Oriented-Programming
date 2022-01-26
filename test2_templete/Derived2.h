

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "abstract.h"

using namespace std;


class Derived2 : public Name {

private:
    string new_m1;
    int new_m2;
    float new_m3;


public:
    Derived2(string member1="", int member2=0, float member3=0.0f, string n_m1="", int n_m2=0, float n_m3=0.0f): Name(member1, member2, member3), new_m1{n_m1}, new_m2{n_m2}, new_m3{n_m3} {     }

    ~Derived2() {  }

    void set_newm1(string m1) {new_m1 = m1; }
    void set_newm2(int m2) {new_m2 = m2; }
    void set_newm3(float m3) {new_m3 = m3; }

    string get_m1n() {return new_m1; }
    int get_m2n() {return new_m2; }
    float get_m3n() {return new_m3; }

    int pure_virtual_method() override;
    ostringstream print() override;

};