// BOJ-05637 / 가장 긴 단어
// devgeon, 2024.11.25, C++17
// https://www.acmicpc.net/problem/5637

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ch = 0;
    string word = "", max_word = "";

    while ((ch = cin.get()) != EOF) {
        if (isalpha(ch) || ch == '-') {
            word.push_back(tolower(ch));
            continue;
        }
        if (word.size() > max_word.size()) {
            max_word.swap(word);
        }
        word.clear();
    }
    cout << max_word << endl;

    return 0;
}
