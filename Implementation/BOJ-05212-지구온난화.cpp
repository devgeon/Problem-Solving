// BOJ-05212 / 지구 온난화
// devgeon, 2024.12.18, C++17
// https://www.acmicpc.net/problem/5212

#include <iostream>
#include <vector>

using namespace std;

inline int row_count(const vector<bool> &bitvec) {
    int count = 0;
    for (bool bit : bitvec)
        count += (int)bit;
    return count;
}

inline int col_count(const vector<vector<bool>> &bitmat, const int col) {
    int count = 0;
    for (const auto &bitvec : bitmat) {
        count += (int)bitvec[col];
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    int top = 0, bottom = 0, left = 0, right = 0;
    cin >> row >> col;

    vector<vector<bool>> map(row + 2, vector<bool>(col + 2, false));
    vector<vector<bool>> new_map(row, vector<bool>(col, false));
    for (int r = 1; r <= row; r++) {
        cin.get();
        for (int c = 1; c <= col; c++) {
            map[r][c] = (cin.get() == 'X');
        }
    }

    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            int count = (int)map[r - 1][c] + (int)map[r + 1][c] +
                        (int)map[r][c - 1] + (int)map[r][c + 1];
            new_map[r - 1][c - 1] = (map[r][c] && count > 1);
        }
    }

    for (top = 0; top < row; top++) {
        if (row_count(new_map[top]))
            break;
    }
    for (bottom = row - 1; bottom > -1; bottom--) {
        if (row_count(new_map[bottom]))
            break;
    }
    for (left = 0; left < col; left++) {
        if (col_count(new_map, left))
            break;
    }
    for (right = col - 1; right > -1; right--) {
        if (col_count(new_map, right))
            break;
    }

    for (int r = top; r <= bottom; r++) {
        for (int c = left; c <= right; c++) {
            cout << (new_map[r][c] ? 'X' : '.');
        }
        cout << '\n';
    }

    return 0;
}
