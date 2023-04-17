#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <math.h>
#include <iostream>
#include <cmath>
#include <numeric>

using namespace ariel;
Fraction::Fraction(int num, int deno)
{
    this->numerator = num;
    this->denominator = deno;
}
Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 0;
}
int Fraction::getNum() const
{
    return numerator;
}

int Fraction::getDen() const
{
    return denominator;
}
// Fractions
Fraction Fraction::operator+(const Fraction &other)
{
    return Fraction((numerator * other.denominator) + (other.numerator * denominator), denominator * other.denominator);
}
Fraction Fraction::operator-(const Fraction &other)
{
    return Fraction((numerator * other.denominator) - (other.numerator * denominator), denominator * other.denominator);
}
Fraction Fraction::operator*(const Fraction &other)
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}
Fraction Fraction::operator/(const Fraction &other)
{
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}
// Fractions and floats
Fraction Fraction::operator+(const float n)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator-(const float n)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator*(const float n)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator/(const float n)
{
    return Fraction(1, 1);
}

// floats and Fractions
Fraction operator+(const float x, const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction
operator-(const float x, const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction operator*(const float x, const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction operator/(const float x, const Fraction &other)
{
    return Fraction(1, 1);
}

//  Increment Prefix
Fraction &Fraction::operator++() { return *this; }
Fraction &Fraction::operator--() { return *this; }

// Increment Postfix
Fraction Fraction::operator++(int x) { return *this; }
Fraction Fraction::operator--(int x) { return *this; }
// Comparators Fractions
bool Fraction::operator==(const Fraction &other) const { return false; }
bool Fraction::operator>(const Fraction &other) const { return false; }
bool Fraction::operator>=(const Fraction &other) const { return false; }
bool Fraction::operator<(const Fraction &other) const { return false; }
bool Fraction::operator<=(const Fraction &other) const { return false; }

// Comparators Float to Fraction.
bool operator==(const float x, const Fraction &other2) { return false; }
bool operator>(const float x, const Fraction &other2) { return false; }
bool operator>=(const float x, const Fraction &other2) { return false; }
bool operator<(const float x, const Fraction &other2) { return false; }
bool operator<=(const float x, const Fraction &other2) { return false; }

// Comparators Fraction to Float.
bool operator==(const Fraction &other1, const float x) { return false; }
bool operator>(const Fraction &other1, const float x) { return false; }
bool operator>=(const Fraction &other1, const float x) { return false; }
bool operator<(const Fraction &other1, const float x) { return false; }
bool operator<=(const Fraction &other1, const float x) { return false; }

// I/O
std::ostream &operator<<(std::ostream &output, const Fraction &c) { return output; }
std::istream &operator>>(std::istream &input, Fraction &c) { return input; }