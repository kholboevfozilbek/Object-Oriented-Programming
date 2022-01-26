
#pragma once

#include <string>
#include <iostream>

using namespace std;

class Work
{

protected:
    string m_description;
    string m_NameWorker;
    static int count_work;

public:

    Work(string description="", string worker=""): m_description{description}, m_NameWorker{worker}
    {   ++count_work; }
    virtual ~Work() {cout << "Work has been destroyed " << endl; --count_work; }
    //Work(const Work &o); COPY CONSTRUCTOR
    //Work& operator== (const Work &o); ASSIGNMENT OPERATOR

    void setALL(string des, string name_worker);
    string get_description() {return m_description; }
    string get_WorkerName() {return m_NameWorker; }

    static int get_CountWork() {return count_work; }

    virtual float getCost() =0;
};
int Work::count_work=0;

void Work::setALL(string des, string name_worker)
{
    m_description = des;
    m_NameWorker = name_worker; 
}

