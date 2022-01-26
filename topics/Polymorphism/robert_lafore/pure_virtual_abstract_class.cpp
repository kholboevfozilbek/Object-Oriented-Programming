
#include <iostream>
using namespace std;

class Base {

public:
    virtual void show() =0;
};

class Der1 : public Base {

public:
    void show() override {cout << "Derv1\n"; }
};

class Der2 : public Base {

public:
    void show() override {cout << "Derv2\n"; }
};

int main(int argc, char* args[])
{
    puts("\n\n");
    Der1 dv1;
    Der2 dv2;

    Base* p[2];

    p[0] = &dv1;
    p[1] = &dv2;

    p[0]->show();
    p[1]->show();

    puts("\n\n");
    return 0;
}