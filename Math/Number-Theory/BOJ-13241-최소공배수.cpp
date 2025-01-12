// BOJ-13241 / 최소공배수
// devgeon, 2025.01.12, C++17
// https://www.acmicpc.net/problem/13241

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a = 0, b = 0;
    long long answer = 0;

    cin >> a >> b;
    answer = (long long)a * b / gcd(a, b);
    cout << answer << endl;

    return 0;
}
