// BOJ-11048 / 이동하기
// devgeon, 2024.06.29, C++17
// https://www.acmicpc.net/problem/11048

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    cin >> row >> col;

    vector<vector<int>> cache(2, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> cache[i % 2][j];
            cache[i % 2][j] +=
                max(cache[(i + 1) % 2][j], (j > 0 ? cache[i % 2][j - 1] : 0));
        }
    }
    cout << cache[(row - 1) % 2][col - 1] << endl;

    return 0;
}
