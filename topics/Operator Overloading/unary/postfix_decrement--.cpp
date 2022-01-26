#include <iostream>

using namespace std;

class Counter
{
    private:

    int m_count=0;

    public:

    Counter(int val) : m_count{val}
    { }

     int getcount() { return m_count; }
    Counter operator-- ()
    {
        return Counter(--m_count);
    }

    Counter operator-- (int)
    {
        return Counter(m_count--);
    }

};

int main()
{
    Counter c1(5), c2(5);

    

   c2 = --c1;
    cout << "c1: " << c1.getcount() << endl;
    cout << "c2: " << c2.getcount() << endl;

    c2 = c1--;
    cout << "c1: " << c1.getcount() << endl;
    cout << "c2: " << c2.getcount() << endl;

    return 0;
}