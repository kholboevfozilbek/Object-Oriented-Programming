
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {

protected:
    char name[40];

public: 
    Person() = default;
    //virtual ~Person();

    void getName();
    void putName() {cout << "Name is: " << name << endl;}
    virtual void getData() =0;
    virtual bool isOutstanding() =0;
};

void Person::getName()
{
    cout << "Enter the name: ";
    cin >> name;
}