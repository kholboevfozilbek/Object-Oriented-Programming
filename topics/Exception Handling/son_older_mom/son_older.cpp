

#include <iostream>

using namespace std;

int main()
{
    puts("\n\n");
    int son, mom;

    cout << "Enter son's age: "; cin >> son;
    cout << "Enter mom's age: "; cin >> mom;

    try {
        if(son  > mom)
            throw 99;
    } catch(int error) {
        cout << "\nSon can not be older than his mom: ERROR number -> " << error << endl;
    }

    puts("\n\n");
    return 0;
}