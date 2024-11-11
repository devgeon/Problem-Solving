// BOJ-30506 / 가위 가위 가위
// devgeon, 2024.11.11, C++17
// https://www.acmicpc.net/problem/30506

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int LEN = 100, GAMES = 100;
    int win = 0, prev_win = 0;
    string player(LEN, '2');

    cin >> prev_win;
    for (int i = 0; i < GAMES; i++) {
        player[i] = '0';
        cout << "? " << player << endl;
        cin >> win;
        if (win - prev_win < 0) {
            player[i] = '2';
            win++;
        } else if (win == prev_win) {
            player[i] = '5';
            win++;
        }
        prev_win = win;
    }

    cout << "! ";
    for (char c : player) {
        cout << (c == '0' ? '2' : (c == '5' ? '0' : '5'));
    }
    cout << endl;

    return 0;
}
