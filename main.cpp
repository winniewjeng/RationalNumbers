
#include "Rational.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    Rational r;
    Rational r1(1, 0);
    Rational r2(1, 2);
    char option = ' ';

    while (option != tolower('x')) {

        r.print_operations(r1, r2);

        cout << "[A] [B] e[X]it:  ";
        cin >> option;

        if (option == 'A') {
            cout << "A: ";
            cin >> r1;
        } else if (option == 'B') {
            cout << "B: ";
            cin >> r2;
        }

    }



    return 0;
}

