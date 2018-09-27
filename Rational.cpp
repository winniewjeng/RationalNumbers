

#include "Rational.h"

//using namespace std;

//constructor

Rational::Rational() {
}

Rational::Rational(int num, int denom) {
    _num = num;
    _denom = denom; //_denom = denom;
    _error = 0;
}

Rational::Rational(int whole) {
    _num = whole;
    _denom = 1;
    _error = 0;
}

void Rational::print_rational() {
    Rational local;
    if (_denom == 0) {
        cout << local.description();
    } else {
        cout << _num << "/" << _denom;
    }
}

void Rational::print_operations(Rational num1, Rational num2) const {
    num1.print_rational();
    cout << " + ";
    num2.print_rational();
    cout << " = ";
    cout << num1 + num2;
    cout << endl;

    num1.print_rational();
    cout << " - ";
    num2.print_rational();
    cout << " = ";
    cout << num1 - num2;
    cout << endl;

    num1.print_rational();
    cout << " * ";
    num2.print_rational();
    cout << " = ";
    cout << num1 * num2;
    cout << endl;
    
    num1.print_rational();
    cout << " / ";
    num2.print_rational();
    cout << " = ";
    cout << num1 / num2;
    cout << endl;
    cout << endl << "============================================" << endl;
}

int Rational::error() const {
    //if denominator is zero, return 1
    if (_denom == 0) {
        return 1;
    }
    return 0; //denom is NOT 0, returns 0
}

//NOT YET IMPLEMENTED

string Rational::description() const {
    return "UNDEFINED";
}

//resets number to 0/1 and clears error state

void Rational::reset() {
    _num = 0;
    _denom = 1;
    _error = 0;
}

void Rational::set(int num, int denom) {
    _num = num;
    _denom = denom;
}

void Rational::set_numerator(int n) {
    _num = n;
}

void Rational::set_denominator(int d) {
    _denom = d;
}

int Rational::get_numerator() const {
    return _num;
}

int Rational::get_denominator() const {
    return _denom;
}

Rational operator+(const Rational &num1, const Rational &num2) {

    int num;
    int denom;

    denom = num1._denom * num2._denom; //take my denominator and other's denominator and multiply them
    num = num1._num * num2._denom + num2._num * num1._denom;

    return Rational(num, denom);



}

Rational operator-(const Rational &num1, const Rational &num2) {

    int num;
    int denom;

    denom = num1._denom * num2._denom; //take my denominator and other's denominator and multiply them
    num = num1._num * num2._denom - num2._num * num1._denom;

    return Rational(num, denom);
}

//Algorithm needs to be changed so if denominator multiply to zero, return invalid

Rational operator/(const Rational &num1, const Rational &num2) {

    int num = num1._num * num2._denom;
    int denom = num1._denom * num2._num;

    return Rational(num, denom);
}

Rational operator*(const Rational &num1, const Rational &num2) {

    int num = num1._num * num2._num;
    int denom = num1._denom * num2._denom;

    return Rational(num, denom);
}

//insertion operator

ostream& operator<<(ostream &outs, const Rational &num) {

    if (num.error() == 0) {
        outs << " " << num._num << "/" << num._denom << endl;
        return outs;
    } else {
        outs << num.description();
        return outs;
    }

}

//extraction operator

istream& operator>>(istream &ins, Rational &num) {
    char slash = ' ';
    ins >> num._num;
    ins >> slash;
    ins >> num._denom;

    num._error = num.error();

    return ins;
}




