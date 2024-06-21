// BOJ-25312 / 200% Mixed Juice!
// devgeon, 2024.06.21, C++17
// https://www.acmicpc.net/problem/25312

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Fraction {
  private:
    long long numerator = 0;
    long long denominator = 1;

    long long _gcd(long long a, long long b) {
        int r = 0;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

  public:
    Fraction(long long numerator = 0, long long denominator = 1) {
        this->numerator = numerator;
        this->denominator = denominator;
        this->simplify();
    }

    void simplify() {
        long long div = _gcd(numerator, denominator);
        this->numerator /= div;
        this->denominator /= div;
    }

    friend ostream &operator<<(ostream &out, const Fraction &frac) {
        out << frac.numerator << '/' << frac.denominator;
        return out;
    }
};

class Drink {
  public:
    int volume = 0;
    int sugar = 0;

    friend istream &operator>>(istream &in, Drink &drink) {
        in >> drink.volume >> drink.sugar;
        return in;
    }
};

bool compare_drinks(const Drink &a, const Drink &b) {
    return ((double)a.sugar / a.volume > (double)b.sugar / b.volume);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    long long target = 0;
    Fraction answer;
    cin >> num >> target;

    vector<Drink> drinks(num);
    for (Drink &drink : drinks) {
        cin >> drink;
    }
    sort(drinks.begin(), drinks.end(), compare_drinks);

    for (long long i = 0, sugar = 0, volume = 0; i < num; i++) {
        if (volume + drinks[i].volume < target) {
            sugar += drinks[i].sugar;
            volume += drinks[i].volume;
            continue;
        }
        sugar *= drinks[i].volume;
        sugar += drinks[i].sugar * (target - volume);
        answer = Fraction(sugar, drinks[i].volume);
        break;
    }
    cout << answer << endl;

    return 0;
}
