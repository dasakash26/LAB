#include <iostream>

using namespace std;

class Counter {
private:
    int count = 0;
    mutable int accessCount = 0;

public:
    // Constant member function
    int getCount() const {
        ++accessCount; // Modify mutable member
        return count;
    }

    // Non-constant member function
    void increment() {
        ++count;
    }

    void showState() const {
        cout << "Count: " << count << ", Access Count: " << accessCount << endl;
    }
};

int main() {
    Counter c;
    c.increment(); // Increase count
    c.increment();

    cout << "Count from getCount(): " << c.getCount() << endl;
    c.showState();

    const Counter& cConstRef = c;
    cout << "Count from const getCount(): " << cConstRef.getCount() << endl;
    cConstRef.showState();

    return 0;
}
