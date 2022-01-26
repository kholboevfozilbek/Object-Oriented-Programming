
#include <iostream>
using namespace std;

class Obj
{
private:
    int x;
    float f;

public:
    //Obj() = delete;
    Obj(int _x, float _f): x(_x), f(_f)
    {   }
    int getx() {return x; }
    float getf() {return f; }
    void print();

};

void Obj::print()
{
    cout << "x: " << x << " f: " << f << endl;
}

int main()
{
    Obj a(5, 8);
    a.print();
    puts("\n\n");
    return 0;
}