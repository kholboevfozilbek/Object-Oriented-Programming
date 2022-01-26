

#include <string>
#include <iostream>

using namespace std;

#pragma once

class Entry   ///abstract class
{
protected:
    string description;
    int seq_num;
    static int entry_counter;

public:
    Entry(string des=""): description{des}
    { ++entry_counter; //seq_num=entry_counter;   }
    
    virtual ~Entry(){ cout << "\nEntry has been removed"; };

    void setdes(string des) {description=des; }
    string getdes() {return description; }
    int getseq_num() {return seq_num; }

    virtual string getContents() = 0;
};
