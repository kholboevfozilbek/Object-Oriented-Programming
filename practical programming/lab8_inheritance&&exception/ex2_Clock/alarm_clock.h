
#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "clock.h"
#include <list>

using namespace std;


class AlarmClock : public Clock {

protected:
    std::list<Clock> alarm_times;
    bool enabled=true;

public:
    AlarmClock(int hours=0, int minutes=0, int seconds=0): Clock(hours, minutes, seconds)
    {
        cout << "Alarm clock has been created " << endl;
    }

    ~AlarmClock() {cout << "Alarm clock has been destroyed " << endl; }

    void addAlarm();
    void eraseAlarms() {alarm_times.clear(); cout << "\nAll alarms has been erased " << endl; }
    void enable_Alarms() {enabled = true; }
    void disable_Alarms() {enabled = false; }

    friend ostream& operator<< (ostream& stream, AlarmClock &o);


};

void AlarmClock::addAlarm()
{
    cout << "YOU ARE ADDING NEW ALARM TIME, PLEASE ENTER THE DETAILS: \n";
    Clock c;

    while(true)
    {
        try {
            c.setALL();
            break;
        } catch(exception &e) {

            cout << "ERROR HAS BEEN CAPTURED: " << e.what() << endl;
            cout << "Please Enter in correct format!!!" << endl;
        }
    }

    alarm_times.push_back(c);


    cout << "ALARM TIME HAS BEEN ADDED!\n";
}



ostream& operator<< (ostream& stream, AlarmClock &o)
{
    stream << "\nAlarm Clock:  \n";
    stream << "Time in format hh:mm:ss" << endl;
    stream << "------------------------" << endl;
    if(o.enabled == true)
        for(auto it = o.alarm_times.begin(); it != o.alarm_times.end(); ++it)
        {
            stream << *it <<  endl;
        }
    else
        stream << "ALL ALARMS ARE DISABLED" << endl;

    return stream;
}

