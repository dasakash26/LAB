#include <iostream>
using namespace std;

class Stack
{
    int *buffer, top;

public:
    Stack(int size)
    {
        buffer = new int[size];
        top = -1;
    }
};