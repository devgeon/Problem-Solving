// BOJ-29198 / 이번에는 C번이 문자열
// devgeon, 2024.06.02, C++17
// https://www.acmicpc.net/problem/29198

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int num = 0, len = 0, sel = 0;
    cin >> num >> len >> sel;

    vector<vector<int>> count(num, vector<int>(26, 0));
    for (vector<int> &cnt : count) {
        cin >> str;
        for (char ch : str) {
            cnt[ch - 'A']++;
        }
    }
    sort(count.begin(), count.end(), compare);

    for (int col = 0; col < 26; col++) {
        for (int row = 0; row < sel; row++) {
            for (int i = 0, end = count[row][col]; i < end; i++) {
                cout << (char)('A' + col);
            }
        }
    }
    cout << endl;

    return 0;
}

bool compare(const vector<int> &a, const vector<int> &b) {
    for (int i = 0, size = a.size(); i < size; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        return a[i] > b[i];
    }
    return false;
}
