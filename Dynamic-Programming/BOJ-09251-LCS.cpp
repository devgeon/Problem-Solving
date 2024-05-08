// BOJ-09251 / LCS
// devgeon, 2024.05.08, C++17
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string seq1 = "", seq2 = "";
    cin >> seq1 >> seq2;

    vector<vector<int>> cache(2, vector<int>(seq2.size() + 1, 0));

    for (int i = 0; i < seq1.size(); i++) {
        for (int j = 0; j < seq2.size(); j++) {
            if (seq1[i] == seq2[j]) {
                cache[(i + 1) % 2][j + 1] = cache[i % 2][j] + 1;
                continue;
            }
            cache[(i + 1) % 2][j + 1] =
                max(cache[(i + 1) % 2][j], cache[i % 2][j + 1]);
        }
    }

    cout << cache[seq1.size() % 2][seq2.size()] << endl;
    return 0;
}
