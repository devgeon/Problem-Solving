// BOJ-09734 / 순환 소수
// devgeon, 2024.10.16, C++17
// https://www.acmicpc.net/problem/9734

#include <iostream>

using namespace std;

int pow(int num, int exp);

int gcd(int a, int b);

void print_frac_from_inf_dec(string &inf_dec);

int main() {
    string inf_dec = "";

    while (true) {
        cin >> inf_dec;
        if (cin.eof()) {
            break;
        }
        cout << inf_dec << " = ";
        print_frac_from_inf_dec(inf_dec);
        cout << '\n';
    }

    return 0;
}

int pow(int num, int exp) {
    int result = 1;
    while (exp--) {
        result *= num;
    }
    return result;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void print_frac_from_inf_dec(string &inf_dec) {
    int idx = 0, acycle_part = 0, divisor = 0;
    int dec_len = 0, acycle_dec_len = 0;
    int numerator = 0, denominator = 0;

    inf_dec.pop_back();
    idx = inf_dec.rfind('.');
    dec_len = inf_dec.size() - idx - 2;
    inf_dec.erase(idx, 1);
    idx = inf_dec.rfind('(');
    acycle_part = stoi(inf_dec.substr(0, idx));
    acycle_dec_len = dec_len - (inf_dec.size() - idx - 1);
    inf_dec.erase(idx, 1);

    numerator = stoi(inf_dec) - acycle_part;
    denominator = pow(10, dec_len) - pow(10, acycle_dec_len);
    divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    cout << numerator << " / " << denominator;
}
