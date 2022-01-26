#include <iostream>

using namespace std;

class Fraction
{
    private:
        int num;
        int denom;
    public:
        Fraction(): num{0}, denom{1}
        {   }
        Fraction(int _n, int _d=1): num{_n}, denom{_d}
        {   }
        void print()
        {
            cout << num << " / " << denom << endl;
        }
        int getnum() {return num; }
        int getdenom() {return denom; }

        Fraction& operator/ (const Fraction &o);
};

int GCD(int a, int b)
{
    int x= a;
    int y=b;

    while (x!=y)
    {
        /* code */
        if(x>y)
            x = x-y;
        else if(y > x)
            y = y -x;
    }
    return x;
    
}

int LCM(int a, int b)
{
    return (a*b) / GCD(a, b);
}

Fraction& Fraction::operator/ (const Fraction &o)
{
    Fraction* result = new Fraction;
    result->denom = denom * o.num;
    result->num = num * o.denom;

    if(GCD(result->num, result->denom) != 1)
    {
        int gcd = GCD(result->num, result->denom);
        result->num /= gcd;
        result->denom /= gcd;
    }
    return *result;
}

int main()
{
    Fraction a(7, 4), b(2, 3);
    Fraction c;

    c= a/b;
    c.print();
    return 0;
}