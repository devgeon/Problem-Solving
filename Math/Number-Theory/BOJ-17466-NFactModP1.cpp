// BOJ-17466 / N! mod P (1)
// devgeon, 2024.03.28, C++17
// https://www.acmicpc.net/problem/17466

#include <iostream>

using namespace std;

int main() {
    int num = 0, prime = 0;
    long long answer = 1LL;
    cin >> num >> prime;

    for (int i = num; i > 1; i--) {
        answer *= i;
        answer %= prime;
    }

    cout << answer << endl;
    return 0;
}
