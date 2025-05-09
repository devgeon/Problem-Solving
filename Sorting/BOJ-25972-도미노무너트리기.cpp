// BOJ-25972 / 도미노 무너트리기
// devgeon, 2025.04.17, C++17
// https://www.acmicpc.net/problem/25972

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, answer = 1;
    vector<pair<int, int>> dominoes;

    cin >> num;
    dominoes.reserve(num);
    for (int i = 0; i < num; i++) {
        int pos = 0, len = 0;
        cin >> pos >> len;
        dominoes.emplace_back(pos, len);
    }

    sort(dominoes.begin(), dominoes.end());

    for (int i = 1; i < num; i++) {
        if (dominoes[i - 1].first + dominoes[i - 1].second <
            dominoes[i].first) {
            answer++;
        }
    }
    cout << answer << endl;

    return 0;
}
