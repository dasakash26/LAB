#include <iostream>
#include <cstring>
#define len 50
using namespace std;

void Swap(char a[len], char b[len])
{
    char temp[len];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);     
}

int main()
{
    char a[len], b[len];
    cout << "Enter first string :";
    cin.getline(a, len);
    cout << "Enter second string :";
    cin.getline(b, len);
    cout << a << " " << b << endl;
    Swap(a, b);
    cout << a << " " << b << endl;
}