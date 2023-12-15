// BOJ-11179 / 2진수 뒤집기
// devgeon, 2023.12.05, C++17
// https://www.acmicpc.net/problem/11179

#include <iostream>

using namespace std;

int main() {
    int num = 0, result = 0;
    cin >> num;

    while (num) {
        result <<= 1;
        result |= num & 1;
        num >>= 1;
    }

    cout << result << endl;

    return 0;
}
