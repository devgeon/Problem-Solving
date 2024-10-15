// BOJ-09663 / N-Queen
// devgeon, 2024.10.15, C++17
// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>

using namespace std;

bool check_threat(vector<vector<bool>> &board, int row, int col);

int solve(vector<vector<bool>> &board, int num, int row = 0);

int main() {
    int size = 0;
    cin >> size;

    vector<vector<bool>> board(size, vector<bool>(size, false));
    cout << solve(board, size) << endl;

    return 0;
}

bool check_threat(vector<vector<bool>> &board, int row, int col) {
    int size = board.size();
    int forward_diff = row - col, reverse_diff = row - (size - col - 1);
    for (int i = 0, r1 = 0, r2 = 0; i < size; i++) {
        r1 = i + forward_diff, r2 = size - i - 1 + reverse_diff;
        if (board[row][i] || board[i][col] ||
            (r1 >= 0 && r1 < size && board[r1][i]) ||
            (r2 >= 0 && r2 < size && board[r2][i])) {
            return true;
        }
    }
    return false;
}

int solve(vector<vector<bool>> &board, int num, int row) {
    int size = board.size(), count = 0;
    if (row == size && num == 0) {
        return 1;
    }
    for (int col = 0; col < size; col++) {
        if (check_threat(board, row, col)) {
            continue;
        }
        board[row][col] = true;
        count += solve(board, num - 1, row + 1);
        board[row][col] = false;
    }
    return count;
}
