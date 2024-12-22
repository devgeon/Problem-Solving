// BOJ-03982 / Soccer Bets
// devgeon, 2024.12.22, C++17
// https://www.acmicpc.net/problem/3982

#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
    int score1 = 0, score2 = 0;
    string team1 = "", team2 = "";
    unordered_map<string, int> count;

    for (int i = 0; i < 16; i++) {
        cin >> team1 >> team2 >> score1 >> score2;
        string &winner = score1 > score2 ? team1 : team2;
        if (++count[winner] == 4) {
            cout << winner << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_cases = 0;
    cin >> total_cases;

    for (int i = 0; i < total_cases; i++) {
        solve();
    }

    return 0;
}
