
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Clock {

protected:
    int m_hour;  // 0 -> 23
    int m_minute; //0 -> 59
    int m_second; //0 -> 59
public:
    class HourError : public logic_error {
    public:
        HourError(string what) : logic_error(what) {    }
    };

    class MinuteError : public logic_error {
    public:
        MinuteError(string what) : logic_error(what) {    }
    };

    class SecondsError : public logic_error {
    public:
        SecondsError(string what) : logic_error(what) {    }
    };

    Clock(int hours=0, int minutes=0, int seconds=0) throw(HourError, MinuteError, SecondsError);
    ~Clock() {/* cout << "Clock has been destroyed " << endl;*/ }

    Clock(const Clock &o);

    void setHour(int hours) {m_hour = hours; }
    int getHour() {return m_hour; }

    void setMinute(int minutes) {m_minute = minutes; }
    int getMinute() {return m_minute; }

    void setSecond(int seconds) {m_second = seconds; }
    int getSecond() {return m_second; }

    friend ostream& operator<< (ostream& stream, Clock &o);

    void setALL() throw(HourError, MinuteError, SecondsError);


};

Clock::Clock(int hours, int minutes, int seconds) throw(HourError, MinuteError, SecondsError)
{
    if(hours < 0 || hours > 23)
        throw HourError("WRONG FORMAT OF HOURS!!!");

    if(minutes < 0 || minutes > 59)
        throw MinuteError("WRONG FORMAT OF MINUTES!!!");

    if(seconds < 0 || seconds > 59)
        throw SecondsError("WRONG FORMAT OF SECONDS!!!");

    m_hour = hours;
    m_minute = minutes;
    m_second = seconds;
}

ostream& operator<< (ostream& stream, Clock &o)
{
    stream << std::setw(2) << std::setfill('0') << o.getHour() << ":" << o.getMinute() << ":" << o.getSecond();
    return stream;
}

Clock::Clock(const Clock &o)
{
    m_hour = o.m_hour;
    m_minute = o.m_minute;
    m_second = o.m_second;
}

void Clock::setALL() throw(HourError, MinuteError, SecondsError)
{
    int hours, minutes, seconds;
    cout << "Enter the hour: "; cin >> hours;
    cout << "Enter the minutes: "; cin >> minutes;
    cout << "Enter the seconds: "; cin >> seconds;

    if(hours < 0 || hours > 23)
            throw HourError("WRONG FORMAT OF HOURS!!!");
    if(minutes < 0 || minutes > 59)
        throw MinuteError("WRONG FORMAT OF MINUTES!!!");

    if(seconds < 0 || seconds > 59)
        throw SecondsError("WRONG FORMAT OF SECONDS!!!");
    m_hour = hours;
    m_minute = minutes;
    m_second = seconds;
}
