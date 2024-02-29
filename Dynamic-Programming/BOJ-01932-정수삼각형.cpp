// BOJ-01932 / 정수 삼각형
// devgeon, 2024.02.29, C++17
// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size = 0, answer = 0;
    cin >> size;

    vector<vector<int>> cache(2, vector<int>(size, 0));
    cin >> cache[0][0];

    for (int r = 1; r < size; r++) {
        for (int c = 0; c <= r; c++) {
            cin >> cache[r % 2][c];

            if (c == 0) {
                cache[r % 2][c] += cache[(r + 1) % 2][c];
            } else if (c == r) {
                cache[r % 2][c] += cache[(r + 1) % 2][c - 1];
            } else {
                cache[r % 2][c] +=
                    max(cache[(r + 1) % 2][c], cache[(r + 1) % 2][c - 1]);
            }
        }
    }

    for (int n : cache[(size - 1) % 2]) {
        if (n > answer) {
            answer = n;
        }
    }
    cout << answer << endl;

    return 0;
}
