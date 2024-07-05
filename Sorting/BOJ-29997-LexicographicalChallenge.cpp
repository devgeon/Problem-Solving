// BOJ-29997 / Lexicographical Challenge
// devgeon, 2024.07.05, C++17
// https://www.acmicpc.net/problem/29997

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int interval = 0;
    string text = "";
    cin >> text >> interval;

    vector<string> split(interval, "");
    for (auto c = text.begin(); c != text.end();) {
        for (string &subtext : split) {
            if (c == text.end()) {
                break;
            }
            subtext.push_back(*c);
            c++;
        }
    }

    for (string &subtext : split) {
        sort(subtext.begin(), subtext.end());
    }
    for (int i = 0, end = (text.size() - 1) / interval + 1; i < end; i++) {
        for (string &subtext : split) {
            if (i == subtext.size()) {
                break;
            }
            cout << subtext[i];
        }
    }
    cout << endl;

    return 0;
}
