// BOJ-01977 / 완전제곱수
// devgeon, 2024.07.09, C++17
// https://www.acmicpc.net/problem/1977

#include <iostream>

using namespace std;

int main() {
    int m = 0, n = 0, min = 0, sum = 0;
    cin >> m >> n;

    for (int i = 1; i * i <= n; i++) {
        if (i * i < m) {
            continue;
        }
        if (min == 0) {
            min = i * i;
        }
        sum += i * i;
    }

    if (min == 0) {
        cout << -1 << endl;
    } else {
        cout << sum << '\n' << min << endl;
    }

    return 0;
}
