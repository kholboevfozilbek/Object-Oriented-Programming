
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Mammal {

protected:
    string name;
    float weight;
    float age;
    static int cout_animals;

public:
    Mammal(string n="", float w=0.0f, float a=0.0f): name{n}, weight{w}, age{a}
    { ++cout_animals;  }

    virtual ~Mammal() {cout << "\nMammal has been destroyed" << endl;}

    virtual void utterVoice() =0;

    void setALL(string n, float w, float a) {name = n; weight = w; age = a; }
    string getname() {return name; }
    float getage() {return age; }
    float getweight() {return weight; }

};

int Mammal::cout_animals=0;