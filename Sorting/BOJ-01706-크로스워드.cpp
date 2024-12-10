// BOJ-01706 / 크로스워드
// devgeon, 2024.12.10, C++17
// https://www.acmicpc.net/problem/1706

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    string line = "";
    vector<string> puzzle;
    vector<string> words;

    cin >> row >> col;
    puzzle.reserve(row);
    for (int i = 0; i < row; i++) {
        cin >> line;
        puzzle.push_back(line);
    }

    for (int r = 0; r < row; r++) {
        string word = "";
        for (int c = 0; c < col; c++) {
            if (puzzle[r][c] != '#') {
                word.push_back(puzzle[r][c]);
                continue;
            }
            if (word.size() > 1) {
                words.push_back(word);
            }
            word.clear();
        }
        if (word.size() > 1) {
            words.push_back(word);
        }
    }

    for (int c = 0; c < col; c++) {
        string word = "";
        for (int r = 0; r < row; r++) {
            if (puzzle[r][c] != '#') {
                word.push_back(puzzle[r][c]);
                continue;
            }
            if (word.size() > 1) {
                words.push_back(word);
            }
            word.clear();
        }
        if (word.size() > 1) {
            words.push_back(word);
        }
    }

    cout << *min_element(words.begin(), words.end()) << endl;

    return 0;
}
