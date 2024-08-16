// BOJ-04689 / Basically Speaking
// devgeon, 2024.08.16, C++17
// https://www.acmicpc.net/problem/4689

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const string ERROR_MSG = "ERROR";

int to_decimal(string num, int notation);
string from_decimal(int num, int notation);
string convert(string num, int in, int out);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int in = 0, out = 0;
    string num = "", result = "";

    while (true) {
        cin >> num >> in >> out;
        if (cin.eof()) {
            break;
        }
        result = convert(num, in, out);
        cout << setw(7) << (result.size() > 7 ? ERROR_MSG : result) << '\n';
    }

    return 0;
}

int to_decimal(string num, int notation) {
    int result = 0;
    for (int i = 0, size = num.size(); i < size; i++) {
        num[i] -= (num[i] < 'A' ? '0' : 'A' - 10);
        if (num[i] > notation) {
            result = -1;
            break;
        }
        result += num[i] * pow(notation, size - i - 1);
    }
    return result;
}

string from_decimal(int num, int notation) {
    char temp = 0;
    string result = "";
    while (num > 0) {
        temp = num % notation;
        temp += (temp < 10 ? '0' : 'A' - 10);
        result.push_back(temp);
        num /= notation;
    }
    reverse(result.begin(), result.end());
    return result;
}

string convert(string num, int in, int out) {
    int dec = 0;
    dec = to_decimal(num, in);
    if (dec < 0) {
        return ERROR_MSG;
    }
    return from_decimal(dec, out);
}
