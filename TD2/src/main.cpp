#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << " f2 = " << f2 << std::endl;

    Fraction f3 { f1 + f2 };

    std::cout << "f1 + f2 = " << f3 << std::endl;

    Fraction f4 { f1 - f2 };
    std::cout << "f1 - f2 = " << f4 << std::endl;

    Fraction f5 { f1 * f2 };
    std::cout << "f1 * f2 = " << f5 << std::endl;

    Fraction f6 { f1 / f2 };
    std::cout << "f1 / f2 = " << f6 << std::endl;

    // std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    // std::cout << "f1 != f2: " << (f1 != f2) << std::endl;

    return 0;
}