
#pragma once
#include <iostream>
#include <string>
#include "person.h"

using namespace std;


class Student : public Person {

private:
    float gpa;

public:
    void getData() override;
    bool isOutstanding() override {return (gpa>3.5)? true : false; }
};

void Student::getData()
{
    Person::getName();
    cout << "Enter student's GPA: ";
    cin >> gpa;
}