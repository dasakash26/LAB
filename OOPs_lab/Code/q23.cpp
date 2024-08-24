#include <iostream>
#include <cmath>  

using namespace std;

class Complex {
private:
    float real;
    float imaginary;

public:
    // Constructor to initialize complex number to 0 + 0i
    Complex() : real(0), imaginary(0) {}

    // Function to set the real part
    void setReal(float r) {
        real = r;
    }

    // Function to set the imaginary part
    void setImg(float i) {
        imaginary = i;
    }

    // Function to get the real part
    float getReal() const {
        return real;
    }

    // Function to get the imaginary part
    float getImg() const {
        return imaginary;
    }

    // Function to display the complex number
    void disp() const {
        cout << real << (imaginary >= 0 ? " + " : " - ") << fabs(imaginary) << "i" << endl;
    }

    // Function to sum two complex numbers and return a new Complex object
    Complex sum(const Complex& other) const {
        Complex result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        return result;
    }
};

int main() {
    // Create three Complex objects
    Complex c1, c2, c3;

    // Set values for the first complex number
    c1.setReal(3.5);
    c1.setImg(2.5);

    // Set values for the second complex number
    c2.setReal(1.5);
    c2.setImg(-1.5);

    // Calculate the sum of c1 and c2 and assign it to c3
    c3 = c1.sum(c2);

    // Display all complex numbers
    cout << "Complex Number 1: ";
    c1.disp();
    
    cout << "Complex Number 2: ";
    c2.disp();
    
    cout << "Sum of Complex Numbers: ";
    c3.disp();

    return 0;
}
