#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) {
        if (den == 0) {
            cerr << "Error: The denominator can't be equal to 0." << endl;
            exit(1);
        }

        numerator = num;
        denominator = den;
        simplify();
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    void simplify() {
        int commonFactor = gcd(numerator, denominator);
        numerator /= commonFactor;
        denominator /= commonFactor;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Error: You can't divide by 0." << endl;
            exit(1);
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

int main() {
    int num1, den1, num2, den2;

    cout << "Enter the numerator and denominator for the first fraction: ";
    cin >> num1 >> den1;

    cout << "Enter the numerator and denominator for the second fraction: ";
    cin >> num2 >> den2;

    cout << endl;

    Fraction a(num1, den1);
    Fraction b(num2, den2);

    Fraction sum = a + b;
    Fraction diff = a - b;
    Fraction product = a * b;
    Fraction quotient = a / b;

    cout << "a = ";
    a.print();
    cout << endl;

    cout << "b = ";
    b.print();
    cout << endl;

    cout << "a + b = ";
    sum.print();
    cout << endl;

    cout << "a - b = ";
    diff.print();
    cout << endl;

    cout << "a * b = ";
    product.print();
    cout << endl;

    cout << "a / b = ";
    quotient.print();
    cout << endl;

    return 0;
}
