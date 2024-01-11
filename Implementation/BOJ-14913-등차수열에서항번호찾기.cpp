// BOJ-14913 / 등차수열에서 항 번호 찾기
// devgeon, 2024.01.11, C++17
// https://www.acmicpc.net/problem/14913

#include <iostream>

using namespace std;

int main() {
    int a = 0, d = 0, k = 0, n = 0;
    cin >> a >> d >> k;
    if (!((k - a) % d)) {
        n = 1 + (k - a) / d;
    }
    if (n) {
        cout << n << endl;
    } else {
        cout << 'X' << endl;
    }
    return 0;
}
