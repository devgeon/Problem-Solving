// BOJ-23276 / Locust Locus
// devgeon, 2024.07.12, C++17
// https://www.acmicpc.net/problem/23276

#include <iostream>

using namespace std;

int greatest_common_divisor(int num1, int num2);

int least_common_multiple(int num1, int num2);

int main() {
    int num = 0, answer = 1'000'000'000;
    int year = 0, period1 = 0, period2 = 0;
    cin >> num;

    while (num--) {
        cin >> year >> period1 >> period2;
        answer = min(answer, year + least_common_multiple(period1, period2));
    }
    cout << answer << endl;

    return 0;
}

int greatest_common_divisor(int num1, int num2) {
    if (num1 < num2) {
        num1 ^= num2 ^= num1 ^= num2;
    }
    if (num2 == 0) {
        return num1;
    }
    return greatest_common_divisor(num2, num1 % num2);
}

int least_common_multiple(int num1, int num2) {
    return num1 * num2 / greatest_common_divisor(num1, num2);
}
