#ifndef DS_RATIO_H
#define DS_RATIO_H

#include <iostream>
#include <algorithm>
// using namespace ... - DON'T DO THIS

// Here is stuff that is in header files
// Declarations only
namespace ds_course
{
    class Ratio
    {
    private:
        int num;
        int den;
        int gcd(int a, int b);

    public:
        Ratio(int nn = 0, int dd = 1);
        Ratio operator+(const Ratio& rhs);
        bool operator==(const Ratio& rhs);
        Ratio operator-(const Ratio& rhs);
        Ratio operator*(const Ratio& rhs);
        Ratio operator=(const Ratio& rhs);

        friend std::ostream& operator<<(std::ostream& oStream, const Ratio rat)
        {
            if (rat.num == 0) {
                oStream <<  rat.num ;
            return oStream;
            }
            oStream <<  rat.num << "/" << rat.den;
            return oStream;
        }

        friend std::istream& operator>>(std::istream& input, ds_course::Ratio& rat)
        {
            input >> rat.num;
            input.ignore(256, '/'); // ignore slash
            input >> rat.den;
            return input;
        }
    };

}

ds_course::Ratio::Ratio(int nn, int dd) : num(nn), den(dd)
{
    int g = std::__gcd(nn, dd);

    num = num / g;
    den = den / g;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

ds_course::Ratio ds_course::Ratio::operator+(const Ratio& rhs)
{
    int upside = num * rhs.den + den * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}
ds_course::Ratio ds_course::Ratio::operator-(const Ratio& rhs)
{
    int upside = num * rhs.den - den * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}
ds_course::Ratio ds_course::Ratio::operator*(const Ratio& rhs)
{
    int upside = num * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}

bool ds_course::Ratio::operator==(const ds_course::Ratio& r) {
    return (num * r.den == den * r.num);
}

ds_course::Ratio ds_course::Ratio::operator=(const ds_course::Ratio& r) {
    num = r.num;
    den = r.den;
    int upside = r.num;
    int downside = r.den;
    ds_course::Ratio finalRatio(upside, downside);
    return finalRatio;
}

#endif