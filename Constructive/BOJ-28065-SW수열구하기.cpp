// BOJ-28065 / SW 수열 구하기
// devgeon, 2024.06.26, C++17
// https://www.acmicpc.net/problem/28065

#include <iostream>

using namespace std;

int main() {
    int num = 0, high = 0, low = 1;
    cin >> num;

    high = num;
    while (high >= low) {
        cout << high << ' ';
        if (high > low) {
            cout << low << ' ';
        }
        high--, low++;
    }

    return 0;
}
