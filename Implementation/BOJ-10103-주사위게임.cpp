// BOJ-10103 / 주사위 게임
// devgeon, 2024.06.16, C++17
// https://www.acmicpc.net/problem/10103

#include <iostream>

using namespace std;

int main() {
    int num = 0, cy_score = 100, sd_score = 100;
    cin >> num;

    for (int i = 0, cy_dice = 0, sd_dice = 0; i < num; i++) {
        cin >> cy_dice >> sd_dice;
        if (cy_dice < sd_dice) {
            cy_score -= sd_dice;
        } else if (cy_dice > sd_dice) {
            sd_score -= cy_dice;
        }
    }
    cout << cy_score << '\n' << sd_score << endl;

    return 0;
}
