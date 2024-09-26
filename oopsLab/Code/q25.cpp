#include <iostream>
using namespace std;

class Queue {
    int *data;
    int front, rear, size, capacity;

public:
    // Constructor to create a queue with a specified size
    Queue(int capacity) {
        this->capacity = capacity;
        data = new int[capacity];
        front = 0;
        rear = -1;
        size = 0; // Tracks the number of elements in the queue
    }

    // Add a specified element to the queue
    void add(int val) {
        if (size == capacity) {
            cout << "The queue is full! Can't add more elements.\n";
        } else {
            rear = (rear + 1) % capacity; // Circular increment
            data[rear] = val;
            size++;
        }
    }

    // Remove an element from the queue
    int remove() {
        if (size == 0) {
            cout << "The queue is empty!\n";
            return -1; // Return an invalid value
        } else {
            int removedValue = data[front];
            front = (front + 1) % capacity; // Circular increment
            size--;
            return removedValue;
        }
    }

    // Display all elements in the queue (front to rear order)
    void disp() {
        if (size == 0) {
            cout << "The queue is empty!\n";
        } else {
            cout << "Queue elements (front to rear): ";
            for (int i = 0; i < size; i++) {
                cout << data[(front + i) % capacity] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue q(5); // Create a queue with size 5

    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);

    cout << "Removed: " << q.remove() << endl; // Remove an element
    q.disp(); // Display the queue

    return 0;
}
