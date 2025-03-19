#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    os << f.numerator << '/' << f.denominator;
    return os;
}


Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}


bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction f1s = simplify(f1);
    Fraction f2s = simplify(f2);
    return f1s.numerator == f2s.numerator && f1s.denominator == f2s.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator > f2.numerator * f1.denominator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator <= f2.numerator * f1.denominator;
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator >= f2.numerator * f1.denominator;
}

/*
Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}


Fraction sub(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

*/