// BOJ-04095 / 최대 정사각형
// devgeon, 2024.01.27, C++17
// https://www.acmicpc.net/problem/4095

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int row = 0, col = 0, input = 0, max_size = 0;
    cin >> row >> col;
    if (row == 0) {
        return -1;
    }
    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> input;
            if (input == 0) {
                continue;
            }
            matrix[r][c] = 1;
            if (r > 0 && c > 0) {
                matrix[r][c] += min(
                    {matrix[r - 1][c - 1], matrix[r - 1][c], matrix[r][c - 1]});
            }
            max_size = max(max_size, matrix[r][c]);
        }
    }
    return max_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_size = 0;

    while (true) {
        max_size = solve();
        if (max_size < 0) {
            break;
        }
        cout << max_size << "\n";
    }

    return 0;
}
