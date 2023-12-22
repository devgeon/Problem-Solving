// BOJ-23083 / 꿀벌 승연이
// devgeon, 2023.12.22, C++17
// https://www.acmicpc.net/problem/23083

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int DIVISOR = 1000000007;
    int row = 0, col = 0, total_holes = 0;
    cin >> row >> col >> total_holes;
    int tmp_r = 0, tmp_c = 0;
    vector<vector<int>> honeycomb(row, vector<int>(col, -1));
    honeycomb[0][0] = 1;
    while (total_holes) {
        cin >> tmp_r >> tmp_c;
        honeycomb[tmp_r - 1][tmp_c - 1] = 0;
        total_holes--;
    }

    for (tmp_c = 0; tmp_c < col; tmp_c++) {
        for (tmp_r = 0; tmp_r < row; tmp_r++) {
            if (honeycomb[tmp_r][tmp_c] != -1) {
                continue;
            }
            if (tmp_r > 0) {
                honeycomb[tmp_r][tmp_c] += honeycomb[tmp_r - 1][tmp_c];
                honeycomb[tmp_r][tmp_c] %= DIVISOR;
            }
            if (tmp_c > 0) {
                honeycomb[tmp_r][tmp_c] += honeycomb[tmp_r][tmp_c - 1];
                honeycomb[tmp_r][tmp_c] %= DIVISOR;
                if (tmp_c & 1) {
                    if (tmp_r < row - 1) {
                        honeycomb[tmp_r][tmp_c] +=
                            honeycomb[tmp_r + 1][tmp_c - 1];
                        honeycomb[tmp_r][tmp_c] %= DIVISOR;
                    }
                } else if (tmp_r > 0) {
                    honeycomb[tmp_r][tmp_c] += honeycomb[tmp_r - 1][tmp_c - 1];
                    honeycomb[tmp_r][tmp_c] %= DIVISOR;
                }
            }
            honeycomb[tmp_r][tmp_c]++;
        }
    }

    cout << honeycomb[row - 1][col - 1] << endl;
    return 0;
}
