
#include <iostream>

using namespace std;

class Pet 
{

public:
    char eat() const { return 'a'; }
    int speak() const { return 2;  }
    float sleep() const {return 3.0; }
    float sleep(int ) const  {return 4.0;  }

};

class Goldfish : private Pet
{

/* private:
    eat()
    speak();
    sleep()
    sleep()

*/

public:  //publicize privately inherited members

    using Pet::eat;
    
};


int main()
{
    Goldfish bob;

    cout << bob.eat();
    //bob.speak(); -> compiler error is inaccesible in thiis context

    return 0;
}