// BOJ-09663 / N-Queen
// devgeon, 2024.10.15, C++17
// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>

using namespace std;

bool check_threat(vector<int> &queen_index, int row, int col);

int solve(vector<int> &queen_index, int row = 0);

int main() {
    int size = 0;
    cin >> size;

    vector<int> queen_index(size, -1);
    cout << solve(queen_index) << endl;

    return 0;
}

bool check_threat(vector<int> &queen_index, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queen_index[i] == col ||
            abs(queen_index[i] - col) == abs(i - row)) {
            return true;
        }
    }
    return false;
}

int solve(vector<int> &queen_index, int row) {
    int size = queen_index.size(), count = 0;
    if (row == size) {
        return 1;
    }
    for (int col = 0; col < size; col++) {
        if (check_threat(queen_index, row, col)) {
            continue;
        }
        queen_index[row] = col;
        count += solve(queen_index, row + 1);
        queen_index[row] = -1;
    }
    return count;
}
