// BOJ-25204 / 문자열 정렬
// devgeon, 2024.09.01, C++17
// https://www.acmicpc.net/problem/25204

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compare(char a, char b);

void solve();

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

int compare(char a, char b) {
    if (a == b)
        return 0;
    if (a == '-')
        a = 127;
    if (b == '-')
        b = 127;
    if (abs(a - b) == 32) {
        return a - b;
    }
    if (a > 'Z')
        a -= 32;
    if (b > 'Z')
        b -= 32;
    return a - b;
}

void solve() {
    int num = 0;
    cin >> num;

    vector<string> list(num, "");
    for (string &str : list) {
        cin >> str;
    }

    sort(list.begin(), list.end(), [](string &a, string &b) -> bool {
        int end = min(a.size(), b.size());
        for (int i = 0, result = 0; i < end; i++) {
            result = compare(a[i], b[i]);
            if (result != 0) {
                return result < 0;
            }
        }
        return (a.size() < b.size());
    });

    for (string str : list) {
        cout << str << '\n';
    }
}
