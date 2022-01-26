

#include <iostream>
#include <string>
#include <stdexcept>
#include "box.h"
#include "weight_box.h"
#include "colored_box.h"

using namespace std;

int main()
{
    puts("\n\n");
    /*Box africa(5, 2.5, 1.5);

    try {
        africa.setContents("Fruits: banana, mango, orange", 17.8);
    } catch(Box::CapacityError &e) {
        cout << e.what() << endl;
        cout << "\nPlease enter amount that box supports!!!";
    }

    cout << africa << endl;*/

    WeightBox cars(10.5, 4.0, 2.5, 50);

    try {
        cars.setContents("Tesla Electric Cars: Model S -> 3", 15);

    } catch(WeightBox::WeightError &e) {
        cout  << "ERRO has been captured:  " << e.what() << endl;
    }

    cout << cars << endl;
    
    puts("\n\n");
    return 0;
}