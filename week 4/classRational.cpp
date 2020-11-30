#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include<set>
using namespace std;

int Euclid(int a, int b) {
    while(a != 0 && b != 0) {
        if (a >= b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    else {
        return a;
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int numerator_input, int denominator_input) {
        if (denominator_input < 0) {
            numerator_input = -numerator_input;
            denominator_input = -denominator_input;
        }
        if(numerator_input == 0) {
            numerator = 0;
            denominator = 1;
        }
        if (numerator_input != 0) {
            int gcd = Euclid(abs(numerator_input), abs(denominator_input));
            numerator = numerator_input / gcd;
            denominator = denominator_input / gcd;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
    int substraction_numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator()*lhs.Denominator();
    int subtraction_denominator = lhs.Denominator() *rhs.Denominator();
    return {substraction_numerator, subtraction_denominator};
}
Rational operator+(const Rational& lhs,  const Rational& rhs) {
    int substraction_numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator()*lhs.Denominator();
    int subtraction_denominator = lhs.Denominator() *rhs.Denominator();
    return {substraction_numerator, subtraction_denominator};
}

Rational operator*( const Rational& lhs,  const Rational& rhs) {
    int mult_numerator = lhs.Numerator() * rhs.Numerator();
    int mult_denominator = lhs.Denominator() * rhs.Denominator();
    return {mult_numerator, mult_denominator};
}
Rational operator/(const Rational& lhs,  const Rational& rhs) {
    int div_numerator = lhs.Numerator() * rhs.Denominator();
    int div_denominator = lhs.Denominator() * rhs.Numerator();
    return {div_numerator, div_denominator};
}
ostream& operator<<(ostream& stream,  const Rational& fraction) {
    stream << fraction.Numerator() <<'/'<<fraction.Denominator();
    return stream;
}
istream& operator >>(istream& stream,  Rational& fraction) {
    int a, b;
    char ident;
    if (stream) {
        stream >> a;
        stream >> ident;
        stream >> b;
        if(stream && ident == '/') {
            fraction = Rational(a, b);
        }
    }
    return stream;
}
bool operator<(const Rational& lhs,  const Rational& rhs) {
    if (lhs.Numerator() * rhs.Denominator() - rhs.Numerator()*lhs.Denominator() < 0) {
        return true;
    }
    return false;
}

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
