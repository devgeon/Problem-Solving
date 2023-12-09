// BOJ-01157 / 단어 공부
// devgeon, 2023.12.09 C++17
// https://www.acmicpc.net/problem/1157

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c = '\0';
    int cnt[26] = {0};
    int freq_idx = 0;
    bool duplicated = false;

    while (cin >> c && !cin.eof()) {
        if ((c -= 'A') > 25) {
            c -= 32;
        }
        if (cnt[c] + 1 > cnt[freq_idx]) {
            freq_idx = c;
            duplicated = false;
        } else if (cnt[c] + 1 == cnt[freq_idx]) {
            duplicated = true;
        }
        cnt[c]++;
    }

    if (duplicated) {
        cout << '?' << endl;
    } else {
        cout << (char)(freq_idx + 'A') << endl;
    }

    return 0;
}
