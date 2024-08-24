// BOJ-13986 / Gravity
// devgeon, 2024.08.24, C++17
// https://www.acmicpc.net/problem/13986

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0, apple = 0;
    cin >> row >> col;

    vector<vector<char>> world(row + 1, vector<char>(col, '#'));
    for (int r = 0; r < row; r++) {
        cin.get();
        for (int c = 0; c < col; c++) {
            world[r][c] = cin.get();
        }
    }

    for (int c = 0; c < col; c++) {
        for (int r = 0; r <= row; r++) {
            if (world[r][c] == 'o') {
                apple++;
                world[r][c] = '.';
                continue;
            }
            if (world[r][c] == '.') {
                continue;
            }
            while (apple) {
                world[r - apple][c] = 'o';
                apple--;
            }
        }
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << world[r][c];
        }
        cout << '\n';
    }

    return 0;
}
