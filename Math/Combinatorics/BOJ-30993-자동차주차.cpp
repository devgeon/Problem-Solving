// BOJ-30993 / 자동차 주차
// devgeon, 2025.01.09, C++17
// https://www.acmicpc.net/problem/30993

#include <iostream>

using namespace std;

int main() {
    int car = 0;
    long long num = 0;

    cin >> num;
    for (int i = num - 1; i > 0; i--) {
        num *= i;
    }

    for (int i = 0; i < 3; i++) {
        cin >> car;
        for (int j = car; j > 0; j--) {
            num /= j;
        }
    }
    cout << num << endl;

    return 0;
}
