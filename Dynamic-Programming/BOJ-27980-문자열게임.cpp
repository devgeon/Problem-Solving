// BOJ-27980 / 문자열 게임
// devgeon, 2024.08.13, C++17
// https://www.acmicpc.net/problem/27980

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int board_size = 0, word_len = 0, answer = 0;
    string board = "", word = "";
    cin >> board_size >> word_len;
    cin >> board >> word;

    vector<vector<int>> cache(2, vector<int>(board_size + 2, 0));

    for (int w = 0; w < word_len; w++) {
        for (int b = 1; b <= board_size; b++) {
            cache[w % 2][b] =
                max(cache[(w + 1) % 2][b - 1], cache[(w + 1) % 2][b + 1]);
            cache[w % 2][b] += (word[w] == board[b - 1] ? 1 : 0);
        }
    }
    answer = *max_element(cache[(word_len - 1) % 2].begin(),
                          cache[(word_len - 1) % 2].end());
    cout << answer << endl;

    return 0;
}
