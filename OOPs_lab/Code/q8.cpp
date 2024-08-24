#include <iostream>
#define ll long long
using namespace std;

void swap(ll &a, ll &b)
{
    ll temp = a;
    a = b;
    b = temp;
}

int main()
{
    ll a, b;
    cout << "Enter a & b: ";
    cin >> a >> b;

    cout << "before swap function call :" << "a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "after swap function call :" << "a = " << a << " b = " << b << endl;
}