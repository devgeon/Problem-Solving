// BOJ-10798 / 세로읽기
// devgeon, 2023.12.11, C++17
// https://www.acmicpc.net/problem/10798

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    char input = 0;
    char board[5][15] = {0};

    while (!cin.eof()) {
        input = cin.get();
        if (input != '\n') {
            board[row][col] = input;
            col++;
        } else {
            row++;
            col = 0;
        }
    }

    for (col = 0; col < 15; col++) {
        for (row = 0; row < 5; row++) {
            if (board[row][col] != 0) {
                cout << board[row][col];
            }
        }
    }

    return 0;
}
