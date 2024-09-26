#include <iostream>
using namespace std;

inline void sum(int a, int b, int c)
{
    cout << a + b + c << endl;
}

int main()
{
    int a, b, c;
    cout<<"Enter three numbers :";
    cin >> a >> b >> c;
    sum(a,b,c);
}