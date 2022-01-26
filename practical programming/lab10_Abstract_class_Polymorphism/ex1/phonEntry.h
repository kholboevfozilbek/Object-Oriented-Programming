

#include <string>
#include <iostream>
#include "Entry.h"

using namespace std;


class PhoneEntry : public Entry
{

protected:
    string phone_number;

public:

    PhoneEntry(string des="", string phone=""): Entry(des), phone_number{phone}
    {   }
    ~PhoneEntry();

    string getContents();
    

};

PhoneEntry::~PhoneEntry()
{
    cout << "-> Phone Entry" << endl;

}

string PhoneEntry::getContents()
{
    return description + to_string(seq_num) + phone_number;
}