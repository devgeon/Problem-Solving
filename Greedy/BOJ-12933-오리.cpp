// BOJ-12933 / 오리
// devgeon, 2024.12.12, C++17
// https://www.acmicpc.net/problem/12933

#include <iostream>

using namespace std;

int solve() {
    const string PATTERN = "quack";
    const int LEN = PATTERN.size();

    char ch = 0;
    int idx = 0, prev_idx = 0;
    int count[LEN] = {0};

    while (cin >> ch) {
        idx = PATTERN.find(ch);
        prev_idx = (idx + LEN - 1) % LEN;
        if (count[prev_idx] == 0) {
            if (ch == PATTERN[0]) {
                count[0]++;
                continue;
            }
            return -1;
        }
        count[prev_idx]--;
        count[idx]++;
    }

    for (int i = 0; i < LEN - 1; i++) {
        if (count[i] > 0) {
            return -1;
        }
    }
    return count[LEN - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << endl;
    return 0;
}
