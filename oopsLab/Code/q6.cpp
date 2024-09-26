#include <iostream>
using namespace std;

const double pi = 3.141592653589793238462643383279502884197;
int main()
{
    double r;

    cout << "Enter the radius of the circle : ";
    cin >> r;

    cout << "The area of the circle of radius "<<r<<" is :"<<pi*r*r<< endl;
}
