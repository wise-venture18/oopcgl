// Implement a class Complex which represents the Complex Number data type. 
// Implement the following 
// 1. Constructor (including a default constructor which creates the complex 
// number 0+0i). 
// 2. Overload operator+ to add two complex numbers. 
// 3. Overload operator* to multiply two complex numbers. 
// 4. Overload operators << and >> to print and read Complex Numbers.
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Overload operator+ to add two complex numbers
    Complex operator+(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    // Overload operator* to multiply two complex numbers
    Complex operator*(Complex c) {
        Complex result;
        result.real = real * c.real - imag * c.imag;
        result.imag = real * c.imag + imag * c.real;
        return result;
    }

    // Overload operator >> to read a complex number
    friend istream& operator>>(istream& input, Complex& c) {
        cout << "Enter real part: ";
        input >> c.real;
        cout << "Enter imaginary part: ";
        input >> c.imag;
        return input;
    }

    // Overload operator << to print a complex number
    friend ostream& operator<<(ostream& output, Complex& c) {
       
        if (c.imag >= 0)
            output << c.real << " + " << c.imag << "i";
        else
            output << c.real << " - " << -c.imag << "i";
        return output;
    }
};

int main() {
    Complex c1, c2, sum, product;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    // Add two complex numbers
    sum = c1 + c2;

    // Multiply two complex numbers
    product = c1 * c2;

    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
