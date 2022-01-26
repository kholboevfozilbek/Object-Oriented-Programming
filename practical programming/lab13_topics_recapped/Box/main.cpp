

#include <iostream>
#include <string>
#include <cmath>
#include "box.h"
#include "brick_box.h"
#include "tube_box.h"
#include "bubble_box.h"
#include "store.h"

using namespace std;


int main()
{
    Store store("My home store", 100);
    cout << Box::get_countBoxes() << endl; //0

    try {
        store.addFirst(new BrickBox("books", 1234, 5, 3.5, 4)); //5 x 3.5 x 4
        store.addFirst(new TubeBox("posters", 2234, 1, 3)); //radius=1, height=3
        store.addLast(new BubbleBox("sweets", 5413, 1)); //radius=1
        store.addLast(new BrickBox("jewels", 2114, 2, 2, 2)); //2 x 2 x 2
        store.addFirst(new BrickBox("trinkets", 3456, 3, 4, 1)); //3 x 4 x 1
    } catch(Store::CapacityError &e) {
        cout << e.what() << endl; //trinkets too large - only 10.5 free space
    }

    cout << store << endl;

    cout << Box::get_countBoxes() << endl;

    cout << store.summaryVolume() << endl; //89.5

    store.removeFirst();

    cout << Box::get_countBoxes() << endl; //3

    cout << store.summaryVolume() << endl; //80.1

    store.clear();
    cout << Box::get_countBoxes();

    try {
        cout << store[1]->getCapacity() << endl; //70.0
        cout << store[5]->getCapacity() << endl; //IndexError exception
    } catch(Store::IndexError &e) {
        cout << e.what(); //item no. 5 not found
    }
    puts("\n\n");
    return 0;
}
