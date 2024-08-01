// BOJ-25058 / Bottle Arrangements
// devgeon, 2024.08.01, C++17
// https://www.acmicpc.net/problem/25058

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0, wines = 0, critics = 0, red = 0, white = 0;
    cin >> cases;

    while (cases--) {
        red = 0, white = 0;
        cin >> wines >> critics;
        for (int i = 0, r = 0, w = 0; i < critics; i++) {
            cin >> r >> w;
            red = max(r, red), white = max(w, white);
        }
        if (red + white > wines) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        red = wines - white;
        while (red--) {
            cout << 'R';
        }
        while (white--) {
            cout << 'W';
        }
        cout << '\n';
    }

    return 0;
}
