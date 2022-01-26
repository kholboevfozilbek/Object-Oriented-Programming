

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


class SportData {

protected:
    string m_description;
    string m_person_name;
    static int count_sportdata;
public:
    SportData(string des="", string name_person=""): m_description{des}, m_person_name{name_person}
    {  ++count_sportdata;  }

    virtual ~SportData() {cout << "SporData has been destroyed" << endl; --count_sportdata;  }

    static int get_Count_sportdata() {return count_sportdata; }

    virtual string getBestResult() =0;

    void setALL(string des, string person);
    string get_description() {return m_description; }
    string get_person() {return m_person_name; }

};

int SportData::count_sportdata=0;

void SportData::setALL(string des, string person)
{
    m_description = des;
    m_person_name = person;
}

void print_SportData(SportData* o)
{
    cout << o->get_description() << ": " << o->get_person() << " result: " << o->getBestResult() << endl;
}

class TimeResult : public SportData {

private:
    string m_result;
    int m_hh;
    int m_mm;
    float m_ss;

public:
    TimeResult(string des="", string name_person="", string time_result="00:00:00.00"): SportData(des, name_person), m_result{time_result}
    {
        std::stringstream h; string hh;
        h << time_result[0] << time_result[1];
        h >> hh;
        m_hh = std::stoi(hh);

        std::stringstream m; string mm;
        m << time_result[3] << time_result[4];
        m >> mm;
        m_mm = std::stoi(mm);

        std::stringstream s; string ss;
        s << time_result[6] << time_result[7] << time_result[8] << time_result[9] << time_result[10];
        s >> ss;
        m_ss = std::stof(ss);
    }

    virtual ~TimeResult() {cout << "TimeResult has been destroyed " << endl; }

    string getBestResult() override { return m_result; }

    void set_result(string r) {m_result = r; }
    string get_result() {return m_result; }
    int get_hh() {return m_hh; }
    int get_mm() {return m_mm; }
    float get_ss() {return m_ss; }

    //bool operator> (TimeResult *o);
    friend ostream& operator<< (ostream& stream, TimeResult &o);
};

ostream& operator<< (ostream& stream, TimeResult &o)
{
    stream << o.get_description() << ": " << o.get_person() << " result: " << o.getBestResult() << endl;
    return stream;
}

void print(TimeResult* o)
{
    cout << o->get_description() << ": " << o->get_person() << " result: " << o->getBestResult() << endl;
}

int main()
{
    TimeResult* time = new TimeResult("swimming", "Bill Wood", "00:14:59.34");

    SportData* base_time = time;
    print_SportData(base_time);

    TimeResult* time_back = dynamic_cast<TimeResult*>(base_time);


    return 0;
}


