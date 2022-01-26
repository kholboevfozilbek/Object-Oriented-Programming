
#pragma once

#include <string>
#include <iostream>
using namespace std;

class Vehicle
{

protected:

    float speed;
    float engine;
    std::string gas_type;

public:
    Vehicle(float s=0.0f, float e=0.0f, std::string gas="petrol"): speed{s}, engine{e}, gas_type{gas}
    {  cout << "\nVehicle has been created " << endl; }
    ~Vehicle();

    void setspeed(float s) {speed = s; }
    void setengine(float en) {engine = en; }
    void setgastype(string gas) {gas_type = gas; }
    void setall(float s=0.0f, float e=0.0f, std::string gas="petrol") {speed=s; engine=e; gas_type=gas; }

    float getspeed() const {return speed; }
    float getengine() const{return engine; }
    string getgas_type() const{return gas_type; }

    void move();
    void stop();

    friend ostream& operator<< (ostream& stream, const Vehicle &o);
};

Vehicle::~Vehicle()
{
    cout << "Vehicle has been destroyed " << endl;
}

void Vehicle::move()
{
    cout << "\nMoving ";
}
void Vehicle::stop()
{
    cout << "\nStopping ";
}

ostream& operator<< (ostream& stream, const Vehicle &o)
{
    stream << "Speed: " << o.getspeed() << endl;
    stream << "Engine: " << o.getengine() << endl;
    stream << "Fuel: " << o.getgas_type() << endl;
    return stream; 
}