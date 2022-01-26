#include <iostream>

using namespace std;

class Counter
{
    private:

    unsigned int m_count=0;

    public:

    Counter(unsigned int val) : m_count{val}
    { }

    unsigned int getcount() { return m_count; }
    void operator-- ()
    {
        --m_count;
    }

};

int main()
{
    Counter c1(5), c2(5);

    cout << "c1: " << c1.getcount() << endl;
    cout << "c2: " << c2.getcount() << endl;

    --c1;
    --c2;
    --c2;

    cout << "c1: " << c1.getcount() << endl;
    cout << "c2: " << c2.getcount() << endl;

    return 0;
}