
#pragma once


#include <iostream>
#include <string>

using namespace std;

class Footballer
{

protected:

    string name;
    string surname;
    int number;
    string club;
    string position;
    float height;
    float weight;
    int age;

public:

    Footballer(): name{""}, surname{""}, number{0}, club{""}, position{""}, height{0.0f}, weight{0.0f}, age{0} {    }
    Footballer(string n, string s, int num, string cl, string pos, float heig, float w, int a);
    void setall(string n, string s, int num, string cl, string pos, float heig, float w, int a);
    void setname(string n) {name = n; }
    void setsurname(string s) {surname = s; }
    void setnumber(int num) {number = num; }
    void setclub(string c) {club = c; }
    void setposition(string ppos) {position = ppos; }
    void setheight_weight_age(float h, float w, int a) {height = h; weight = w; age = a; }

    string getname() {return name; }
    string getsurname() {return surname; }
    string getclub() {return club; }
    string getpos() {return position; }
    int getnumber() {return number; }
    int getage() {return age; }

    void run() {std::cout << "\nI am running"; };
    void pass() {std::cout << "\nPassing the ball\n"; };
    
    friend ostream& operator<< (ostream& stream, Footballer &o);
};

Footballer::Footballer(string n, string s, int num, string cl, string pos, float heig, float w, int a):
    name{n}, surname{s}, number{num}, club{cl}, position{pos}, height{heig}, weight{w}, age{a}
{   }

void Footballer::setall(string n, string s, int num, string cl, string pos, float heig, float w, int a)
{
    name = n;
    surname = s; number = num; club = cl; position = pos; height = heig; 
    weight = w; age = a;
}

ostream& operator<< (ostream& stream, Footballer &o)
{
    stream << "\n\n";
    stream << "Name: " << o.getname() << endl;
    stream << "Surname: " << o.getsurname() << endl;
    stream << "Number: " << o.getnumber() << endl;
    stream << "Club: " << o.getclub() << endl;
    stream << "Position: " << o.getpos() << endl;
    stream << "Age: " << o.getage() << endl;
    return stream;
}


