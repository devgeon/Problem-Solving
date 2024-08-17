// BOJ-30618 / donstructive
// devgeon, 2024.08.17, C++17
// https://www.acmicpc.net/problem/30618

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    for (int i = 1; i <= num; i += 2) {
        cout << i << ' ';
    }
    for (int i = (num | 1) - 1; i > 0; i -= 2) {
        cout << i << ' ';
    }

    return 0;
}
