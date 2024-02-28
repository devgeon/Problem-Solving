// BOJ-02239 / 스도쿠
// devgeon, 2024.02.28, C++17
// https://www.acmicpc.net/problem/2239

#include <iostream>
#include <vector>

using namespace std;

bool solve(vector<vector<int>> &board);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> board(9, vector<int>(9, 0));
    for (vector<int> &row : board) {
        for (int &col : row) {
            col = cin.get() - '0';
        }
        cin.get();
    }

    solve(board);

    return 0;
}

bool solve(vector<vector<int>> &board) {
    int row = -1, col = -1;
    bool skip = false;

    // 빈칸 위치 확인
    for (int r = 0; r < 9 && row == -1; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == 0) {
                row = r;
                col = c;
                break;
            }
        }
    }
    // 빈칸이 없을 경우 출력 후 종료
    if (row == -1) {
        for (vector<int> row : board) {
            for (int col : row) {
                cout << col;
            }
            cout << "\n";
        }
        return true;
    }

    // 빈칸에 들어갈 수 있는 수 오름차순으로 시도
    for (int n = 1; n <= 9; n++) {
        skip = false;
        // 행과 열에 겹치는 숫자가 있는지 확인
        for (int i = 0; i < 9; i++) {
            if (n == board[row][i] || n == board[i][col]) {
                skip = true;
                break;
            }
        }
        // 3×3 구역 내에 겹치는 숫자가 있는지 확인
        for (int r = row - row % 3; r < row - row % 3 + 3 && !skip; r++) {
            for (int c = col - col % 3; c < col - col % 3 + 3; c++) {
                if (board[r][c] == n) {
                    skip = true;
                    break;
                }
            }
        }
        // 겹치는 숫자가 있는 경우 다음 숫자 시도
        if (skip) {
            continue;
        }

        // 빈칸 채우기
        board[row][col] = n;

        if (solve(board)) {
            // 모든 칸이 채워졌을 경우 종료
            return true;
        }

        // 올바르지 않은 숫자일 경우 다음 숫자 시도
    }

    // 1~9 모두 들어갈 수 없을 경우 이전 숫자 변경
    board[row][col] = 0;
    return false;
}
