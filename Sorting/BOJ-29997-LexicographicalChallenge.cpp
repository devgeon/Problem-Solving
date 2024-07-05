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
    for (int i = 0; i < text.size(); i++) {
        split[i % interval].push_back(text[i]);
    }

    for (string &subtext : split) {
        sort(subtext.begin(), subtext.end());
    }
    for (int i = 0; i < text.size(); i++) {
        cout << split[i % interval][i / interval];
    }
    cout << endl;

    return 0;
}
