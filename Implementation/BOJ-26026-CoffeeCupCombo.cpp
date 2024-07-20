// BOJ-26026 / Coffee Cup Combo
// devgeon, 2024.07.20, C++17
// https://www.acmicpc.net/problem/26026

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char machine = 0;
    int num = 0, coffee = 0, answer = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> machine;
        if (machine == '0' && coffee == 0) {
            continue;
        }
        if (machine == '1') {
            coffee = 2;
        } else {
            coffee--;
        }
        answer++;
    }
    cout << answer << endl;

    return 0;
}
