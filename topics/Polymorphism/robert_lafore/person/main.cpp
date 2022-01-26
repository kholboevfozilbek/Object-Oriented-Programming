


#include <iostream>
#include <string>
#include "person.h"
#include "student.h"
#include "professor.h"

using namespace std;

int main(int argc, char* args[])
{
    Person* ptr[100];
    int n=0;
    char choice;

    do {

        cout << "Student or Professor s/p:  ";
        cin >>choice;

        if(choice == 's')
            ptr[n] = new Student;
        else    
            ptr[n] = new Professor;
        ptr[n++]->getData();
        cout << "Enter another one y/n:  ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    for (size_t i = 0; i < n; i++)
    {
        ptr[i]->putName();
        if(ptr[i]->isOutstanding())
            cout << "This person is outstanding\n";
    }
    
    return 0;
}