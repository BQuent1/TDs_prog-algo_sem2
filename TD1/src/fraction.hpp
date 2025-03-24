#pragma once
#include <iostream>

struct Fraction {
    int numerator { 0 };
    int denominator { 1 };

    
    friend std::ostream& operator<<(std::ostream& os, Fraction const& f);
    friend bool operator==(Fraction const& f1, Fraction const& f2);
    friend bool operator!=(Fraction const& f1, Fraction const& f2);
    friend bool operator<(Fraction const& f1, Fraction const& f2);
    friend bool operator>(Fraction const& f1, Fraction const& f2);
    friend bool operator<=(Fraction const& f1, Fraction const& f2);
    friend bool operator>=(Fraction const& f1, Fraction const& f2);
};

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);


/*
Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);
*/