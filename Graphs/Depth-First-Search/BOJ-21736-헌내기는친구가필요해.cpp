// BOJ-21736 / 헌내기는 친구가 필요해
// devgeon, 2024.11.30, C++17
// https://www.acmicpc.net/problem/21736

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<char>> &campus, int r, int c) {
    int result = 0;

    if (r < 0 || r >= campus.size() || c < 0 || c >= campus[0].size() ||
        campus[r][c] == 0 || campus[r][c] == 'X') {
        return 0;
    }
    if (campus[r][c] == 'P') {
        result++;
    }
    campus[r][c] = 0;

    result += solve(campus, r + 1, c);
    result += solve(campus, r - 1, c);
    result += solve(campus, r, c + 1);
    result += solve(campus, r, c - 1);

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    int start_row = 0, start_col = 0, answer = 0;
    cin >> row >> col;

    vector<vector<char>> campus(row, vector<char>(col));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> campus[r][c];
            if (campus[r][c] == 'I') {
                start_row = r, start_col = c;
            }
        }
    }

    answer = solve(campus, start_row, start_col);
    if (answer) {
        cout << answer << endl;
    } else {
        cout << "TT" << endl;
    }

    return 0;
}
