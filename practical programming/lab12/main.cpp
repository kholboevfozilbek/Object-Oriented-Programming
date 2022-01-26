


#include <iostream>
#include <string>
#include "work.h"
#include "piece_work.h"
#include "field_work.h"
#include "time_work.h"
#include "schedule.h"
#include <list>
using namespace std;


int main()
{
    Schedule repairs("Expected repairs of my room", 2000);

    cout << Work::get_CountWork() << endl;

    try {
        repairs.insert(new FieldWork("floor", "John", 4.5, 6, 30), 1);
        repairs.insert(new FieldWork("walls", "Luke", 21, 2.5, 15), 2);
        repairs.insert(new PieceWork("electric points", "Ben", 7, 20), 1);
        repairs.insert(new TimeWork("cleaning", "Mary",  18, 10), 4); 
        repairs.insert(new PieceWork("ligtnening", "Tom", 4, 30));
    } catch(Schedule::DeficitError &error) {
        cout << error.what() << endl;
    }

    cout << Work::get_CountWork() << endl;
    cout << repairs << endl;
    cout << "\nSummary cost: " << repairs.summaryCost() << endl;

    try {
        repairs.remove_first();
    } catch(Schedule::EmptyError &error) {
        cout <<"Exception has been caught:  " <<  error.what() << endl;
    }

    cout << repairs << endl;
    cout << Work::get_CountWork() << endl;
    cout << "\nSummary cost: " << repairs.summaryCost() << endl;

    try {
        cout << repairs[1]->getCost() << endl;
        cout << repairs[5]->getCost() << endl;
    } catch(Schedule::IndexError &e) {
        cout << e.what() << endl;
    }

    repairs.clear();
    cout << Work::get_CountWork() << endl;
    return 0;
}