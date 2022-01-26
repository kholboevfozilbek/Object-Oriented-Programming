

#include <iostream>
#include <string>
#include "vehicle_base.h"

using namespace std;


class Air : public Vehicle
{

private:

    int number_engines;
    int number_crews;
    float kg_support;

public:

    Air(float s=0.0f, float e=0.0f, std::string gas="petrol", int n_e=0, int n_c=0, float k_s=0.0f):
        Vehicle(s, e, gas), number_engines{n_e}, number_crews{n_c}, kg_support{k_s} { std::cout << "\nAir vehicle has been created " << endl; }
    void setAll(int n_e, int n_c, float k_s) {number_engines=n_e; number_crews=n_c; kg_support=k_s; }

    ~Air();

    int getnum_engine() {return number_engines; }
    int get_number_crews() {return number_crews; }
    float getkg_support() {return kg_support; }

    void fly();
    void take_off();
    void land() {cout << "Landing the Air:  " << endl;}

    friend ostream& operator<< (ostream& stream, const Air &o);
};

void Air::fly()
{
    cout << "\nFlying "<< endl;
}

Air::~Air()
{
    cout << "Air has been destroyed " << endl;
}

void Air::take_off()
{
    cout << "\nTaking off "<< endl;
}


ostream& operator<< (ostream& stream, const Air &o)
{
    stream << "Number of engines: " << o.number_engines << endl;
    stream << "Number of crews: " << o.number_crews << endl;
    stream << "Weight support: " << o.kg_support << endl;
    stream << Vehicle(o);
    return stream;
}