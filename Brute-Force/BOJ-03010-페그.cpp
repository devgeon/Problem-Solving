// BOJ-03010 / 페그
// devgeon, 2024.07.30, C++17
// https://www.acmicpc.net/problem/3010

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int answer = 0;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vector<vector<char>> board(9, vector<char>(9, 0));
    for (int r = 1; r <= 7; r++) {
        for (int c = 1; c <= 7; c++) {
            board[r][c] = cin.get();
        }
        cin.get();
    }

    for (int r = 1; r <= 7; r++) {
        for (int c = 1; c <= 7; c++) {
            if (board[r][c] != 'o') {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                if (board[r + dy[i]][c + dx[i]] != 'o') {
                    continue;
                }
                if (board[r + 2 * dy[i]][c + 2 * dx[i]] != '.') {
                    continue;
                }
                answer++;
            }
        }
    }
    cout << answer << endl;

    return 0;
}
