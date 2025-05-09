// BOJ-05556 / 타일
// devgeon, 2025.05.09, C++17
// https://www.acmicpc.net/problem/5556

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size = 0, count = 0;
    int row = 0, col = 0, answer = 0;
    cin >> size >> count;

    for (int i = 0; i < count; i++) {
        cin >> col >> row;
        if (row > (size >> 1))
            row = size - row + 1;
        if (col > (size >> 1))
            col = size - col + 1;

        answer = ((row < col ? row : col) - 1) % 3 + 1;
        cout << answer << '\n';
    }

    return 0;
}
