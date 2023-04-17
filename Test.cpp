#include "sources/Fraction.hpp"
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

TEST_CASE("Fraction Creation")
{
    Fraction f1(5, 6);
    CHECK_NOTHROW(Fraction(5, 6));
    SUBCASE("simplify")
    {
        CHECK(f1 == Fraction(10, 12));
    }
    CHECK_THROWS(Fraction(1, 0));
    CHECK_NOTHROW(Fraction(0, 1));
}
TEST_CASE("Fractions operators")
{
    Fraction f1(5, 6);
    Fraction f2(5, 6);
    CHECK((f1 + f2 == Fraction(10, 6)));
    CHECK((f1 - f2 == Fraction(0, 6)));
    CHECK((f1 * f2 == Fraction(25, 36)));
    CHECK((f1 / f2 == Fraction(1, 1)));
}
TEST_CASE("fractions and floats operators")
{
    Fraction f1(5, 6);
    CHECK((f1 + 3.14 == Fraction(298, 75)));
    CHECK((f1 - 3.14 == Fraction(-173, 75)));
    CHECK((f1 * 3.14 == Fraction(157, 60)));
    CHECK((f1 / 3.14 == Fraction(125, 471)));
}
TEST_CASE("floats and Fractions operators")
{
    Fraction f1(5, 6);
    CHECK((3.14 + f1 == Fraction(298, 75)));
    CHECK((3.14 - f1 == Fraction(173, 75)));
    CHECK((3.14 * f1 == Fraction(157, 60)));
    CHECK((3.14 / f1 == Fraction(471, 125)));
}
TEST_CASE("Comparisons")
{
    Fraction f1(5, 6);
    CHECK((f1 > Fraction(4, 6)));
    CHECK((f1 < Fraction(6, 6)));
    CHECK((f1 >= Fraction(5, 6)));
    CHECK((f1 <= Fraction(5, 6)));
}
TEST_CASE("++ and -- PRE")
{
    Fraction f1(5, 6);
    Fraction f2(12, 8);
    CHECK(((f1++) == Fraction(5, 6)));
    CHECK(((f2--) == Fraction(12, 8)));
}
TEST_CASE("++ and -- POST")
{
    Fraction f1(5, 6);
    Fraction f2(12, 8);
    CHECK(((++f1) == Fraction(11, 6)));
    CHECK(((--f2) == Fraction(1, 2)));
}
TEST_CASE("<< and >>")
{
    Fraction frac1(5, 6);
    std::stringstream str;
    str << frac1;
    CHECK((str.str() == "5/6"));

    Fraction frac2;
    std::stringstream str2("1/2");
    str2 >> frac2;
    CHECK((frac2 == Fraction(1, 2)));
}