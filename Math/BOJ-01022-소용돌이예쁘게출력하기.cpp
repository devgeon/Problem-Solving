// BOJ-01022 / 소용돌이 예쁘게 출력하기
// devgeon, 2023.11.27, C++17
// https://www.acmicpc.net/problem/1022

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int top = 0, left = 0, bottom = 0, right = 0;
    int max = 0, max_len = 0, len = 0;
    cin >> top >> left >> bottom >> right;
    vector<vector<int>> table(bottom - top + 1,
                              vector<int>(right - left + 1, 1));

    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            if (y <= x && x < -y) { // North
                table[y - top][x - left] = 4 * y * y - x + y + 1;
            } else if (-y < x && x <= y + 1) { // South
                table[y - top][x - left] = 4 * y * y + x + 3 * y + 1;
            } else if (-x <= y && y < x) { // East
                table[y - top][x - left] = 4 * x * x - 3 * x - y + 1;
            } else if (x < y && y <= -x) { // West
                table[y - top][x - left] = 4 * x * x - x + y + 1;
            }

            if (table[y - top][x - left] > max) {
                max = table[y - top][x - left];
            }
        }
    }

    max_len = static_cast<int>(log10(max));
    for (int y = 0; y <= bottom - top; y++) {
        if (y != 0) {
            cout << "\n";
        }
        for (int x = 0; x <= right - left; x++) {
            if (x != 0) {
                cout << " ";
            }
            len = static_cast<int>(log10(table[y][x]));
            for (int i = 0; i < max_len - len; i++) {
                cout << " ";
            }
            cout << table[y][x];
        }
    }

    return 0;
}
