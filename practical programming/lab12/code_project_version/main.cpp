


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

    repairs.insert(1, new FieldWork("floor", "John", 4.5, 6, 30));
    /*repairs.insert(2, new FieldWork("walls", "Luke", 21, 2.5, 15));
    repairs.insert(1, new PieceWork("electric points", "Ben", 7, 20));
    repairs.insert(new TimeWork("cleaning", "Mary",  18, 10)); */

    cout << repairs << endl;

    /*cout << Work::get_CountWork() << endl;
    try {
        repairs.remove_first();
    } catch(Schedule::EmptyError &error) {
        cout <<"Exception has been caught:  " <<  error.what() << endl;
    }

    cout << repairs << endl;
    cout << Work::get_CountWork() << endl;*/

    return 0;
}
