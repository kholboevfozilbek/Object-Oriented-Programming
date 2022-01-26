

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <iomanip>
#include "clock.h"
#include "alarm_clock.h"
using namespace std;

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    Clock* now_point = nullptr;
    try {
        Clock* now = new Clock(15, 28, 17);

        now_point = now;

    } catch(exception &e) {
        cout << e.what() << endl;
    }

    AlarmClock a6;

    a6.addAlarm();
    a6.addAlarm();

    cout << a6 << endl;

    a6.disable_Alarms();
    cout << a6 << endl;


    a6.eraseAlarms();
    cout << a6 << endl;


    return 0;
}
