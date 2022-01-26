

#pragma once
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class Professor : public Person {

private:
    int num_pubs;

public:
    void getData() override;
    bool isOutstanding() override {return (num_pubs>100)? true : false; }
};

void Professor::getData()
{
    Person::getName();
    cout << "Enter professor's number publications:  ";
    cin >> num_pubs;
}