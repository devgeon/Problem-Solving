// BOJ-01181 / 단어 정렬
// devgeon, 2024.11.17, C++17
// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <set>

using namespace std;

class Compare {
  public:
    bool operator()(const string &a, const string &b) const {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        return a < b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    string word = "";
    set<string, Compare> words;

    for (int i = 0; i < num; i++) {
        cin >> word;
        words.insert(word);
    }

    for (const string &word : words) {
        cout << word << '\n';
    }

    return 0;
}
