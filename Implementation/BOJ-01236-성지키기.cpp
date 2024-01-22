// BOJ-01236 / 성 지키기
// devgeon, 2024.01.22, C++17
// https://www.acmicpc.net/problem/1236

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    cin >> row >> col;
    vector<bool> empty_row(row, true);
    vector<bool> empty_col(col, true);
    int count_empty_row = 0, count_empty_col = 0;

    for (int r = 0; r < row; r++) {
        cin.get();
        for (int c = 0; c < col; c++) {
            if (cin.get() == 'X') {
                empty_row[r] = false;
                empty_col[c] = false;
            }
        }
    }
    for (bool b : empty_row) {
        if (b) {
            count_empty_row++;
        }
    }
    for (bool b : empty_col) {
        if (b) {
            count_empty_col++;
        }
    }

    cout << max(count_empty_row, count_empty_col) << endl;
    return 0;
}
