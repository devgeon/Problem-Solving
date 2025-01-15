// BOJ-02063 / 철사 연결
// devgeon, 2025.01.15, C++17
// https://www.acmicpc.net/problem/2063

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int num = 0;
    double sum = 0;
    cin >> num;

    vector<double> radius(num);
    for (double &r : radius) {
        cin >> r;
        sum += r;
    }
    sort(radius.begin(), radius.end());

    for (int i = radius.size() - 1; i >= 0; i--) {
        sum -= radius[i];
        if (sum >= radius[i]) {
            cout << "YES" << '\n';
            return;
        }
        radius.pop_back();
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}
