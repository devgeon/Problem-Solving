// BOJ-14910 / 오르막
// devgeon, 2024.04.18, C++17
// https://www.acmicpc.net/problem/14910

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MIN = -1'000'000;
    int cur = 0, prev = MIN - 1;

    while (true) {
        cin >> cur;
        if (cin.eof()) {
            cout << "Good" << endl;
            break;
        }
        if (prev > cur) {
            cout << "Bad" << endl;
            break;
        }
        prev = cur;
    }

    return 0;
}
