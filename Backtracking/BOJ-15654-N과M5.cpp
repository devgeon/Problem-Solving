// BOJ-15654 / N과 M (5)
// devgeon, 2024.10.31, C++17
// https://www.acmicpc.net/problem/15654

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &seq, vector<int> &ans, const int len);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, len = 0;
    cin >> num >> len;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    sort(seq.begin(), seq.end());

    vector<int> ans;
    ans.reserve(len);

    solve(seq, ans, len);

    return 0;
}

void solve(vector<int> &seq, vector<int> &ans, const int len) {
    if (ans.size() == len) {
        for (const int n : ans) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] < 0) {
            continue;
        }
        ans.push_back(seq[i]);
        seq[i] = -1;
        solve(seq, ans, len);
        seq[i] = ans.back();
        ans.pop_back();
    }
    return;
}
