// BOJ-16931 / 겉넓이 구하기
// devgeon, 2024.02.09, C++17
// https://www.acmicpc.net/problem/16931

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0, area = 0, max_v = 0;
    cin >> row >> col;
    vector<vector<int>> base(row + 2, vector<int>(col + 2, 0));
    for (int r = 1; r < row + 1; r++) {
        for (int c = 1; c < col + 1; c++) {
            cin >> base[r][c];
            if (base[r][c] > 0) {
                area += 2;
            }
        }
    }
    for (int r = 1; r < row + 1; r++) {
        for (int c = 1; c < col + 2; c++) {
            area += abs(base[r][c] - base[r][c - 1]);
        }
    }
    for (int c = 1; c < col + 1; c++) {
        for (int r = 1; r < row + 2; r++) {
            area += abs(base[r][c] - base[r - 1][c]);
        }
    }
    cout << area << endl;
    return 0;
}
