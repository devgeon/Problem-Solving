// BOJ-28015 / 영역 색칠
// devgeon, 2024.07.24, C++17
// https://www.acmicpc.net/problem/28015

#include <iostream>

using namespace std;

int main() {
    int row = 0, col = 0, curr = 0, prev = 0, count = 0, answer = 0;
    cin >> row >> col;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> curr;
            if (prev == curr) {
                continue;
            }
            prev = curr;
            if (curr > 0) {
                count++;
                continue;
            }
            answer += count / 2 + 1;
            count = 0;
        }
        if (curr == 0) {
            continue;
        }
        answer += count / 2 + 1;
        count = 0, prev = 0;
    }
    cout << answer << endl;

    return 0;
}
