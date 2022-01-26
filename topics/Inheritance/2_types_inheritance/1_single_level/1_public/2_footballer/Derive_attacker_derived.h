
#include <iostream>
#include <string>
#include "Footballer_base.h"
using namespace std;

class Attacker : public Footballer
{
private: //since this is single level inheritance private and protected have sma eeffect because you do not have inherting classes
    float speed;
    float dribbling;
    float shoot;


public:
    Attacker(string n="", string s="", int num=0, string c="", string pos="attacker", float h=0.0f, float w=0.0f, int a=0): Footballer(n, s, num, c, pos, h, w, a)
    {    }

    void setAll(float s, float d, float sh) {speed = s; dribbling = d; shoot = sh; }
    float getspeed() {return speed; }
    float getdribbleing() {return dribbling; }
    float getshoot() {return shoot; }

    void speedd();
    void dribble();
    void shoott();
    //right here I did not have any operator<< for attacker(derived) class but when I tried to output it came when it did not find corresponding operator (<<) in derived class
    // but compiler look for operator from base class and used it

    string getname_from_derived() {return name; }

};

void Attacker::speedd()
{
    Footballer::run(); cout << " at " << getspeed() << " speed!";
}

void Attacker::dribble()
{
    cout << " I am dribbling  at " << getdribbleing() << "  level!";
}

void Attacker::shoott()
{
    cout << " I am shooting at " <<  getshoot() << " level!";
}