

#include <iostream>

using namespace std;

int main()
{
    int numerator, denominator, result; 
    cout << "Enter numerator and denominator " << endl;

    cin >> numerator >> denominator;

    while (true)
    {
        try {
            if(denominator == 0)
                throw denominator;
            result = numerator/denominator;
            break;

        } catch(int exception_zero) {

            cout << "\nDivision by zero NOT allowed " << endl;
            cout << "\nEnter the values again:  \n";
            cout << "Enter numerator: "; cin >> numerator;
            cout << "Enter denominator: "; cin >> denominator; 
        }
    }
    
    

    cout << "\nDivision is:  " << result << endl;


    puts("\n\n"); 
    return 0;
}