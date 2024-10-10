// BOJ-02553 / 마지막 팩토리얼 수
// devgeon, 2024.10.10, C++17
// https://www.acmicpc.net/problem/2553

#include <iostream>

using namespace std;

int main() {
    int n = 0;
    long long fact = 1L;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        fact = fact * i % 10'000'000;
        while (fact % 10L == 0L) {
            fact /= 10L;
        }
    }
    cout << fact % 10L << endl;

    return 0;
}
