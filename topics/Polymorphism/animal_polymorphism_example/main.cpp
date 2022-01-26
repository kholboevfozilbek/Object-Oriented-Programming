
#include <iostream>
#include <cstdlib>
using namespace std;


class Animal {

public:
    virtual void sound() {
        cout << "Animal is making sound " << endl;
    }

    void print() {
        cout << "Animal is printing " << endl;
    }

};

class Dog : public Animal {

public:
    void sound() {
        cout << "WOOOF" << endl;
    }

    void print() {
        cout << "Dog is printing " << endl;
    }
};

class Cat : public Animal {

public:
    void sound() {
        cout << "MEAOW" << endl;
    }

    void print() {
        cout << "Cat is printing " << endl;
    }
};

class Donkey : public Animal {

public:
    void sound() {
        cout << "ihhha-ihhaaa" << endl;
    }
};

void current_animal_sound(Animal& base_ref)
{
    base_ref.sound();
}

int main()
{
    puts("\n\n");

    Animal base_animal;
    base_animal.sound();

    Dog derived_dog;
    derived_dog.sound();

    Animal* base_ptr = &base_animal; //pointer
    Animal& base_ref = base_animal;  //reference
    base_ptr->sound();
    base_ref.sound();

    Dog* derived_ptr = &derived_dog; //pointer
    Dog& derived_ref = derived_dog;  //reference
    derived_ptr->sound();
    derived_ref.sound();

    Cat derived_cat;

    Donkey derived_donkey;


    system("CLS");

    current_animal_sound(derived_donkey);


    puts("\n\n");
    return 0;
}