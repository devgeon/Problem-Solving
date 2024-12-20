// BOJ-25487 / 단순한 문제 (Large)
// devgeon, 2024.12.19, C++17
// https://www.acmicpc.net/problem/25487

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_cases = 0;
    int a = 0, b = 0, c = 0;
    cin >> total_cases;

    for (int i = 0; i < total_cases; i++) {
        cin >> a >> b >> c;
        cout << min(a, min(b, c)) << '\n';
    }

    return 0;
}
