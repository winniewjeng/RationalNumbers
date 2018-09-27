

#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Rational {
private:
    //variables
    //use _ in front of class variables 
    int _num;
    int _denom;
    int error() const; //checks for error cond and returns error code
    int _error; //error code

public:
    
    
    //constructors
    Rational();
    Rational(int num, int denom);
    Rational(int whole);

    //primitive ways of computing rational numbers with object functions
    Rational add(const Rational& other);
    Rational sub(const Rational& other);
    Rational div(const Rational& other);
    Rational mult(const Rational& other);

    void print_rational();
    void print_operations(Rational num1, Rational num2) const;
    void input();
    string description() const;
    void reset(); //resets number to 0/1 and clears error state

    //setter (mutator)
    void set(int num, int denom);
    void set_numerator(int n);
    void set_denominator(int d);

    //getter (accessor)
    int get_numerator() const;
    int get_denominator() const;

    //will return object whose error state is set 
    //   if one of the operands is in error. 
    friend Rational operator+(const Rational &num1, const Rational &num2);
    friend Rational operator-(const Rational &num1, const Rational &num2);
    friend Rational operator*(const Rational &num1, const Rational &num2);
    friend Rational operator/(const Rational &num1, const Rational &num2);
    //will print UNDEFINED if num is in error.
    friend ostream& operator<<(ostream &outs, const Rational &num);
    friend istream& operator>>(istream &ins,  Rational &num);
};

#endif /* RATIONAL_H */

