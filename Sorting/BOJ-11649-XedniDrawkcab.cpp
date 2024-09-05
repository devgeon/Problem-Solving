// BOJ-11649 / Xedni Drawkcab
// devgeon, 2024.09.05, C++17
// https://www.acmicpc.net/problem/11649

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<string> words(num, "");
    for (string &word : words) {
        cin >> word;
        reverse(word.begin(), word.end());
    }
    sort(words.begin(), words.end());

    for (string word : words) {
        cout << word << '\n';
    }

    return 0;
}
