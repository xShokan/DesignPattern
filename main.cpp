#include <iostream>
#include "Prototype/Prototype.h"

class Fraction{
public:
    Fraction(int num, int den=1) : m_numerator(num), m_denominator(den){}

    Fraction operator+(const Fraction& f) const{
        return {m_numerator + f.m_numerator, m_denominator + f.m_denominator};
    }

    double Value() const{
        return (double)m_numerator / m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;
};

int main() {

    Fraction f(1, 2);

    Fraction f1 = f + 4;

    cout << f1.Value() << endl;

    return 0;
}
