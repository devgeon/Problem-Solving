// BOJ-09252 / LCS 2
// devgeon, 2024.05.08, C++17
// https://www.acmicpc.net/problem/9252

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string seq1 = "", seq2 = "", lcs = "";
    cin >> seq1 >> seq2;

    vector<vector<int>> cache(seq1.size() + 1, vector<int>(seq2.size() + 1, 0));

    for (int i = 1; i <= seq1.size(); i++) {
        for (int j = 1; j <= seq2.size(); j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1] + 1;
                continue;
            }
            cache[i][j] = max(cache[i][j - 1], cache[i - 1][j]);
        }
    }

    for (int i = seq1.size(), j = seq2.size(); i > 0 && j > 0;) {
        if (seq1[i - 1] == seq2[j - 1]) {
            lcs += seq1[i - 1];
            i--, j--;
            continue;
        }
        if (cache[i][j - 1] < cache[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }

    cout << cache[seq1.size()][seq2.size()];
    if (cache[seq1.size()][seq2.size()] != 0) {
        reverse(lcs.begin(), lcs.end());
        cout << '\n' << lcs;
    }
    cout << endl;

    return 0;
}
