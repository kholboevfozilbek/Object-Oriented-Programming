#include <iostream>

using namespace std;

class Money
{
    private:
    float money=0;

    public:

    Money(int val=0): money{val}
    {  }
    int getmoney() {return money; }

    bool operator! ()
    {
        if(money <= 0)
            return true;
        return false;
    }
};

int main()
{
    Money expenditures(5000);
    Money income(7000);
    Money profit(income.getmoney() - expenditures.getmoney());

    if(!profit)
        cout << "You did not make any profit! " << endl;
    else
        cout << "You made profit !!!!!!!!!!!!!" << endl;

    return 0;
}