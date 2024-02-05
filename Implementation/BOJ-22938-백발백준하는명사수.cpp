// BOJ-22938 / 백발백준하는 명사수
// devgeon, 2024.02.05, C++17
// https://www.acmicpc.net/problem/22938

#include <iostream>

using namespace std;

int main() {
    long long x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 + r2) * (r1 + r2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
