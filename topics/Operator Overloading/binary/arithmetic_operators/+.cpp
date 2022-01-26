#include <iostream>

using namespace std;

class Distance
{
    private:
    int feet;
    float inch;

    public:
    Distance(): feet{0}, inch{0.0}
    {   }
    Distance(int f, float i): feet{f}, inch{i}
    {   }

    void getdist()
    {
        cout << "\nEnter the feet: "; cin >> feet;
        cout << "Enter the inches: \n"; cin >> inch;
    }

    void print() const
    {
        cout << feet << "\' -" << inch << "\"\n";
    }
    
    Distance& operator+ (const Distance &o) const
    {
        int f = feet + o.feet;
        float i = inch + o.inch;

        if(i >= 12.0)
        {
            i -= 12.0;
            ++f;
        }
        Distance* result = new Distance(f, i);
        return *result;
    }
};

int main()
{
    Distance d1, d2(11, 6.25), d3, d4;
    d1.getdist();

    d3 = d1 + d2;
    d4 = d3 + d2 + d1;

    d1.print();
    d2.print();
    d3.print();
    d4.print();
    return 0;
}