#include <iostream>


using namespace std;

class Counter
{
    unsigned int count=0;
    public:
    Counter(unsigned int _c=0)
    {
        count = _c;
    }
    unsigned int getcount(){ return count; }
    Counter operator++ ()
    {
        ++count;
        return Counter(count);
    }
};

int main()
{
    Counter c1, c2;
    ++c1;
    c2 = ++c1;



    cout << "c1: " << c1.getcount() << endl;
    cout << "c2: " << c2.getcount() << endl;



    return 0;
}