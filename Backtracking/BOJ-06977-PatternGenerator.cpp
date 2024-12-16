// BOJ-06977 / Pattern Generator
// devgeon, 2024.12.16, C++17
// https://www.acmicpc.net/problem/6977

#include <iostream>

using namespace std;

void solve(string &pattern, const int max_len, const int max_one,
           const int one = 0) {
    if (pattern.size() == max_len) {
        if (one == max_one) {
            cout << pattern << '\n';
        }
        return;
    }
    if (one < max_one) {
        pattern.push_back('1');
        solve(pattern, max_len, max_one, one + 1);
        pattern.pop_back();
    }
    pattern.push_back('0');
    solve(pattern, max_len, max_one, one);
    pattern.pop_back();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_cases = 0, max_len = 0, max_one = 0;
    string pattern = "";

    cin >> total_cases;
    for (int i = 0; i < total_cases; i++) {
        cin >> max_len >> max_one;
        cout << "The bit patterns are\n";
        solve(pattern, max_len, max_one);
        cout << '\n';
    }

    return 0;
}
