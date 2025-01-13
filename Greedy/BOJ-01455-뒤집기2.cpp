// BOJ-01455 / 뒤집기 II
// devgeon, 2025.01.13, C++17
// https://www.acmicpc.net/problem/1455

#include <bitset>
#include <iostream>

#define MAX_ROW 100
#define MAX_COL 100

using namespace std;

inline void flip(bitset<MAX_ROW * MAX_COL> &coins, const int col_size,
                 const int row, const int col) {
    for (int r = row; r >= 0; r--) {
        for (int c = col; c >= 0; c--) {
            coins.flip(r * col_size + c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0, count = 0;
    cin >> row >> col;

    bitset<MAX_ROW * MAX_COL> coins;
    for (int r = 0; r < row; r++) {
        cin.ignore();
        for (int c = 0; c < col; c++) {
            if (cin.get() == '1') {
                coins.set(r * col + c);
            }
        }
    }

    for (int r = row - 1; r >= 0; r--) {
        for (int c = col - 1; c >= 0; c--) {
            if (coins[r * col + c]) {
                flip(coins, col, r, c);
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}
