// BOJ-09465 / 스티커
// devgeon, 2024.10.03, C++17
// https://www.acmicpc.net/problem/9465

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    const int ROW = 2;
    int num = 0, answer = 0;
    cin >> num;

    vector<vector<int>> score(ROW, vector<int>(num, 0));
    vector<vector<int>> cache(ROW, vector<int>(3, 0));
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < num; c++) {
            cin >> score[r][c];
        }
    }

    for (int c = 0; c < num; c++) {
        for (int r = 0; r < ROW; r++) {
            cache[r][c % 3] = max(cache[(r + 1) % ROW][(c + 1) % 3],
                                  cache[(r + 1) % ROW][(c + 2) % 3]) +
                              score[r][c];
        }
    }

    for (int r = 0; r < ROW; r++) {
        answer = max(answer, cache[r][(num - 1) % 3]);
    }
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_cases = 0;
    cin >> num_of_cases;

    while (num_of_cases--) {
        solve();
    }

    return 0;
}
