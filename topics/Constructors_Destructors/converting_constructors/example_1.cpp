

#include <iostream>
#include <string>
using namespace std;

class Entity {

private:
    int age=0;
    string name="unknown";

public:
    Entity(const string& n="unknown"):
        name{n}, age{0}
    {   }

    Entity(int a=0):
        age{a}, name{"unknown"}
    {   }

    void print() {
        cout << "\nname: " << name << endl;
        cout << "age:  " << age << endl;
    }
};

int main()
{
    Entity a = string("Fozil"); // implicit converting constructor calls
    Entity b = 18;

    a.print();
    b.print();
    puts("\n\n");
    return 0;
}