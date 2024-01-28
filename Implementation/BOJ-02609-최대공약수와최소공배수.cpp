// BOJ-02609 / 최대공약수와 최소공배수
// devgeon, 2024.01.28, C++17
// https://www.acmicpc.net/problem/2609

#include <iostream>

using namespace std;

int main() {
    int num1 = 0, num2 = 0, remainder = 0;
    int greatest_common_factor = 0, lowest_common_multiple = 0;

    cin >> num1 >> num2;
    lowest_common_multiple = num1 * num2;

    while (true) {
        if (num1 < num2) {
            num1 ^= num2 ^= num1 ^= num2;
        }
        remainder = num1 % num2;
        if (remainder == 0) {
            break;
        }
        num1 = num2;
        num2 = remainder;
    }

    greatest_common_factor = num2;
    lowest_common_multiple /= num2;

    cout << greatest_common_factor << '\n';
    cout << lowest_common_multiple << endl;

    return 0;
}
