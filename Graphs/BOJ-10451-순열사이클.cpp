// BOJ-10451 / 순열 사이클
// devgeon, 2024.08.04, C++17
// https://www.acmicpc.net/problem/10451

#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
    int cases = 0;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, count = 0;
    cin >> num;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }

    for (int i = 0, idx = 0; i < num; i++) {
        if (seq[i] < 0) {
            continue;
        }
        idx = i;
        do {
            seq[idx] *= -1;
            idx = -seq[idx] - 1;
        } while (i != idx);
        count++;
    }
    cout << count << '\n';
}
