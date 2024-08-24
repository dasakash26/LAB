#include <iostream>
using namespace std;

class Rectangle
{
    int length, breadth;

public:
    Rectangle(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    int area(){
        return length*breadth;
    }
};

int main()
{
    Rectangle r1(2,4);
    Rectangle r2(6,4);
    Rectangle r3(2,8);
    Rectangle r4(7,4);

    cout<<r1.area()<<endl;
    cout<<r2.area()<<endl;
    cout<<r3.area()<<endl;
    cout<<r4.area()<<endl;
}