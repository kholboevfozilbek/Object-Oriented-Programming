#include <iostream>

using namespace std;

class Height
{
    private:
    int length_meters=0;

    public:

    Height(int val=0): length_meters{val}
    { }
    int getheight() {return length_meters; }

    void operator- ()
    {
        length_meters = -length_meters;
    }
};

int main()
{
    Height Everest(8448);
    Height Mariana=1500;

    -Mariana;

    cout << "Everest: " << Everest.getheight() << endl;
    cout << "Mariana: " << Mariana.getheight() << endl;


    return 0;
}