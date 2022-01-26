

#include <iostream>
#include <stdexcept>
#include "figure.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <vector>
#include <set>

using namespace std;

class FigureSet 
{
    
private:
    std::vector<Figure*> arr;

public:
    FigureSet() = default;
    void add_figure(Figure*);
    void remove_all() { arr.clear(); }
    float summary_Area();
    int summary_perimeter();
    friend ostream& operator<< (ostream& stream, FigureSet &o);
    Figure* operator[] (int index);
};

void print(Figure* f)
{
    cout << f->print() << endl;
}

Figure* FigureSet::operator[] (int index)
{
    if(index < 0 || index >= arr.size())
        throw runtime_error("Bad index access");
    return arr[index];
}

ostream& operator<< (ostream& stream, FigureSet &o)
{
    for(auto it = o.arr.begin(); it != o.arr.end(); ++it)
    {
        stream << (*it)->print() << endl;
    }
    return stream;
}

float FigureSet::summary_Area()
{
    float sum=0.0f;
    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        sum += (*it)->getArea();
    }
    return sum; 
}

int FigureSet::summary_perimeter()
{
    float sum=0.0f;
    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        sum += (*it)->getPerimeter();
    }
    return sum;
}

void FigureSet::add_figure(Figure* type_figure)
{
    arr.push_back(type_figure);
}


int main()
{
    FigureSet figure;

    char choice;
    int fig;
    do {
        cout << "Enter the 1->Rectangle  2->Triangle  3->Circle: "; cin >> fig;
        switch (fig)
        {
        case 1: {
            Rectangle *rect = new Rectangle;
            rect->getData();
            figure.add_figure(rect);
            break; }
        case 2: {
            Triangle* ptr_tri = new Triangle();
            while (true)
            {
                try  {
                    ptr_tri->getData();
                break;
                } catch(Sides_Error &e) {
                    cout << e.what();
                    cout << "\nPlease Enter 3 sides valid for triangle";
                }
            }
            figure.add_figure(ptr_tri);
            break; }
        case 3: {
            Circle* ptr_circle = new Circle();
            ptr_circle->getData();
            figure.add_figure(ptr_circle);
            break; }
        default:
            std::cout << "Please enter corresponding number!";
            break; 
        }

        cout << "Enter more? y/n: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << figure << endl;
    cout << "\n\nSummary Area of all figures in FigureSet:  " << figure.summary_Area() << endl;
    cout << "\nSummary perimeter of all figures in Set:  " << figure.summary_perimeter() << endl;

    print(figure[1]);
    return 0;
}