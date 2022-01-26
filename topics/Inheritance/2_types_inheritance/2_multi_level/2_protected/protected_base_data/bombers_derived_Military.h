

#include <iostream>
#include "military_derived_derived.h"

using namespace std;

class Bombers : protected Military
{

protected:

    string category_bombs;
    bool isOnAttack;
    int total_number_bombs;
    int curr_number_bombs;

public:

    Bombers(float s=0.0f, float e=0.0f, std::string gas="petrol", int n_e=0, int n_c=0, float k_s=0.0f, string category="", int total_bombs=0): Military(s, e, gas, n_e, n_c, k_s), category_bombs{category}, isOnAttack{false}, total_number_bombs{total_bombs} { cout << "\nBomber military air vehicle has been created " << endl;}

    ~Bombers();

    friend ostream& operator<< (ostream& stream, const Bombers &o);
    float getspeed_derived() {return getspeed(); }
    float getengine_derived() {return getengine(); }
    string getgas_derived() {return getgas_type(); }

    void move_derived() {move(); }
    int getnum_engine_derived() {getnum_engine(); }
    int number_crews_derived() {return get_number_crews(); }
    void fly_derived() {fly(); }
    void takeoff_derived() {take_off(); }
    void land_derived() {land(); }

};

Bombers::~Bombers()
{
    cout << "\nBombers has been destroyed " << endl;
}

ostream& operator<< (ostream& stream, const Bombers &o)
{
    stream << "\n************************\n";
    stream << "Bomber Fighter Jet\n";
    stream << "Category of Bomber:  " << o.category_bombs << endl;
    stream << "Total bombs:  " << o.total_number_bombs << endl;
    stream << "Current number of bombs: " << o.curr_number_bombs << endl;
    cout << Military(o);
    return stream;
}