// BOJ-02417 / 정수 제곱근
// devgeon, 2024.04.07, C++17
// https://www.acmicpc.net/problem/2417

#include <iostream>

using namespace std;

long long solve(long long num);

int main() {
    long long num = 0;

    cin >> num;
    cout << solve(num) << endl;

    return 0;
}

long long solve(long long num) {
    long long min = 0, max = 3'037'000'500, mid = 0;

    while (min < max) {
        mid = (min + max) / 2;
        if (mid * mid < num) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }

    return max;
}
