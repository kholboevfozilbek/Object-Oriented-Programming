#include <iostream>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;

class String
{
    private:
    char str[80];

    public:

    String()
    {
        strcpy(str, "");
    }
    String(char s[])
    {
        strcpy(str, s);
    }
    void display()
    {
        cout << str << endl;
    }
    String operator+ (const String&o ) const
    {
        
        String temp;
        if(strlen(str) + strlen(o.str) < 80)
        {
            strcpy(temp.str, str);
            strcat(temp.str, o.str);
        }
        else
            throw runtime_error("string overflow");
        return temp;
    }
};

int main()
{
    String s1{"Ona"};
    String s2(" men sizni yaxshi ko'raman");
    String s3 = s1 + s2;
    s3.display();
    return 0;
}