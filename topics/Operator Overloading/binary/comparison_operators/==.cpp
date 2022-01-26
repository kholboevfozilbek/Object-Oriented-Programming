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
            cout << num << " / " << denom ;
        }
        int getnum() {return num; }
        int getdenom() {return denom; }

        Fraction& operator- (const Fraction &o);
        bool operator< (const Fraction &o) const
        {
            int frac1 = num * o.denom;
            int frac2 = denom * o.num;

            return (frac1<frac2)? true: false;
        }

        bool operator> (const Fraction &o) const
        {
            int frac1 = num * o.denom;
            int frac2 = denom * o.num;

            return (frac1>frac2)? true: false;
        }
        bool operator>= (const Fraction &o) const
        {
            int frac1 = num * o.denom;
            int frac2 = denom * o.num;

            return (frac1>=frac2)? true: false;
        }

        bool operator== (const Fraction &o) const
        {
            int frac1 = num * o.denom;
            int frac2 = denom * o.num;

            return (frac1==frac2)? true: false;
        }
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

Fraction& Fraction::operator- (const Fraction &o)
{
    Fraction* result = new Fraction;

    result->denom = LCM(denom, o.denom);
    int top1 = result->denom / denom;
    int top2 = result->denom / o.denom;

    result->num = (top1*num) - (top2*o.num);
    return *result;
}

int main()
{
    Fraction a(7, 4), b(7, 4);
    Fraction c;

    /*c= a-b; 
    c.print(); cout << endl;
    if (b < a)
    {
        b.print(); cout << " < "; a.print();
    }

    if (a > b)
        cout << "a is bigger than b" << endl;*/
    
    if(a >= b)
    {
        cout << "a >= b " << endl;
    }

    if(a == b)
        cout << "a == b " << endl << endl;
    return 0;
}