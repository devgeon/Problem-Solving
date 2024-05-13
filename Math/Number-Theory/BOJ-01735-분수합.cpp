// BOJ-01735 / 분수 합
// devgeon, 2024.05.13, C++17
// https://www.acmicpc.net/problem/1735

#include <iostream>

using namespace std;

class Fraction {
  public:
    long long numerator = 0;
    long long denominator = 1;
    Fraction(long long numerator = 0, long long denominator = 1);
    const Fraction operator+(const Fraction &frac) const;
    void simplify();
};

istream &operator>>(istream &in, Fraction &frac);
ostream &operator<<(ostream &out, const Fraction &frac);

int main() {
    Fraction frac1, frac2, answer;
    cin >> frac1 >> frac2;
    answer = frac1 + frac2;
    cout << answer << endl;
    return 0;
}

Fraction::Fraction(long long numerator, long long denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->simplify();
}

const Fraction Fraction::operator+(const Fraction &frac) const {
    Fraction new_frac;
    new_frac.numerator = (this->numerator * frac.denominator +
                          frac.numerator * this->denominator);
    new_frac.denominator = this->denominator * frac.denominator;
    new_frac.simplify();
    return new_frac;
}

void Fraction::simplify() {
    long long a = 0, b = 0, r = 0;
    a = max(numerator, denominator);
    b = min(numerator, denominator);
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    numerator /= a;
    denominator /= a;
}

istream &operator>>(istream &in, Fraction &frac) {
    in >> frac.numerator >> frac.denominator;
    frac.simplify();
    return in;
}

ostream &operator<<(ostream &out, const Fraction &frac) {
    out << frac.numerator << ' ' << frac.denominator;
    return out;
}
