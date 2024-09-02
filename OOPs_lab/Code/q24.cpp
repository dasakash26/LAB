#include <iostream>
using namespace std;

class Stack {
  int *buffer, top, size;

public:
  Stack(int size) {
    this->size = size;
    buffer = new int[size];
    top = -1;
  }

  void push(int val) {
    if (top >= size) {
      cout << "The stack is full! can't push more elements.\n";
    } else {
      top++;
      buffer[top] = val;
    }
  }

  int pop() {
    if (top < 0) {
      cout << "The stack is empty!\n";
      return -1;
    } else {
      return buffer[top--];
    }
  }

  void disp() {
    cout << "stack :\n";
    for (int i = top; i >= 0; i--) {
      cout << "| " << buffer[i] << " |" << endl;
    }
  }

  ~Stack() { delete[] buffer; }
};

int main() {
  Stack s(10);

  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  s.pop();
  s.disp();
}
