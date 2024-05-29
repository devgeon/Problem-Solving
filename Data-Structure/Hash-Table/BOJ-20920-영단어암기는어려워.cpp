// BOJ-20920 / 영단어 암기는 괴로워
// devgeon, 2024.05.29, C++17
// https://www.acmicpc.net/problem/20920

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Compare {
  private:
    unordered_map<string, int> *counts;

  public:
    Compare(unordered_map<string, int> *counts) { this->counts = counts; }

    bool operator()(const string &a, const string &b) {
        if ((*counts)[a] != (*counts)[b]) {
            return (*counts)[a] > (*counts)[b];
        }
        if (a.length() != b.length()) {
            return a.length() > b.length();
        }
        return a < b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, min_len = 0;
    string word = "";
    cin >> num >> min_len;

    vector<string> word_list;
    word_list.reserve(num);
    unordered_map<string, int> counts;
    for (int i = 0; i < num; i++) {
        cin >> word;
        if (word.size() < min_len) {
            continue;
        }
        if (counts[word] == 0) {
            word_list.push_back(word);
        }
        counts[word]++;
    }

    Compare compare(&counts);
    sort(word_list.begin(), word_list.end(), compare);

    for (string word : word_list) {
        cout << word << '\n';
    }

    return 0;
}
