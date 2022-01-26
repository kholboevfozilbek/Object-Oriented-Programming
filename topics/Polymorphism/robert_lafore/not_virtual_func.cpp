
#include <iostream>
using namespace std;

class Base {

public:
    void show() {cout << "Base\n"; }
};

class Der1 : public Base {

public:
    void show() {cout << "Derv1\n"; }
};

class Der2 : public Base {

public:
    void show() {cout << "Derv2\n"; }
};

int main(int argc, char* args[])
{
    puts("\n\n");
    Der1 dv1;
    Der2 dv2;

    Base* ptr;

    ptr = &dv1;
    ptr->show();

    ptr = &dv2;
    ptr->show();

    puts("\n\n");
    return 0;
}